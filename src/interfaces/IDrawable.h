#if !defined(GRAPHENE_DRAWABLE_INTERFACE_H)
#define GRAPHENE_DRAWABLE_INTERFACE_H

// #include "../core/Object.h"
#include "../events/TouchEvent.h"
#include "../math/Rect.h"
#include "AbstractCanvas.h"

namespace Graphene {

// Placeholder layout interface to avoid circular dependencies
class IContainer;

class IDrawable {
   public:
	IDrawable(IContainer *parent = nullptr) : parent(parent) {
	}

	IDrawable(Rect bounds, IContainer *parent = nullptr) : parent(parent), bounds(bounds) {
	}

	Rect getBounds() const {
		return bounds;
	}

	virtual void setBounds(Rect bounds) {
		this->bounds = bounds;
	}

	uint8_t getStretchX() const {
		return stretchX;
	}

	virtual void setStretchX(uint8_t stretchX) {
		this->stretchX = stretchX;
	}

	uint8_t getStretchY() const {
		return stretchY;
	}

	virtual void setStretchY(uint8_t stretchY) {
		this->stretchY = stretchY;
	}

	virtual void draw(AbstractCanvas &canvas) = 0;

	// Event handlers
	virtual void onTouchEvent(TouchEvent *event) = 0;

   protected:
	IContainer *parent;
	Rect bounds;

	// Stretch factors, used as layout hints/polices
	uint8_t stretchX = 1;
	uint8_t stretchY = 1;
};

}  // namespace Graphene

#endif	// GRAPHENE_DRAWABLE_INTERFACE_H
