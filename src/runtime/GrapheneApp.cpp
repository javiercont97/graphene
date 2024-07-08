#include "GrapheneApp.h"

Graphene::GrapheneApp::GrapheneApp(AbstractCanvas *canvas, AbstractTouchInput *touchInput, IContainer *rootContainer)
	: canvas(canvas), touchInput(touchInput), rootContainer(rootContainer) {
	this->hasPrevTouchEvent = false;
	this->prevTouchEvent = {
		.type = TouchEventType::RELEASE, .position = Point(0, 0), .timestamp = std::chrono::steady_clock::now()};
}

Graphene::GrapheneApp::~GrapheneApp() {
}

void Graphene::GrapheneApp::eventLoop() {
	// get input
	std::vector<Graphene::Point> points = this->touchInput->getTouchPoints();

	// update state. Process and dispatch events
	std::vector<Graphene::TouchEvent> events = this->processTouchEvents(points);
	for (auto event : events) {
		this->rootContainer->onTouchEvent(&event);
	}

	// draw
	if (this->rootContainer->needsRedraw()) {
		this->rootContainer->forceRedraw();
	}
	this->rootContainer->draw(*this->canvas);
}

std::vector<Graphene::TouchEvent> Graphene::GrapheneApp::processTouchEvents(std::vector<Point> points) {
	std::vector<TouchEvent> events = {};
	auto now = std::chrono::steady_clock::now();
	const int32_t moveThresholdDistance = 50;

	if (!points.empty()) {
		auto point = points[0];

		if (this->hasPrevTouchEvent) {
			auto prevEvent = this->prevTouchEvent;
			auto prevPoint = prevEvent.position;

			// Check if the point has moved
			if (point.distanceTo(prevPoint) > moveThresholdDistance) {
				TouchEvent event = {.type = TouchEventType::MOVE, .position = point, .timestamp = now};

				events.push_back(event);
				this->prevTouchEvent = event;
			}
		} else {
			TouchEvent event = {.type = TouchEventType::PRESS, .position = point, .timestamp = now};

			events.push_back(event);
			this->prevTouchEvent = event;
		}

		this->hasPrevTouchEvent = true;
	} else {
		if (this->prevTouchEvent.type == TouchEventType::PRESS) {
			TouchEvent event = {
				.type = TouchEventType::TAP, .position = this->prevTouchEvent.position, .timestamp = now};

			events.push_back(event);
		}

		if (this->hasPrevTouchEvent) {
			TouchEvent event = {
				.type = TouchEventType::RELEASE, .position = this->prevTouchEvent.position, .timestamp = now};

			events.push_back(event);
			this->prevTouchEvent = event;
		}

		this->hasPrevTouchEvent = false;
	}

	return events;
}
