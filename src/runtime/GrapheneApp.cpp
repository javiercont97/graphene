#include "GrapheneApp.h"

Graphene::GrapheneApp::GrapheneApp(AbstractCanvas *canvas, AbstractTouchInput *touchInput, IContainer *rootContainer)
	: canvas(canvas), touchInput(touchInput), rootContainer(rootContainer) {
}

Graphene::GrapheneApp::~GrapheneApp() {
	delete this->canvas;
	delete this->touchInput;
	delete this->rootContainer;
}

void Graphene::GrapheneApp::eventLoop() {
	// get input
	std::vector<Graphene::Point> points = this->touchInput->getTouchPoints();

	// update state. Process and dispatch events
	std::vector<Graphene::TouchEvent> events = this->processTouchEvents(points);
	for (auto event : events) {
		this->rootContainer->onTouchEvent(&event);
	}

	// Update previous touch points state
	this->prevTouchEvents.clear();	// Clear the old state
	for (const auto &event : events) {
		// Only keep relevant events that indicate ongoing touch points
		if (event.type == Graphene::TouchEventType::MOVE || event.type == Graphene::TouchEventType::PRESS
			|| event.type == Graphene::TouchEventType::LONG_PRESS) {
			this->prevTouchEvents.push_back(event);
		}
	}

	// draw
	this->rootContainer->draw(*this->canvas);
}

std::vector<Graphene::TouchEvent> Graphene::GrapheneApp::processTouchEvents(std::vector<Point> points) {
	std::vector<TouchEvent> events;
	auto now = std::chrono::steady_clock::now();

	// Thresholds
	const int32_t moveThresholdDistance = 50;						 // threshold for movement
	const auto longPressThreshold = std::chrono::milliseconds(500);	 // threshold for long press, this might also work
																	 // as resolution for long press
	const auto tapThresholdTime = std::chrono::milliseconds(100);	 // threshold for tap duration

	// Process touch points if there is a touch point
	if (!points.empty()) {
		auto point = points[0];

		if (this->prevTouchEvents.empty()) {
			events.push_back({TouchEventType::PRESS, point, now});
		}

		// Check if there is a previous touch point with PRESS or LONG_PRESS event
		for (const auto &prevEvent : this->prevTouchEvents) {
			if (prevEvent.type == TouchEventType::PRESS || prevEvent.type == TouchEventType::LONG_PRESS) {
				// Check if the point has moved
				if (point.distanceTo(prevEvent.position) > moveThresholdDistance) {
					events.push_back({TouchEventType::MOVE, point, now});
				} else {
					// Check if the point has been pressed for a long time
					if (now - prevEvent.timestamp > longPressThreshold) {
						events.push_back({TouchEventType::LONG_PRESS, point, now});
					}
				}
			}
		}
	} else {
		// Check if there is a previous touch point with PRESS or LONG_PRESS event
		for (const auto &prevEvent : this->prevTouchEvents) {
			if (prevEvent.type == TouchEventType::PRESS || prevEvent.type == TouchEventType::LONG_PRESS) {
				events.push_back({TouchEventType::RELEASE, prevEvent.position, now});
			}

			if (prevEvent.type == TouchEventType::PRESS) {
				// Check if the point has been pressed for a short time
				if (now - prevEvent.timestamp < tapThresholdTime) {
					events.push_back({TouchEventType::TAP, prevEvent.position, now});
				}
			}
		}
	}

	return events;
}
