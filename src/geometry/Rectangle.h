// #if !defined(GRAPHENE_RECTANGLE_H)
// #define GRAPHENE_RECTANGLE_H

// #include <stdint.h>

// #include "../core/Color.h"
// #include "../core/Point.h"
// #include "Shape.h"

// namespace Graphene {
// class Rectangle : public Shape {
//    public:
// 	Rectangle();
// 	Rectangle(Graphene::Point position, uint32_t width, uint32_t height,
// 			  Color fillColor, Color strokeColor);

// 	Rectangle& operator=(const Rectangle& rectangle);

// 	void getBoundingBox(Point& topLeft, Point& bottomRight) override;
// 	void scale(double factor) override;
// 	void draw(ScreenDriver* driver) override;

//    private:
// };

// }  // namespace Graphene

// #endif	// GRAPHENE_RECTANGLE_H
