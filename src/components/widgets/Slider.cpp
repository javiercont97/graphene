#include "Slider.h"

void Graphene::Slider::draw(AbstractCanvas& canvas) {
	if (!this->isVisible()) {
		return;
	}
	
	if (this->_needsRedraw) {
		canvas.fillRectangle(
			this->bounds.getTopLeft(), this->bounds.getWidth(), this->bounds.getHeight(), this->backgroundColor);

		uint16_t stepCount = (this->max - this->min) / this->step;
		uint16_t stepSize = this->bounds.getWidth() / stepCount;

		Point xOffset((this->bounds.getWidth() - stepSize * stepCount) / 2, 0);
		Point leftStartingPoint = this->bounds.getTopLeft() + xOffset;

		Point rightEndPoint = leftStartingPoint + Point(stepCount * stepSize, 0);

		Point lineStart = leftStartingPoint + Point(0, this->bounds.getHeight() / 2);
		Point lineEnd = rightEndPoint + Point(0, this->bounds.getHeight() / 2);

		canvas.drawLine(lineStart, lineEnd, this->lineColor);

		uint16_t extremeIndicatorHeight = this->bounds.getHeight() / 3;
		uint16_t stepIndicatorHeight = this->bounds.getHeight() / 5;

		Point start = leftStartingPoint + Point(0, this->bounds.getHeight() / 2 - extremeIndicatorHeight);
		Point end = leftStartingPoint + Point(0, this->bounds.getHeight() / 2 + extremeIndicatorHeight);
		canvas.drawLine(start, end, this->lineColor);

		start = rightEndPoint + Point(0, this->bounds.getHeight() / 2 - extremeIndicatorHeight);
		end = rightEndPoint + Point(0, this->bounds.getHeight() / 2 + extremeIndicatorHeight);
		canvas.drawLine(start, end, this->lineColor);

		for (uint16_t i = 1; i < stepCount; i++) {
			Point start = leftStartingPoint + Point(i * stepSize, this->bounds.getHeight() / 2 - stepIndicatorHeight);
			Point end = leftStartingPoint + Point(i * stepSize, this->bounds.getHeight() / 2 + stepIndicatorHeight);
			canvas.drawLine(start, end, this->lineColor);
		}

		uint16_t currentStep = (this->value - this->min) / this->step;
		uint16_t sliderX = leftStartingPoint.getX() + currentStep * stepSize;

		uint16_t sliderWidth = 10;
		Point sliderTopLeft =
			Point(sliderX - sliderWidth / 2, this->bounds.getCenter().getY() - extremeIndicatorHeight);
		canvas.fillRectangle(sliderTopLeft, sliderWidth, 2 * extremeIndicatorHeight, this->sliderColor);

		if (this->isFocused) {
			canvas.drawRectangle(
				this->bounds.getTopLeft(), this->bounds.getWidth(), this->bounds.getHeight(), this->borderColor);
		}

		this->_needsRedraw = false;
	}
}

void Graphene::Slider::onMove(TouchEvent* event) {
	uint16_t stepCount = (this->max - this->min) / this->step;
	uint16_t stepSize = this->bounds.getWidth() / stepCount;

	uint16_t currentStep = this->getNearestStep(event->position, stepCount, stepSize);

	uint16_t newValue = this->min + currentStep * this->step;
	this->setValue(newValue);
}

void Graphene::Slider::setValue(uint16_t value) {
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

void Graphene::Slider::setStep(uint16_t step) {
	this->step = step;
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

uint16_t Graphene::Slider::getStep() {
	return this->step;
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

uint16_t Graphene::Slider::getNearestStep(Point point, uint16_t stepCount, uint16_t stepSize) {
	uint16_t approxStep = (point.getX() - this->bounds.getTopLeft().getX()) / stepSize;

	if (approxStep > stepCount) {
		return this->max;
	}

	u_int16_t leftX = this->bounds.getTopLeft().getX() + approxStep * stepSize;
	u_int16_t rightX = leftX + stepSize;

	uint16_t leftDiff = point.getX() - leftX;
	uint16_t rightDiff = rightX - point.getX();

	if (leftDiff < rightDiff) {
		return approxStep;
	}
	return approxStep + 1;
}
