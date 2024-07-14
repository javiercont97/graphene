#include "Slider.h"

void Graphene::Slider::draw(AbstractCanvas& canvas) {
	if (!this->isVisible()) {
		return;
	}

	if (this->_needsRedraw) {
		canvas.fillRectangle(
			this->bounds.getTopLeft(), this->bounds.getWidth(), this->bounds.getHeight(), this->backgroundColor);

		// Draw the slider line
		canvas.drawLine({this->bounds.getTopLeft().getX() + 10, this->bounds.getCenter().getY()},
						{this->bounds.getTopRight().getX() - 10, this->bounds.getCenter().getY()},
						this->lineColor);

		// Draw the slider
		uint16_t sliderRadius = 10;
		uint16_t sliderX = (this->value - this->min) * (this->bounds.getWidth() - 20) / (this->max - this->min)
						   + (this->bounds.getTopLeft().getX() + 10);
		canvas.fillCircle({sliderX, this->bounds.getCenter().getY()}, sliderRadius, this->sliderColor);

		if (this->isFocused) {
			canvas.drawRectangle(
				this->bounds.getTopLeft(), this->bounds.getWidth(), this->bounds.getHeight(), this->borderColor);
		}

		this->_needsRedraw = false;
	}
}

void Graphene::Slider::onPress(TouchEvent* event) {
	this->onMove(event);
}

void Graphene::Slider::onMove(TouchEvent* event) {
	uint16_t newValue = (event->position.getX() - this->bounds.getTopLeft().getX() - 10) * (this->max - this->min)
							/ (this->bounds.getWidth() - 20)
						+ this->min;

	this->setValue(newValue);
}

void Graphene::Slider::setValue(uint16_t value) {
	if (value < this->min) {
		value = this->min;
	} else if (value > this->max) {
		value = this->max;
	}

	this->value = value;
	this->valueChangeCallback(value);
	this->forceRedraw();
}

void Graphene::Slider::setMin(uint16_t min) {
	if (min < this->max) {
		this->min = min;
	}

	if (this->value < this->min) {
		this->setValue(this->min);
	}

	this->forceRedraw();
}

void Graphene::Slider::setMax(uint16_t max) {
	if (max > this->min) {
		this->max = max;
	}

	if (this->value > this->max) {
		this->setValue(this->max);
	}

	this->forceRedraw();
}

void Graphene::Slider::setBackgroundColor(Color color) {
	this->backgroundColor = color;
	this->forceRedraw();
}

void Graphene::Slider::setSliderColor(Color color) {
	this->sliderColor = color;
	this->forceRedraw();
}

void Graphene::Slider::setBorderColor(Color color) {
	this->borderColor = color;
	this->forceRedraw();
}

void Graphene::Slider::setLineColor(Color color) {
	this->lineColor = color;
	this->forceRedraw();
}

uint16_t Graphene::Slider::getValue() {
	return this->value;
}

uint16_t Graphene::Slider::getMin() {
	return this->min;
}

uint16_t Graphene::Slider::getMax() {
	return this->max;
}

Graphene::Color Graphene::Slider::getBackgroundColor() {
	return this->backgroundColor;
}

Graphene::Color Graphene::Slider::getSliderColor() {
	return this->sliderColor;
}

Graphene::Color Graphene::Slider::getBorderColor() {
	return this->borderColor;
}

Graphene::Color Graphene::Slider::getLineColor() {
	return this->lineColor;
}

void Graphene::Slider::onValueChange(std::function<void(uint16_t)> callback) {
	this->valueChangeCallback = callback;
}
