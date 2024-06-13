#include "Button.h"

void Graphene::Button::draw(AbstractCanvas& canvas) {
	canvas.fillRectangle(bounds.getTopLeft(), bounds.getWidth(), bounds.getHeight(), backgroundColor);

	canvas.drawRectangle(bounds.getTopLeft(), bounds.getWidth(), bounds.getHeight(), borderColor);

	canvas.drawString(bounds.getCenter(), text, textColor, backgroundColor, font, Graphene::TextAlignment::CENTER);
}

//====================================================================
// getters and setters
//====================================================================

void Graphene::Button::onPress(TouchEvent* event) {
	this->onPressCallback();
}

void Graphene::Button::onRelease(TouchEvent* event) {
	this->onReleaseCallback();
}

void Graphene::Button::onTap(TouchEvent* event) {
	this->onTapCallback();
}

void Graphene::Button::setText(String text) {
	this->text = text;
}

void Graphene::Button::setFont(Font font) {
	this->font = font;
}

void Graphene::Button::setTextColor(Color color) {
	this->textColor = color;
}

void Graphene::Button::setBackgroundColor(Color color) {
	this->backgroundColor = color;
}

void Graphene::Button::setBorderColor(Color color) {
	this->borderColor = color;
}

Graphene::String Graphene::Button::getText() {
	return this->text;
}

void Graphene::Button::onPress(std::function<void()> callback) {
	this->onPressCallback = callback;
}

void Graphene::Button::onRelease(std::function<void()> callback) {
	this->onReleaseCallback = callback;
}

void Graphene::Button::onTap(std::function<void()> callback) {
	this->onTapCallback = callback;
}
