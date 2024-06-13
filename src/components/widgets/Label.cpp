#include "Label.h"

void Graphene::Label::draw(AbstractCanvas& canvas) {
	canvas.drawString(bounds.getCenter(), text, textColor, backgroundColor, font, Graphene::TextAlignment::CENTER);
}

void Graphene::Label::setText(String text) {
	this->text = text;
}

void Graphene::Label::setFont(Font font) {
	this->font = font;
}

void Graphene::Label::setTextColor(Color color) {
	this->textColor = color;
}

void Graphene::Label::setBackgroundColor(Color color) {
	this->backgroundColor = color;
}

Graphene::String Graphene::Label::getText() {
	return this->text;
}
