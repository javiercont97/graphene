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
	const float tapThresholdDistance = 10.0f;						  // threshold for movement
	const auto tapThresholdTime = std::chrono::milliseconds(200);	  // threshold for tap duration
	const auto longPressThreshold = std::chrono::milliseconds(2000);  // threshold for long press

	// To store matched previous points
	std::vector<bool> matchedPrevPoints(prevTouchPoints.size(), false);
	std::vector<bool> matchedCurrentPoints(points.size(), false);

	// Iterate through current touch points
	for (size_t i = 0; i < points.size(); ++i) {
		Point &currentPoint = points[i];
		int32_t minDistance = std::numeric_limits<int32_t>::max();
		int closestPrevIndex = -1;

		// Find the closest previous point
		for (size_t j = 0; j < prevTouchPoints.size(); ++j) {
			if (!matchedPrevPoints[j]) {
				int32_t dist = currentPoint.distanceTo(prevTouchPoints[j].position);
				if (dist < minDistance) {
					minDistance = dist;
					closestPrevIndex = j;
				}
			}
		}

		// If a close previous point is found, match it
		if (closestPrevIndex != -1 && minDistance < tapThresholdDistance) {
			matchedPrevPoints[closestPrevIndex] = true;
			matchedCurrentPoints[i] = true;

			TouchEvent &prevPoint = prevTouchPoints[closestPrevIndex];
			auto duration = now - prevPoint.timestamp;

			if (minDistance > tapThresholdDistance) {
				events.push_back({Graphene::TouchEventType::MOVE, currentPoint, now});
			} else if (duration > longPressThreshold) {
				events.push_back({Graphene::TouchEventType::LONG_PRESS, currentPoint, now});
			}
		} else {
			// New touch point detected
			events.push_back({Graphene::TouchEventType::PRESS, currentPoint, now});
		}
	}

	// Check for released points (not present in current points but present in previous)
	// Handle unmatched previous points (released points)
	for (size_t j = 0; j < prevTouchPoints.size(); ++j) {
		if (!matchedPrevPoints[j]) {
			TouchEvent &prevPoint = prevTouchPoints[j];
			auto duration = now - prevPoint.timestamp;

			if (duration <= tapThresholdTime) {
				static auto lastTapTime = std::chrono::steady_clock::time_point::min();
				auto timeSinceLastTap = now - lastTapTime;

				if (timeSinceLastTap <= tapThresholdTime) {
					events.push_back({Graphene::TouchEventType::DOUBLE_TAP, prevPoint.position, now});
				} else {
					events.push_back({Graphene::TouchEventType::TAP, prevPoint.position, now});
					lastTapTime = now;
				}
			} else {
				events.push_back({Graphene::TouchEventType::RELEASE, prevPoint.position, now});
			}
		}
	}

	return events;
}
