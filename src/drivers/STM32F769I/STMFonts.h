#if defined(ENABLE_STM32F769I_DRIVERS)

#if !defined(GRAPHENE_STM32F769I_FONTS_H)
#define GRAPHENE_STM32F769I_FONTS_H

#include <stdint.h>
#include <stm32f769i_discovery.h>
#include <stm32f769i_discovery_lcd.h>

#include "../../core/Font.h"

namespace Graphene {
const Font STMFont24(Font24.table, 17, 24);
const Font STMFont20(Font20.table, 14, 20);
const Font STMFont16(Font16.table, 11, 16);
const Font STMFont12(Font12.table, 7, 12);
const Font STMFont8(Font8.table, 5, 8);

}  // namespace Graphene

#endif	// GRAPHENE_STM32F769I_FONTS_H

#endif	// ENABLE_STM32F769I_DRIVERS