#include "Button.h"

void Graphene::Button::click() {
	this->onPressCallback();
	this->onReleaseCallback();
	this->onTapCallback();
}

void Graphene::Button::draw(AbstractCanvas& canvas) {
	if (!this->isVisible()) {
		return;
	}

	if (this->_needsRedraw) {
		canvas.fillRectangle(bounds.getTopLeft(), bounds.getWidth(), bounds.getHeight(), backgroundColor);
		canvas.drawString(bounds, text, textColor, backgroundColor, font, this->alignment);

		if (this->isFocused) {
			canvas.drawRectangle(bounds.getTopLeft(), bounds.getWidth(), bounds.getHeight(), borderColor);
		}

		this->_needsRedraw = false;
	}
}

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
	this->forceRedraw();
}

void Graphene::Button::setFont(Font font) {
	this->font = font;
	this->forceRedraw();
}

void Graphene::Button::setTextColor(Color color) {
	this->textColor = color;
	this->forceRedraw();
}

void Graphene::Button::setBackgroundColor(Color color) {
	this->backgroundColor = color;
	this->forceRedraw();
}

void Graphene::Button::setBorderColor(Color color) {
	this->borderColor = color;
	this->forceRedraw();
}

void Graphene::Button::setAlignment(Graphene::TextAlignment alignment) {
	this->alignment = alignment;
	this->forceRedraw();
}

Graphene::String Graphene::Button::getText() {
	return this->text;
}

Graphene::TextAlignment Graphene::Button::getAlignment() {
	return this->alignment;
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
