#if !defined(GRAPHENE_FRAMEWORK_H)
#define GRAPHENE_FRAMEWORK_H

// Core includes
#include "core/Color.h"
#include "core/Font.h"
#include "core/GrapheneFonts.h"
#include "core/String.h"

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
#include "components/layouts/PaginatedView.h"
#include "components/layouts/VerticalLayout.h"
#include "components/widgets/Button.h"
#include "components/widgets/CheckBox.h"
#include "components/widgets/Label.h"
#include "components/widgets/ProgressBar.h"
#include "components/widgets/Slider.h"

// Runtime includes
#include "runtime/GrapheneApp.h"

// Driver includes
// Generic drivers
#include "drivers/NoTouchDriver.h"

// NodeMCU
#include "drivers/NodeMCU/NodeMCU_TFT.h"

// STM32F769I
#include "drivers/STM32F769I/STM32F769I_Canvas.h"
#include "drivers/STM32F769I/STM32F769I_Touch.h"

namespace Graphene {
#include <map>

class SYSTEM {
   public:
	static std::vector<String> getSystemFonts() {
		std::vector<String> fontNames = {};
		for (auto &pair : GrapheneSystemFonts) {
			fontNames.push_back(pair.first);
		}
		return fontNames;
	}

	static Font &getSystemFont(String fontName) {
		return GrapheneSystemFonts[fontName];
	}

	static std::map<String, Font> GrapheneSystemFonts;
};

std::map<String, Font> SYSTEM::GrapheneSystemFonts = {
	{"ubuntu_light_9px", Font(ubuntu_light_9_table, 8, 9)},
	{"ubuntu_light_16px", Font(ubuntu_light_16_table, 16, 16)},
	{"ubuntu_light_20px", Font(ubuntu_light_20_table, 16, 20)},
	{"ubuntu_light_23px", Font(ubuntu_light_23_table, 16, 23)},
	{"ubuntu_light_35px", Font(ubuntu_light_35_table, 24, 35)},
};

}  // namespace Graphene

#endif	// GRAPHENE_FRAMEWORK_H
