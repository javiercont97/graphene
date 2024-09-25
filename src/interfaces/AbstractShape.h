#if !defined(GRAPHENE_DRAWING_PRIMITIVE_INTERFACE_H)
#define GRAPHENE_DRAWING_PRIMITIVE_INTERFACE_H

#include "../core/Color.h"
#include "../math/Point.h"
#include "../math/Rect.h"

class AbstractShape {
   private:
   public:
	AbstractShape();
	~AbstractShape();

	Graphene::Rect getBounds() const;
	void setBounds(Graphene::Rect bounds);
	Graphene::Color getFillColor() const;
	void setFillColor(Graphene::Color color);
	Graphene::Color getStrokeColor() const;
	void setStrokeColor(Graphene::Color color);
	uint8_t getStrokeWidth() const;
	void setStrokeWidth(uint8_t width);
};

#endif	// GRAPHENE_DRAWING_PRIMITIVE_INTERFACE_H
