#if !defined(GRAPHENE_TOUCH_EVENT_H)
#define GRAPHENE_TOUCH_EVENT_H

#include "../math/Point.h"

namespace Graphene {
enum class TouchEventType { PRESS, RELEASE, TAP, LONG_PRESS, DOUBLE_TAP, DRAG, DROP };

class TouchEvent {
   public:
	TouchEvent(TouchEventType type, Point p) : type(type), p(p) {
	}

	TouchEventType getType() const {
		return type;
	}

	int getX() const {
		return p.getX();
	}

	int getY() const {
		return p.getY();
	}

	Point getP() {
		return p;
	}

   private:
	TouchEventType type;
	Point p;
};
}  // namespace Graphene

#endif	// GRAPHENE_TOUCH_EVENT_H
