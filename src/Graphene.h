#if !defined(GRAPHENE_FRAMEWORK_H)
#define GRAPHENE_FRAMEWORK_H

// Core includes
#include "core/Color.h"
#include "core/Font.h"
#include "core/GrapheneFonts.h"
#include "core/Object.h"
#include "core/String.h"
#include "core/Variant.h"

// Events includes
#include "events/TouchEvent.h"

// Math includes
#include "math/Point.h"
#include "math/Rect.h"
#include "math/Vector3D.h"

// Interfaces includes
#include "interfaces/AbstractCanvas.h"
#include "interfaces/AbstractTouchInput.h"
#include "interfaces/IContainer.h"
#include "interfaces/IDrawable.h"
#include "interfaces/IWidget.h"

// Image includes, this acts as a driver
#include "image/Image.h"

// Widgets, layouts/containers and components includes
#include "components/layouts/HorizontalLayout.h"
#include "components/layouts/VerticalLayout.h"
#include "components/widgets/Button.h"
#include "components/widgets/Label.h"
#include "components/widgets/Slider.h"
#include "components/widgets/ProgressBar.h"

// Runtime includes
#include "runtime/GrapheneApp.h"

// Driver includes
// NodeMCU
#include "drivers/NodeMCU/NodeMCU_TFT.h"

// STM32F769I
#include "drivers/STM32F769I/STM32F769I_Canvas.h"
#include "drivers/STM32F769I/STM32F769I_Touch.h"
#include "drivers/STM32F769I/STMFonts.h"

// geometry includes

// Components includes

#endif	// GRAPHENE_FRAMEWORK_H
