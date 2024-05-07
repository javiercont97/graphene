#include "VirtualScreenDriver.h"

Graphene::VirtualScreenDriver::VirtualScreenDriver() {
	this->width = 16;
	this->height = 9;

	// Initialize the frame buffers
	// Start drawing on the first frame buffer
	this->currentFrame = 0;
	this->frames = {Graphene::FrameBuffer(width, height), Graphene::FrameBuffer(width, height)};

	// Set the default colors
	this->foregroundColor = Graphene::WHITE;
	this->backgroundColor = Graphene::BLACK;

	// Clear the frame buffers
	this->frames[0].clear(this->backgroundColor);
	this->frames[1].clear(this->backgroundColor);
}

Graphene::VirtualScreenDriver::VirtualScreenDriver(uint32_t width, uint32_t height) {
	this->width = width;
	this->height = height;

	// Initialize the frame buffers
	// Start drawing on the first frame buffer
	this->currentFrame = 0;
	this->frames = {Graphene::FrameBuffer(width, height), Graphene::FrameBuffer(width, height)};

	// Set the default colors
	this->foregroundColor = Graphene::WHITE;
	this->backgroundColor = Graphene::BLACK;

	// Clear the frame buffers
	this->frames[0].clear(this->backgroundColor);
	this->frames[1].clear(this->backgroundColor);
}

Graphene::VirtualScreenDriver::~VirtualScreenDriver() {
}

void Graphene::VirtualScreenDriver::drawPixel(Graphene::Point point) {
	// if out of bounds, return
	if (point.getX() < 0 || point.getX() >= this->width || point.getY() < 0 || point.getY() >= this->height) {
		return;
	}

	this->frames[this->currentFrame].setPixel(point, this->foregroundColor);
}

void Graphene::VirtualScreenDriver::drawLine(Graphene::Point start, Graphene::Point end) {
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

void Graphene::VirtualScreenDriver::drawRectangle(Graphene::Point position, uint32_t width, uint32_t height) {
	Graphene::Point p1 = position;
	// width - 1 and height - 1 to make sure the rectangle is drawn correctly
	// subtraction si done to take into account the 0 based indexing
	Graphene::Point p2 = {position.getX() + width - 1, position.getY()};
	Graphene::Point p3 = {position.getX() + width - 1, position.getY() + height - 1};
	Graphene::Point p4 = {position.getX(), position.getY() + height - 1};

	this->drawLine(p1, p2);
	this->drawLine(p2, p3);
	this->drawLine(p3, p4);
	this->drawLine(p4, p1);
}

void Graphene::VirtualScreenDriver::fillRectangle(Graphene::Point position, uint32_t width, uint32_t height) {
	for (uint32_t y = position.getY(); y < position.getY() + height; y++) {
		for (uint32_t x = position.getX(); x < position.getX() + width; x++) {
			this->drawPixel({x, y});
		}
	}
}

void Graphene::VirtualScreenDriver::drawCircle(Graphene::Point center, uint32_t radius) {
	// midpoint circle algorithm

	// Given a function f(x, y) = x^2 + y^2 - r^2
	// f(x, y) > 0 means the point is outside the circle
	// f(x, y) < 0 means the point is inside the circle
	// f(x, y) = 0 means the point is on the circle
	auto fCircle = [=](int32_t x, int32_t y, int32_t r) { return x * x + y * y - r * r; };

	radius = radius - 1;  // to take into account 0 based indexing

	// P0 = (0, r)
	int32_t x = 0;
	int32_t y = radius;

	// Initial decision parameter of region 1
	int32_t d = 5 / 4 - radius;

	// loop till x>=y
	for (int32_t k = 0; x >= y; k++) {
		// Print the circle points
		// (x, y) is the current point
		// Print the mirror image of the current point
		// in the 4 quadrants
		this->drawPixel({center.getX() + x, center.getY() + y});
		this->drawPixel({center.getX() - x, center.getY() + y});
		this->drawPixel({center.getX() + x, center.getY() - y});
		this->drawPixel({center.getX() - x, center.getY() - y});
		this->drawPixel({center.getX() + y, center.getY() + x});
		this->drawPixel({center.getX() - y, center.getY() + x});
		this->drawPixel({center.getX() + y, center.getY() - x});
		this->drawPixel({center.getX() - y, center.getY() - x});

		// Depending on the value of d, we can either
		// add x or add x and y
		if (d < 0) {
			d += 2 * x + 3;
		} else {
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
	}
}

void Graphene::VirtualScreenDriver::fillCircle(Graphene::Point center, uint32_t radius) {
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

void Graphene::VirtualScreenDriver::drawPolygon(std::vector<Graphene::Point> points) {
	for (size_t i = 0; i < points.size() - 1; i++) {
		this->drawLine(points[i], points[i + 1]);
	}
	this->drawLine(points[points.size() - 1], points[0]);
}

void Graphene::VirtualScreenDriver::fillPolygon(std::vector<Graphene::Point> points) {
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
			if (((points[i].getY() > point.getY()) != (points[j].getY() > point.getY())) &&
				(point.getX() < (points[j].getX() - points[i].getX()) * (point.getY() - points[i].getY()) /
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

void Graphene::VirtualScreenDriver::drawString(Graphene::Point position, String text) {
	// TODO: Implement this function, requires the Font class

	// // Draw each character in the string
	// for (size_t i = 0; i < text.length(); i++) {
	// 	// Get the character
	// 	char c = text[i];

	// 	// Get the character bitmap
	// 	const uint8_t *bitmap = Graphene::Font::getCharacterBitmap(c);

	// 	// Draw the character bitmap
	// 	for (uint32_t y = 0; y < Graphene::Font::CHARACTER_HEIGHT; y++) {
	// 		for (uint32_t x = 0; x < Graphene::Font::CHARACTER_WIDTH; x++) {
	// 			if (bitmap[y] & (1 << (Graphene::Font::CHARACTER_WIDTH - x -
	// 1))) { 				this->drawPixel({position.getX() + x,
	// position.getY()
	// + y});
	// 			}
	// 		}
	// 	}

	// 	// Move the position to the next character
	// 	position.setX(position.getX() + Graphene::Font::CHARACTER_WIDTH);
	// }
}

void Graphene::VirtualScreenDriver::clearScreen(Color color) {
	this->frames[this->currentFrame].clear(color);
}

void Graphene::VirtualScreenDriver::swapBuffers() {
	// Swap the frame buffers
	// start drawing on the other buffer
	// if currentFrame is 0, set it to 1
	// if currentFrame is 1, set it to 0

	// get the current frame buffer method should return the frame buffer that
	// is not being drawn on
	this->currentFrame = (this->currentFrame + 1) % 2;
}

Graphene::FrameBuffer Graphene::VirtualScreenDriver::getCurrentFrame() {
	// get the current frame buffer method should return the frame buffer that
	// is not being drawn on assume that the current frame buffer is full and
	// ready to be displayed
	return this->frames[(this->currentFrame + 1) % 2];
}

void Graphene::VirtualScreenDriver::setForegroundColor(Color color) {
	this->foregroundColor = color;
}

void Graphene::VirtualScreenDriver::setBackgroundColor(Color color) {
	this->backgroundColor = color;
}

Graphene::Color Graphene::VirtualScreenDriver::getForegroundColor() const {
	return this->foregroundColor;
}

Graphene::Color Graphene::VirtualScreenDriver::getBackgroundColor() const {
	return this->backgroundColor;
}

uint32_t Graphene::VirtualScreenDriver::getWidth() const {
	return this->width;
}

uint32_t Graphene::VirtualScreenDriver::getHeight() const {
	return this->height;
}

uint8_t Graphene::VirtualScreenDriver::currentFrameIndex() const {
	return this->currentFrame;
}
