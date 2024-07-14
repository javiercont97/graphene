#if !defined(GRAPHENE_WIDGET_SLIDER_H)
#define GRAPHENE_WIDGET_SLIDER_H

#include <functional>

#include "../../core/Color.h"
#include "../../core/Font.h"
#include "../../core/GrapheneFonts.h"
#include "../../core/String.h"
#include "../../interfaces/IContainer.h"
#include "../../interfaces/IWidget.h"

namespace Graphene {

class Slider: public IWidget {
   public:
	Slider(IContainer *parent = nullptr)
		: IWidget(parent), value(0), min(0), max(100) {
	}

	Slider(uint16_t min, uint16_t max, IContainer *parent = nullptr)
		: IWidget(parent), value(min), min(min), max(max) {
	}

	Slider(uint16_t min,
		   uint16_t max,
		   Color backgroundColor,
		   Color sliderColor,
		   Color borderColor,
		   Color lineColor,
		   IContainer *parent = nullptr)
		: IWidget(parent),
		  value(min),
		  min(min),
		  max(max),
		  backgroundColor(backgroundColor),
		  sliderColor(sliderColor),
		  borderColor(borderColor),
		  lineColor(lineColor) {
	}

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) override;

	private:
	// Inherited via IWidget
	void onPress(TouchEvent *event) override;
	void onMove(TouchEvent *event) override;

public:
	void setValue(uint16_t value);
	void setMin(uint16_t min);
	void setMax(uint16_t max);
	void setBackgroundColor(Color color);
	void setSliderColor(Color color);
	void setBorderColor(Color color);
	void setLineColor(Color color);

	uint16_t getValue();
	uint16_t getMin();
	uint16_t getMax();
	Color getBackgroundColor();
	Color getSliderColor();
	Color getBorderColor();
	Color getLineColor();

	// Callbacks
	void onValueChange(std::function<void(uint16_t)> callback);

	private:
	uint16_t value;
	uint16_t min;
	uint16_t max;

	Color backgroundColor = Graphene::WHITE;
	Color sliderColor = Graphene::BLUE;
	Color borderColor = Graphene::BLACK;
	Color lineColor = Graphene::BLACK;

	std::function<void(uint16_t)> valueChangeCallback = [](uint16_t value) {};
};

}  // namespace Graphene

#endif	// GRAPHENE_WIDGET_SLIDER_H
