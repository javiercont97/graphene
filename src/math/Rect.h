#if !defined(GRAPHENE_RECT_H)
#define GRAPHENE_RECT_H

#include <stdint.h>

#include "Point.h"

namespace Graphene {

// Rect must have a constraint on the coordinates
// Point p1 must be always the top-left corner
class Rect {
   public:
	Rect();

	Rect(int32_t x, int32_t y, uint32_t width, uint32_t height);

	Rect(Point p, uint32_t width, uint32_t height);

	// Getters and setters
	int32_t getX() const;

	int32_t getY() const;

	int32_t getWidth() const;

	int32_t getHeight() const;

	void setX(int32_t x);

	void setY(int32_t y);

	void setWidth(uint32_t width);

	void setHeight(uint32_t height);

	Point getTopLeft() const;
	Point getTopRight() const;
	Point getBottomRight() const;
	Point getBottomLeft() const;
	Point getCenter() const;

	void setTopLeft(Point p);

	// Check if a point is inside the rectangle
	bool contains(Point p) const;

	// Check if a rectangle is inside the rectangle
	bool contains(Rect r) const;

   private:
	Point p;
	uint32_t width;
	uint32_t height;
};

}  // namespace Graphene

#endif	// GRAPHENE_RECT_H
