#include "IWidget.h"

void Graphene::IWidget::onTouchEvent(TouchEvent* event) {
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