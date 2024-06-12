#include "AbstractCanvas.h"

Graphene::AbstractCanvas::AbstractCanvas() {
	this->width = 0;
	this->height = 0;
}

Graphene::AbstractCanvas::AbstractCanvas(uint32_t width, uint32_t height) {
	this->width = width;
	this->height = height;
}

Graphene::AbstractCanvas::~AbstractCanvas() {
}

uint32_t Graphene::AbstractCanvas::getWidth() const {
	return this->width;
}

uint32_t Graphene::AbstractCanvas::getHeight() const {
	return this->height;
}
