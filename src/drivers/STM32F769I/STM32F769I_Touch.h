#if defined(ENABLE_STM32F769I_DRIVERS)

#if !defined(GRAPHENE_STM32F769I_TOUCH_DRIVER_H)
#define GRAPHENE_STM32F769I_TOUCH_DRIVER_H

#include <stm32f769i_discovery_ts.h>

#include "../../math/Point.h"

namespace GrapheneDrivers {

class STM32F769I_Touch : public Graphene::AbstractTouchInput {
   public:
	STM32F769I_Touch() {
		if (BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize()) == TS_ERROR) {
			printf("BSP_TS_Init error\n");
			return;
		}
	}

	// Implement inherited pure virtual functions from
	// Graphene::AbstractTouchInput
	std::vector<Graphene::Point> getTouchPoints() override {
		std::vector<Graphene::Point> touchPoints;

		TS_StateTypeDef TS_State = {0};
		BSP_TS_GetState(&TS_State);

		if (TS_State.touchDetected) {
			Graphene::Point touchPoint(TS_State.touchX[0], TS_State.touchY[0]);
			touchPoints.push_back(touchPoint);
		}

		return touchPoints;
	}
};

}  // namespace GrapheneDrivers

#endif	// GRAPHENE_STM32F769I_TOUCH_DRIVER_H

#endif	// ENABLE_STM32F769I_DRIVERS
