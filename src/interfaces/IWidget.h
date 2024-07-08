#if !defined(GRAPHENE_WIDGET_INTERFACE_H)
#define GRAPHENE_WIDGET_INTERFACE_H

#include "IDrawable.h"

namespace Graphene {
class IWidget : public IDrawable {
   public:
	IWidget(IContainer *parent = nullptr) : IDrawable(parent) {
	}

	// Inherited via IDrawable
	virtual void draw(AbstractCanvas &canvas) = 0;
	virtual bool needsRedraw() const override;

	void onTouchEvent(TouchEvent *event) override;
	void setFocus(bool focus);

   protected:
	virtual void onPress(TouchEvent *event){};
	virtual void onRelease(TouchEvent *event){};
	virtual void onTap(TouchEvent *event){};
	virtual void onMove(TouchEvent *event){};
	virtual void onFocus(){};
	virtual void onLostFocus(){};

   protected:
	bool isFocused = false;
	bool _needsRedraw = true;
};

}  // namespace Graphene

#endif	// GRAPHENE_WIDGET_INTERFACE_H
