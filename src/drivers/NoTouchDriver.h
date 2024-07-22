#if !defined(GRAPHENE_NO_TOUCH_DRIVER)
#define GRAPHENE_NO_TOUCH_DRIVER

#include "../interfaces/AbstractTouchInput.h"

namespace Graphene {
class NoTouchDriver : public Graphene::AbstractTouchInput {
   public:
	NoTouchDriver() {
	}

	std::vector<Graphene::Point> getTouchPoints() override {
		return {};
	}
};
}  // namespace Graphene

#endif	// GRAPHENE_NO_TOUCH_DRIVER
