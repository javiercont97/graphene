#if !defined(GRAPHENE_SHAPE_H)
#define GRAPHENE_SHAPE_H

#include <math.h>
#include <stdint.h>

#include "../core/Point.h"
#include "../core/String.h"

namespace Graphene {
class Shape {
   public:
	virtual void draw() = 0;

	virtual void move(int x, int y) = 0;

	virtual void rotate(int angle) = 0;

	virtual void scale(float factor) = 0;

   private:
	Point position;
	uint32_t width;
	uint32_t height;
};

}  // namespace Graphene

#endif	// GRAPHENE_SHAPE_H
