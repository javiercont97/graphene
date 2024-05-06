#include "FrameBuffer.h"

Graphene::FrameBuffer::FrameBuffer(uint32_t width, uint32_t height) {
	this->width = width;
	this->height = height;

	for (uint32_t i = 0; i < width * height; i++) {
		buffer.push_back(Graphene::BLACK);
	}

	this->clear(Graphene::BLACK);
}

Graphene::FrameBuffer::~FrameBuffer() {
}

uint32_t Graphene::FrameBuffer::getWidth() const {
	return width;
}

uint32_t Graphene::FrameBuffer::getHeight() const {
	return height;
}

std::vector<Graphene::Color> Graphene::FrameBuffer::getBuffer() const {
	return buffer;
}

void Graphene::FrameBuffer::clear(Graphene::Color color) {
	for (uint32_t i = 0; i < width * height; i++) {
		buffer[i] = color;
	}
}

void Graphene::FrameBuffer::setPixel(Graphene::Point point, Graphene::Color color) {
	this->buffer[point.getY() * width + point.getX()] = color;
}

void Graphene::FrameBuffer::setPixel(uint32_t x, uint32_t y, Graphene::Color color) {
	this->buffer[y * width + x] = color;
}

Graphene::Color Graphene::FrameBuffer::getPixel(Graphene::Point point) const {
	return this->buffer[point.getY() * width + point.getX()];
}

Graphene::Color Graphene::FrameBuffer::getPixel(uint32_t x, uint32_t y) const {
	return this->buffer[y * width + x];
}
