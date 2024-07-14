#include "CheckBox.h"

void Graphene::CheckBox::toggle() {
	this->checked = !this->checked;
	this->onStateChangeCallback(this->checked);
	this->forceRedraw();
}

void Graphene::CheckBox::draw(AbstractCanvas& canvas) {
	if (!this->isVisible()) {
		return;
	}

	if (this->_needsRedraw) {
		int boxSideLength = this->font.getHeight() + 4;

		canvas.fillRectangle(
			this->bounds.getTopLeft(), this->bounds.getWidth(), this->bounds.getHeight(), this->backgroundColor);
			
		Point centerLeftPoint(this->bounds.getTopLeft().getX(), this->bounds.getCenter().getY());

		Graphene::Rect textFrame = this->bounds;
		textFrame.setX(textFrame.getX() + boxSideLength + 10);
		canvas.drawString(textFrame,
						  this->text,
						  this->textColor,
						  this->backgroundColor,
						  this->font,
						  TextAlignment::LEFT);

		canvas.drawRectangle(
			Point(centerLeftPoint.getX(), centerLeftPoint.getY() - boxSideLength / 2),
			boxSideLength,
			boxSideLength,
			this->borderColor);

		if (this->checked) {
			canvas.drawLine(
				Point(centerLeftPoint.getX() + 2, centerLeftPoint.getY() - boxSideLength / 2 + 2),
				Point(centerLeftPoint.getX() + boxSideLength - 2, centerLeftPoint.getY() + boxSideLength / 2 - 2),
				this->checkColor);

			canvas.drawLine(
				Point(centerLeftPoint.getX() + boxSideLength - 2, centerLeftPoint.getY() - boxSideLength / 2 + 2),
				Point(centerLeftPoint.getX() + 2, centerLeftPoint.getY() + boxSideLength / 2 - 2),
				this->checkColor);
		}

		if (this->isFocused) {
			canvas.drawRectangle(this->bounds.getTopLeft(), this->bounds.getWidth(), this->bounds.getHeight(), this->borderColor);
		}

		this->_needsRedraw = false;
	}
}

void Graphene::CheckBox::onTap(TouchEvent* event) {
	this->toggle();
}

void Graphene::CheckBox::setText(String text) {
	this->text = text;
	this->forceRedraw();
}

void Graphene::CheckBox::setFont(Font font) {
	this->font = font;
	this->forceRedraw();
}

void Graphene::CheckBox::setTextColor(Color color) {
	this->textColor = color;
	this->forceRedraw();
}

void Graphene::CheckBox::setBackgroundColor(Color color) {
	this->backgroundColor = color;
	this->forceRedraw();
}

void Graphene::CheckBox::setBorderColor(Color color) {
	this->borderColor = color;
	this->forceRedraw();
}

void Graphene::CheckBox::setCheckColor(Color color) {
	this->checkColor = color;
	this->forceRedraw();
}

Graphene::String Graphene::CheckBox::getText() {
	return this->text;
}

void Graphene::CheckBox::onStateChange(std::function<void(bool)> callback) {
	this->onStateChangeCallback = callback;
}
