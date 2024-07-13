#include "IWidget.h"

bool Graphene::IWidget::needsRedraw() const {
	return this->_needsRedraw;
}

void Graphene::IWidget::forceRedraw() {
	this->_needsRedraw = true;
}

void Graphene::IWidget::onTouchEvent(TouchEvent* event) {
	if (!this->isVisible()) {
		return;
	}
	
	switch (event->type) {
		case TouchEventType::PRESS:
			onPress(event);
			break;
		case TouchEventType::RELEASE:
			onRelease(event);
			break;
		case TouchEventType::TAP:
			onTap(event);
			break;
		case TouchEventType::MOVE:
			onMove(event);
			break;
	}
}

void Graphene::IWidget::setFocus(bool focus) {
	isFocused = focus;
	if (focus) {
		onFocus();
	} else {
		onLostFocus();
	}

	_needsRedraw = true;
}
