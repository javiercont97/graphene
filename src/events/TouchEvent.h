#if !defined(GRAPHENE_TOUCH_EVENT_H)
#define GRAPHENE_TOUCH_EVENT_H

#include <chrono>

#include "../math/Point.h"

namespace Graphene {
enum class TouchEventType { PRESS, RELEASE, TAP, LONG_PRESS, DOUBLE_TAP, MOVE };

struct TouchEvent {
	TouchEventType type;
	Point position;
	std::chrono::steady_clock::time_point timestamp;
};

}  // namespace Graphene

#endif	// GRAPHENE_TOUCH_EVENT_H
