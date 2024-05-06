#include "Point.h"

Graphene::Point::Point() : x(0), y(0) {
}

Graphene::Point::Point(uint32_t x, uint32_t y) : x(x), y(y) {
}

Graphene::Point::Point(const Point& point) {
	this->x = point.x;
	this->y = point.y;
}

Graphene::Point& Graphene::Point::operator=(const Point& point) {
	this->x = point.x;
	this->y = point.y;
	return *this;
}

uint32_t Graphene::Point::getX() const {
	// return x;
	return this->x;
}

uint32_t Graphene::Point::getY() const {
	// return y;
	return this->y;
}

void Graphene::Point::setX(uint32_t x) {
	// assign x to this->x
	this->x = x;
}

void Graphene::Point::setY(uint32_t y) {
	// assign y to this->y
	this->y = y;
}

bool Graphene::Point::operator==(const Point& point) const {
	return this->x == point.x && this->y == point.y;
}

bool Graphene::Point::operator!=(const Point& point) const {
	return this->x != point.x || this->y != point.y;
}

Graphene::Point Graphene::Point::operator+(const Point& point) const {
	Point p;
	p.x = this->x + point.x;
	p.y = this->y + point.y;
	return p;
}

Graphene::Point Graphene::Point::operator-(const Point& point) const {
	Point p;
	p.x = this->x - point.x;
	p.y = this->y - point.y;
	return p;
}

Graphene::Point Graphene::Point::operator+=(const Point& point) {
	this->x += point.x;
	this->y += point.y;
	return *this;
}

Graphene::Point Graphene::Point::operator-=(const Point& point) {
	this->x -= point.x;
	this->y -= point.y;
	return *this;
}

uint32_t Graphene::Point::distanceTo(const Point& point) const {
	int deltaX = point.x - this->x;
	int deltaY = point.y - this->y;

	return std::sqrt(deltaX * deltaX + deltaY * deltaY);
}

Graphene::String Graphene::Point::toString() const {
	return Graphene::String::asPrintf("(%d, %d)", this->x, this->y);
}
