#if !defined(GRAPHENE_RECTANGLE_H)
#define GRAPHENE_RECTANGLE_H

#include <stdint.h>

#include "../core/Color.h"
#include "../core/Point.h"
#include "Shape.h"

namespace Graphene {
class Rectangle : public Shape {
   public:
	Rectangle();
	Rectangle(Graphene::Point position, uint32_t width, uint32_t height);
	Rectangle(const Rectangle& rectangle);
	~Rectangle();

	Rectangle& operator=(const Rectangle& rectangle);

	void draw() override;

	void move(int x, int y) override;

	void rotate(int angle) override;

	void scale(float factor) override;

   private:
	Point position;
	uint32_t width;
	uint32_t height;
};

}  // namespace Graphene

#endif	// GRAPHENE_RECTANGLE_H
