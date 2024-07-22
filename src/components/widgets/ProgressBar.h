#if !defined(GRAPHENE_PROGRESS_BAR_WIDGET_H)
#define GRAPHENE_PROGRESS_BAR_WIDGET_H

#include "../../core/Color.h"
#include "../../core/Font.h"
#include "../../core/GrapheneFonts.h"
#include "../../core/String.h"
#include "../../interfaces/IContainer.h"
#include "../../interfaces/IWidget.h"

namespace Graphene {

class ProgressBar : public IWidget {
   public:
	ProgressBar(IContainer *parent = nullptr) : IWidget(parent), value(0), min(0), max(100) {
	}

	ProgressBar(Color backgroundColor, Color progressColor, Color borderColor, IContainer *parent = nullptr)
		: IWidget(parent),
		  value(0),
		  min(0),
		  max(100),
		  backgroundColor(backgroundColor),
		  progressColor(progressColor),
		  borderColor(borderColor) {
	}

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) override;

   public:
	void setValue(uint16_t value);
	void setBackgroundColor(Color color);
	void setProgressColor(Color color);
	void setBorderColor(Color color);

	uint16_t getValue();
	Color getBackgroundColor();
	Color getProgressColor();
	Color getBorderColor();

   private:
	uint16_t value;
	uint16_t min;
	uint16_t max;

	Color backgroundColor = Graphene::DARK_GRAY;
	Color progressColor = Graphene::GREEN;
	Color borderColor = Graphene::LIGHT_GRAY;
};

}  // namespace Graphene

#endif	// GRAPHENE_PROGRESS_BAR_WIDGET_H
