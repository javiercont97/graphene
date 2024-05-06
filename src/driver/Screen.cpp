#include "Screen.h"

Graphene::Screen::Screen(uint32_t width, uint32_t height) {
	this->width = width;
	this->height = height;

	this->currentFrame = 0;
	this->frames = {Graphene::FrameBuffer(width, height),
					Graphene::FrameBuffer(width, height)};
}

Graphene::Screen::~Screen() {
	// for (auto frame : this->frames) {
	// 	delete frame;
	// }
}

void Graphene::Screen::drawPixel(Graphene::Point point) {
	this->frames[this->currentFrame].setPixel(point, Graphene::WHITE);
}

void Graphene::Screen::drawLine(Graphene::Point start, Graphene::Point end) {
	// Bresenham's line algorithm
	int32_t dx = std::abs((float)end.getX() - (float)start.getX());
	int32_t dy = std::abs((float)end.getY() - (float)start.getY());
	int32_t sx = start.getX() < end.getX() ? 1 : -1;
	int32_t sy = start.getY() < end.getY() ? 1 : -1;
	int32_t err = dx - dy;

	while (true) {
		this->drawPixel(start);

		if (start.getX() == end.getX() && start.getY() == end.getY()) {
			break;
		}

		int32_t e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			start.setX(start.getX() + sx);
		}
		if (e2 < dx) {
			err += dx;
			start.setY(start.getY() + sy);
		}
	}
}

void Graphene::Screen::drawRectangle(Graphene::Point position,
									 uint32_t width,
									 uint32_t height) {
	Graphene::Point p1 = position;
	Graphene::Point p2 = {position.getX() + width, position.getY()};
	Graphene::Point p3 = {position.getX() + width, position.getY() + height};
	Graphene::Point p4 = {position.getX(), position.getY() + height};

	this->drawLine(p1, p2);
	this->drawLine(p2, p3);
	this->drawLine(p3, p4);
	this->drawLine(p4, p1);
}

void Graphene::Screen::fillRectangle(Graphene::Point position,
									 uint32_t width,
									 uint32_t height) {
	for (uint32_t y = position.getY(); y < position.getY() + height; y++) {
		for (uint32_t x = position.getX(); x < position.getX() + width; x++) {
			this->drawPixel({x, y});
		}
	}
}

void Graphene::Screen::drawCircle(Graphene::Point center, uint32_t radius) {
	int32_t x = radius;
	int32_t y = 0;
	int32_t err = 0;

	while (x >= y) {
		this->drawPixel({center.getX() + x, center.getY() + y});
		this->drawPixel({center.getX() + y, center.getY() + x});
		this->drawPixel({center.getX() - y, center.getY() + x});
		this->drawPixel({center.getX() - x, center.getY() + y});
		this->drawPixel({center.getX() - x, center.getY() - y});
		this->drawPixel({center.getX() - y, center.getY() - x});
		this->drawPixel({center.getX() + y, center.getY() - x});
		this->drawPixel({center.getX() + x, center.getY() - y});

		if (err <= 0) {
			y += 1;
			err += 2 * y + 1;
		}

		if (err > 0) {
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}

void Graphene::Screen::fillCircle(Graphene::Point center, uint32_t radius) {
	int32_t x = radius;
	int32_t y = 0;
	int32_t err = 0;

	while (x >= y) {
		for (int32_t i = center.getX() - x; i <= center.getX() + x; i++) {
			this->drawPixel({i, center.getY() + y});
			this->drawPixel({i, center.getY() - y});
		}

		for (int32_t i = center.getX() - y; i <= center.getX() + y; i++) {
			this->drawPixel({i, center.getY() + x});
			this->drawPixel({i, center.getY() - x});
		}

		if (err <= 0) {
			y += 1;
			err += 2 * y + 1;
		}

		if (err > 0) {
			x -= 1;
			err -= 2 * x + 1;
		}
	}
}

void Graphene::Screen::drawPolygon(std::vector<Graphene::Point> points) {
	for (size_t i = 0; i < points.size() - 1; i++) {
		this->drawLine(points[i], points[i + 1]);
	}
	this->drawLine(points[points.size() - 1], points[0]);
}

void Graphene::Screen::fillPolygon(std::vector<Graphene::Point> points) {
	// Find the bounding box of the polygon
	int32_t minX = points[0].getX();
	int32_t minY = points[0].getY();
	int32_t maxX = points[0].getX();
	int32_t maxY = points[0].getY();

	for (size_t i = 1; i < points.size(); i++) {
		if (points[i].getX() < minX) {
			minX = points[i].getX();
		}
		if (points[i].getY() < minY) {
			minY = points[i].getY();
		}
		if (points[i].getX() > maxX) {
			maxX = points[i].getX();
		}
		if (points[i].getY() > maxY) {
			maxY = points[i].getY();
		}
	}

	// Check if a point is inside the polygon
	auto isInside = [&points](Graphene::Point point) {
		bool isInside = false;
		for (size_t i = 0, j = points.size() - 1; i < points.size(); j = i++) {
			if (((points[i].getY() > point.getY()) !=
				 (points[j].getY() > point.getY())) &&
				(point.getX() < (points[j].getX() - points[i].getX()) *
										(point.getY() - points[i].getY()) /
										(points[j].getY() - points[i].getY()) +
									points[i].getX())) {
				isInside = !isInside;
			}
		}
		return isInside;
	};

	for (int32_t y = minY; y <= maxY; y++) {
		for (int32_t x = minX; x <= maxX; x++) {
			if (isInside({x, y})) {
				this->drawPixel({x, y});
			}
		}
	}
}

void Graphene::Screen::drawString(Graphene::Point position, String text) {
	// TODO: Implement this function
}

void Graphene::Screen::clearScreen(Color color) {
	this->frames[this->currentFrame].clear(color);
}

void Graphene::Screen::swapBuffers() {
	this->currentFrame = (this->currentFrame + 1) % 2;
}

Graphene::FrameBuffer Graphene::Screen::getCurrentFrame() {
	return this->frames[this->currentFrame];
}

void Graphene::Screen::setForegroundColor(Color color) {
	this->foregroundColor = color;
}

void Graphene::Screen::setBackgroundColor(Color color) {
	this->backgroundColor = color;
}

Graphene::Color Graphene::Screen::getForegroundColor() const {
	return this->foregroundColor;
}

Graphene::Color Graphene::Screen::getBackgroundColor() const {
	return this->backgroundColor;
}

uint32_t Graphene::Screen::getWidth() const {
	return this->width;
}

uint32_t Graphene::Screen::getHeight() const {
	return this->height;
}
