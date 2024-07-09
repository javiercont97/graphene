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
		: IWidget(parent), value(0), min(0), max(100), step(5) {
	}

	Slider(uint16_t min, uint16_t max, uint16_t step, IContainer *parent = nullptr)
		: IWidget(parent), value(min), min(min), max(max), step(step) {
	}

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) override;

	private:
	// Inherited via IWidget
	void onMove(TouchEvent *event) override;

public:
	void setValue(uint16_t value);
	void setMin(uint16_t min);
	void setMax(uint16_t max);
	void setStep(uint16_t step);
	void setBackgroundColor(Color color);
	void setSliderColor(Color color);
	void setBorderColor(Color color);
	void setLineColor(Color color);

	uint16_t getValue();
	uint16_t getMin();
	uint16_t getMax();
	uint16_t getStep();
	Color getBackgroundColor();
	Color getSliderColor();
	Color getBorderColor();
	Color getLineColor();

	// Callbacks
	void onValueChange(std::function<void(uint16_t)> callback);

   private:
   uint16_t getNearestStep(Point point, uint16_t stepCount, uint16_t stepSize);

	private:
	uint16_t value;
	uint16_t min;
	uint16_t max;
	uint16_t step;

	Color backgroundColor = Graphene::WHITE;
	Color sliderColor = Graphene::BLUE;
	Color borderColor = Graphene::BLACK;
	Color lineColor = Graphene::BLACK;

	std::function<void(uint16_t)> valueChangeCallback = [](uint16_t value) {};
};

}  // namespace Graphene

#endif	// GRAPHENE_WIDGET_SLIDER_H
