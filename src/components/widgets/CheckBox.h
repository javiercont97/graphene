#if !defined(GRAPHENE_CHECKBOX_WIDGET_H)
#define GRAPHENE_CHECKBOX_WIDGET_H

#include <functional>

#include "../../core/Color.h"
#include "../../core/Font.h"
#include "../../core/GrapheneFonts.h"
#include "../../core/String.h"
#include "../../interfaces/IContainer.h"
#include "../../interfaces/IWidget.h"

namespace Graphene {
class CheckBox : public IWidget {
   public:
	CheckBox(IContainer *parent = nullptr) : IWidget(parent) {
	}

	CheckBox(
		String text, Font font, Color textColor, Color backgroundColor, Color borderColor, IContainer *parent = nullptr)
		: IWidget(parent),
		  text(text),
		  font(font),
		  textColor(textColor),
		  backgroundColor(backgroundColor),
		  borderColor(borderColor) {
	}

	CheckBox(String text, Font font, IContainer *parent = nullptr) : IWidget(parent), text(text), font(font) {
	}

	CheckBox(String text, IContainer *parent = nullptr) : IWidget(parent), text(text) {
	}

	void toggle();

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) override;

   private:
	// Inherited via IWidget
	void onTap(TouchEvent *event) override;

   public:
	// Setters
	void setText(String text);
	void setFont(Font font);
	void setTextColor(Color color);
	void setBackgroundColor(Color color);
	void setBorderColor(Color color);
	void setCheckColor(Color color);

	String getText();
	bool isChecked();

	// Callbacks
	void onStateChange(std::function<void(bool)> callback);

   protected:
	String text;
	Font font = Graphene::Font(ubuntu_light_16_table, 16, 16);
	Color textColor = Graphene::BLACK;
	Color backgroundColor = Graphene::WHITE;
	Color borderColor = Graphene::BLACK;
	Color checkColor = Graphene::GREEN;
	bool checked = false;

	std::function<void(bool)> onStateChangeCallback = [](bool state) {};
};
}  // namespace Graphene

#endif	// GRAPHENE_CHECKBOX_WIDGET_H
