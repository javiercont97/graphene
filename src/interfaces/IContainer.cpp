#include "IContainer.h"

void Graphene::IContainer::add(IDrawable* drawable) {
	children.push_back(drawable);
	this->updateLayout();
}

void Graphene::IContainer::remove(IDrawable* drawable) {
	children.erase(std::remove(children.begin(), children.end(), drawable), children.end());
	this->updateLayout();
}

void Graphene::IContainer::clear() {
	children.clear();
	this->updateLayout();
}

void Graphene::IContainer::updateLayout() {
	this->forceRedraw();
}

void Graphene::IContainer::draw(AbstractCanvas& canvas) {
	if (!this->isVisible()) {
		return;
	}

	for (auto child : children) {
		child->draw(canvas);
	}
}

bool Graphene::IContainer::needsRedraw() const {
	for (auto child : children) {
		if (child->needsRedraw()) {
			return true;
		}
	}
	return false;
}

void Graphene::IContainer::forceRedraw() {
	for (auto child : children) {
		child->forceRedraw();
	}
}

void Graphene::IContainer::onTouchEvent(TouchEvent* event) {
	if (!this->isVisible()) {
		return;
	}

	for (auto child : children) {
		if (child->getBounds().contains(event->position)) {
			child->onTouchEvent(event);
		}
	}
}

void Graphene::IContainer::setBounds(Rect bounds) {
	IDrawable::setBounds(bounds);
	this->updateLayout();
}

void Graphene::IContainer::setStretchX(uint8_t stretchX) {
	IDrawable::setStretchX(stretchX);
	this->updateLayout();
}

void Graphene::IContainer::setStretchY(uint8_t stretchY) {
	IDrawable::setStretchY(stretchY);
	this->updateLayout();
}

int Graphene::IContainer::getSpacing() const {
	return spacing;
}

void Graphene::IContainer::setSpacing(int spacing) {
	this->spacing = spacing;
	updateLayout();
}

int Graphene::IContainer::getTopPadding() const {
	return this->topPadding;
}

void Graphene::IContainer::setTopPadding(int topPadding) {
	this->topPadding = topPadding;
	updateLayout();
}

int Graphene::IContainer::getRightPadding() const {
	return this->rightPadding;
}

void Graphene::IContainer::setRightPadding(int rightPadding) {
	this->rightPadding = rightPadding;
	updateLayout();
}

int Graphene::IContainer::getBottomPadding() const {
	return this->bottomPadding;
}

void Graphene::IContainer::setBottomPadding(int bottomPadding) {
	this->bottomPadding = bottomPadding;
	updateLayout();
}

int Graphene::IContainer::getLeftPadding() const {
	return this->leftPadding;
}

void Graphene::IContainer::setLeftPadding(int leftPadding) {
	this->leftPadding = leftPadding;
	updateLayout();
}

Graphene::Color Graphene::IContainer::getBackgroundColor() const {
	return this->backgroundColor;
}

void Graphene::IContainer::setBackgroundColor(Graphene::Color color) {
	this->backgroundColor = color;
	updateLayout();
}
