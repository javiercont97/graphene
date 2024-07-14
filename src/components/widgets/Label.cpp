#include "Label.h"

void Graphene::Label::draw(AbstractCanvas& canvas) {
	if (!this->isVisible()) {
		return;
	}

	if (this->_needsRedraw) {
		canvas.fillRectangle(
			this->bounds.getTopLeft(), this->bounds.getWidth(), this->bounds.getHeight(), backgroundColor);
		canvas.drawString(bounds, text, textColor, backgroundColor, font, this->alignment);

		this->_needsRedraw = false;
	}
}

void Graphene::Label::setText(String text) {
	this->text = text;
	this->forceRedraw();
}

void Graphene::Label::setFont(Font font) {
	this->font = font;
	this->forceRedraw();
}

void Graphene::Label::setTextColor(Color color) {
	this->textColor = color;
	this->forceRedraw();
}

void Graphene::Label::setBackgroundColor(Color color) {
	this->backgroundColor = color;
	this->forceRedraw();
}

void Graphene::Label::setAlignment(Graphene::TextAlignment alignment) {
	this->alignment = alignment;
	this->forceRedraw();
}

Graphene::String Graphene::Label::getText() {
	return this->text;
}

Graphene::TextAlignment Graphene::Label::getAlignment() {
	return this->alignment;
}
