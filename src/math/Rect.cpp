#include "Rect.h"

Graphene::Rect::Rect() : p(0, 0), width(0), height(0) {
}

Graphene::Rect::Rect(int32_t x, int32_t y, uint32_t width, uint32_t height) : p(x, y), width(width), height(height) {
}

Graphene::Rect::Rect(Point p, uint32_t width, uint32_t height) : p(p), width(width), height(height) {
}

// Getters and setters
int32_t Graphene::Rect::getX() const {
	return p.getX();
}

int32_t Graphene::Rect::getY() const {
	return p.getY();
}

int32_t Graphene::Rect::getWidth() const {
	return width;
}

int32_t Graphene::Rect::getHeight() const {
	return height;
}

void Graphene::Rect::setX(int32_t x) {
	p.setX(x);
}

void Graphene::Rect::setY(int32_t y) {
	p.setY(y);
}

void Graphene::Rect::setWidth(uint32_t width) {
	this->width = width;
}

void Graphene::Rect::setHeight(uint32_t height) {
	this->height = height;
}

Graphene::Point Graphene::Rect::getTopLeft() const {
	return p;
}

Graphene::Point Graphene::Rect::getBottomRight() const {
	return Point(p.getX() + width, p.getY() + height);
}

Graphene::Point Graphene::Rect::getCenter() const {
	return Point(p.getX() + width / 2, p.getY() + height / 2);
}

void Graphene::Rect::setTopLeft(Graphene::Point p) {
	this->p = p;
}

// Check if a point is inside the rectangle
bool Graphene::Rect::contains(Graphene::Point p) const {
	return p.getX() >= getX() && p.getX() <= getX() + getWidth() && p.getY() >= getY()
		   && p.getY() <= getY() + getHeight();
}

// Check if a rectangle is inside the rectangle
bool Graphene::Rect::contains(Graphene::Rect r) const {
	return contains(r.getTopLeft()) && contains(r.getBottomRight());
}