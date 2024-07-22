#include "ProgressBar.h"

void Graphene::ProgressBar::draw(AbstractCanvas& canvas) {
	if (!this->isVisible()) {
		return;
	}

	if (this->_needsRedraw) {
		canvas.fillRectangle(bounds.getTopLeft(), bounds.getWidth(), bounds.getHeight(), backgroundColor);

		uint16_t progressWidth = (value - min) * bounds.getWidth() / (max - min) + min;

		if (value > min) {
			canvas.fillRectangle(bounds.getTopLeft(), progressWidth, bounds.getHeight(), progressColor);
		}

		canvas.drawRectangle(bounds.getTopLeft(), bounds.getWidth(), bounds.getHeight(), borderColor);

		this->_needsRedraw = false;
	}
}

void Graphene::ProgressBar::setValue(uint16_t value) {
	if (value < min) {
		value = min;
	} else if (value > max) {
		value = max;
	}

	this->value = value;
	this->forceRedraw();
}

void Graphene::ProgressBar::setBackgroundColor(Color color) {
	this->backgroundColor = color;
	this->forceRedraw();
}

void Graphene::ProgressBar::setProgressColor(Color color) {
	this->progressColor = color;
	this->forceRedraw();
}

void Graphene::ProgressBar::setBorderColor(Color color) {
	this->borderColor = color;
	this->forceRedraw();
}

uint16_t Graphene::ProgressBar::getValue() {
	return this->value;
}

Graphene::Color Graphene::ProgressBar::getBackgroundColor() {
	return this->backgroundColor;
}

Graphene::Color Graphene::ProgressBar::getProgressColor() {
	return this->progressColor;
}

Graphene::Color Graphene::ProgressBar::getBorderColor() {
	return this->borderColor;
}
