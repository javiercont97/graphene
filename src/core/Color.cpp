#include "Color.h"

Graphene::Color::Color() : red(0), green(0), blue(0), alpha(255) {
}

Graphene::Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
	: red(red), green(green), blue(blue), alpha(alpha) {
}

Graphene::Color::Color(const Color &color) : red(color.red), green(color.green), blue(color.blue), alpha(color.alpha) {
}

Graphene::Color &Graphene::Color::operator=(const Color &color) {
	red = color.red;
	green = color.green;
	blue = color.blue;
	alpha = color.alpha;
	return *this;
}

Graphene::Color &Graphene::Color::operator=(const uint32_t &color) {
	return *this = Color::ColorFactory::fromARGB8888(color);
}

bool Graphene::Color::operator==(const Color &color) const {
	return red == color.red && green == color.green && blue == color.blue && alpha == color.alpha;
}

bool Graphene::Color::operator!=(const Color &color) const {
	return red != color.red || green != color.green || blue != color.blue || alpha != color.alpha;
}

Graphene::Color::operator uint32_t() const {
	return (alpha << 24) | (red << 16) | (green << 8) | blue;
}

uint8_t Graphene::Color::getRed() const {
	return red;
}

uint8_t Graphene::Color::getGreen() const {
	return green;
}

uint8_t Graphene::Color::getBlue() const {
	return blue;
}

uint8_t Graphene::Color::getAlpha() const {
	return alpha;
}

void Graphene::Color::setRed(uint8_t red) {
	this->red = red;
}

void Graphene::Color::setGreen(uint8_t green) {
	this->green = green;
}

void Graphene::Color::setBlue(uint8_t blue) {
	this->blue = blue;
}

void Graphene::Color::setAlpha(uint8_t alpha) {
	this->alpha = alpha;
}

uint32_t Graphene::Color::toRGBA8888() const {
	return (red << 24) | (green << 16) | (blue << 8) | alpha;
}

uint32_t Graphene::Color::toARGB8888() const {
	return (alpha << 24) | (red << 16) | (green << 8) | blue;
}

uint16_t Graphene::Color::toRGB565() const {
	uint8_t r5 = (red * 31) / 255;
	uint8_t g6 = (green * 63) / 255;
	uint8_t b5 = (blue * 31) / 255;

	return (r5 << 11) | (g6 << 5) | b5;
}

uint32_t Graphene::Color::toRGB888() const {
	return (red << 16) | (green << 8) | blue;
}

uint8_t Graphene::Color::toGray8() const {
	return (red + green + blue) / 3;
}

uint32_t Graphene::Color::toFormat(PixelFormat format) const {
	switch (format) {
		case PixelFormat::RGBA8888:
			return toRGBA8888();
		case PixelFormat::ARGB8888:
			return toARGB8888();
		case PixelFormat::RGB565:
			return toRGB565();
		case PixelFormat::RGB888:
			return toRGB888();
		case PixelFormat::GRAY8:
			return toGray8();
	}
	return 0;
}
