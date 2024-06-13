#if !defined(GRAPHENE_TOUCH_INPUT_INTERFACE_H)
#define GRAPHENE_TOUCH_INPUT_INTERFACE_H

#include <vector>

#include "../events/TouchEvent.h"
#include "../math/Point.h"

namespace Graphene {

class AbstractTouchInput {
   public:
	AbstractTouchInput();
	virtual ~AbstractTouchInput();

	virtual std::vector<Point> getTouchPoints() = 0;

   protected:
};

}  // namespace Graphene

#endif	// GRAPHENE_TOUCH_INPUT_INTERFACE_H
