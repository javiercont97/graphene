#include "Label.h"

void Graphene::Label::draw(AbstractCanvas& canvas) {
	if (this->_needsRedraw) {
		canvas.drawString(bounds.getCenter(), text, textColor, backgroundColor, font, Graphene::TextAlignment::CENTER);

		this->_needsRedraw = false;
	}
}

void Graphene::Label::setText(String text) {
	this->text = text;
	this->_needsRedraw = true;	// force redraw
}

void Graphene::Label::setFont(Font font) {
	this->font = font;
	this->_needsRedraw = true;	// force redraw
}

void Graphene::Label::setTextColor(Color color) {
	this->textColor = color;
	this->_needsRedraw = true;	// force redraw
}

void Graphene::Label::setBackgroundColor(Color color) {
	this->backgroundColor = color;
	this->_needsRedraw = true;	// force redraw
}

Graphene::String Graphene::Label::getText() {
	return this->text;
}
