#if !defined(GRAPHENE_BUTTON_WIDGET_H)
#define GRAPHENE_BUTTON_WIDGET_H

#include <functional>

#include "../../core/Color.h"
#include "../../core/Font.h"
#include "../../core/GrapheneFonts.h"
#include "../../core/String.h"
#include "../../interfaces/IContainer.h"
#include "../../interfaces/IWidget.h"

namespace Graphene {
class Button : public IWidget {
   public:
	Button(IContainer *parent = nullptr) : IWidget(parent) {
	}

	Button(
		String text, Font font, Color textColor, Color backgroundColor, Color borderColor, IContainer *parent = nullptr)
		: IWidget(parent),
		  text(text),
		  font(font),
		  textColor(textColor),
		  backgroundColor(backgroundColor),
		  borderColor(borderColor) {
	}

	Button(String text, Font font, IContainer *parent = nullptr) : IWidget(parent), text(text), font(font) {
	}

	Button(String text, IContainer *parent = nullptr) : IWidget(parent), text(text) {
	}

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) override;

	private:
	// Inherited via IWidget
	void onPress(TouchEvent *event) override;
	void onRelease(TouchEvent *event) override;
	void onTap(TouchEvent *event) override;

	public:
	// Setters
	void setText(String text);
	void setFont(Font font);
	void setTextColor(Color color);
	void setBackgroundColor(Color color);
	void setBorderColor(Color color);

	String getText();

	// Callbacks
	void onPress(std::function<void()> callback);
	void onRelease(std::function<void()> callback);
	void onTap(std::function<void()> callback);

   protected:
	String text;
	Font font = Graphene::Graphene24;
	Color textColor = Graphene::BLACK;
	Color backgroundColor = Graphene::WHITE;
	Color borderColor = Graphene::BLACK;

	std::function<void()> onPressCallback = []() {};
	std::function<void()> onReleaseCallback = []() {};
	std::function<void()> onTapCallback = []() {};
};
}  // namespace Graphene

#endif	// GRAPHENE_BUTTON_WIDGET_H
