#if !defined(GRAPHENE_LABEL_WIDGET_H)
#define GRAPHENE_LABEL_WIDGET_H

#include <functional>

#include "../../core/Color.h"
#include "../../core/Font.h"
#include "../../core/GrapheneFonts.h"
#include "../../core/String.h"
#include "../../interfaces/IContainer.h"
#include "../../interfaces/IWidget.h"

namespace Graphene {
class Label : public IWidget {
   public:
	Label(IContainer *parent = nullptr) : IWidget(parent) {
	}

	Label(String text, Font font, Color textColor, Color backgroundColor, IContainer *parent = nullptr)
		: IWidget(parent), text(text), font(font), textColor(textColor), backgroundColor(backgroundColor) {
	}

	Label(String text, Font font, IContainer *parent = nullptr) : IWidget(parent), text(text), font(font) {
	}

	Label(String text, IContainer *parent = nullptr) : IWidget(parent), text(text) {
	}

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) override;

	// Setters
	void setText(String text);
	void setFont(Font font);
	void setTextColor(Color color);
	void setBackgroundColor(Color color);
	void setAlignment(Graphene::TextAlignment alignment);

	String getText();
	Graphene::TextAlignment getAlignment();

   protected:
	// rendering properties
	String text;
	Font font = Graphene::Graphene24;
	Color textColor = Graphene::BLACK;
	Color backgroundColor = Graphene::WHITE;
	Graphene::TextAlignment alignment = Graphene::TextAlignment::CENTER;
};
}  // namespace Graphene

#endif	// GRAPHENE_LABEL_WIDGET_H
