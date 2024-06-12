#include "AbstractCanvas.h"

Graphene::AbstractCanvas::AbstractCanvas() : bounds(0, 0, 0, 0) {
}

Graphene::AbstractCanvas::AbstractCanvas(uint32_t width, uint32_t height) : bounds(0, 0, width, height) {
}

Graphene::AbstractCanvas::~AbstractCanvas() {
}

int32_t Graphene::AbstractCanvas::getWidth() const {
	return this->bounds.getWidth();
}

int32_t Graphene::AbstractCanvas::getHeight() const {
	return this->bounds.getHeight();
}

Graphene::Rect Graphene::AbstractCanvas::getBounds() const {
	return this->bounds;
}
