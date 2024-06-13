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
	this->prevTouchPoints.clear();	// Clear the old state
	for (const auto &event : events) {
		// Only keep relevant events that indicate ongoing touch points
		if (event.type == Graphene::TouchEventType::MOVE || event.type == Graphene::TouchEventType::PRESS
			|| event.type == Graphene::TouchEventType::LONG_PRESS) {
			this->prevTouchPoints.push_back(event);
		}
	}

	// draw
	this->rootContainer->draw(*this->canvas);
}

std::vector<Graphene::TouchEvent> Graphene::GrapheneApp::processTouchEvents(std::vector<Point> points) {
	std::vector<TouchEvent> events;

	auto now = std::chrono::steady_clock::now();
	const float tapThresholdDistance = 10.0f;						 // threshold for movement
	const auto tapThresholdTime = std::chrono::milliseconds(100);	 // threshold for tap duration
	const auto longPressThreshold = std::chrono::milliseconds(500);	 // threshold for long press

	// Process touch points, there must be only one entry in points vector
	if (points.size() == 1) {
		auto point = points[0];
		auto event = TouchEvent();
		event.position = point;
		event.timestamp = now;

		// Check if this is a new touch point
		bool isNewTouchPoint = true;
		for (const auto &prevEvent : this->prevTouchPoints) {
			if (prevEvent.position.distanceTo(point) < tapThresholdDistance) {
				isNewTouchPoint = false;
				break;
			}
		}

		if (isNewTouchPoint) {
			event.type = TouchEventType::PRESS;
			events.push_back(event);
		} else {
			// Check if this is a long press
			bool isLongPress = true;
			for (const auto &prevEvent : this->prevTouchPoints) {
				if (prevEvent.position.distanceTo(point) < tapThresholdDistance) {
					auto duration = now - prevEvent.timestamp;
					if (duration < longPressThreshold) {
						isLongPress = false;
						break;
					}
				}
			}

			if (isLongPress) {
				event.type = TouchEventType::LONG_PRESS;
				events.push_back(event);
			} else {
				// Check if this is a move
				bool isMove = true;
				for (const auto &prevEvent : this->prevTouchPoints) {
					if (prevEvent.position.distanceTo(point) < tapThresholdDistance) {
						isMove = false;
						break;
					}
				}

				if (isMove) {
					event.type = TouchEventType::MOVE;
					events.push_back(event);
				}
			}
		}
	}

	return events;
}
