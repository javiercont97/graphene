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

	// Event handlers, override to handle events
	void onTouchEvent(TouchEvent *event) override;

	virtual void onPress(TouchEvent *event){};
	virtual void onRelease(TouchEvent *event){};
	virtual void onTap(TouchEvent *event){};
	virtual void onLongPress(TouchEvent *event){};
	// virtual void onDoubleTap(TouchEvent *event) = 0;
	// virtual void onDrag(DragEvent *event) = 0;
	// virtual void onDrop(DragEvent *event) = 0;

   protected:
	bool isFocused = false;
};

}  // namespace Graphene

#endif	// GRAPHENE_WIDGET_INTERFACE_H
