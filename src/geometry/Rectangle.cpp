// #include "Rectangle.h"

// Graphene::Rectangle::Rectangle() : Shape() {}

// Graphene::Rectangle::Rectangle(Graphene::Point position, uint32_t width,
// 							   uint32_t height, Color fillColor,
// 							   Color strokeColor)
// 	: Shape(position, width, height, fillColor, strokeColor) {}

// Graphene::Rectangle& Graphene::Rectangle::operator=(
// 	const Rectangle& rectangle) {
// 	if (this != &rectangle) {
// 		position = rectangle.position;
// 		width = rectangle.width;
// 		height = rectangle.height;
// 		fillColor = rectangle.fillColor;
// 		strokeColor = rectangle.strokeColor;
// 		strokeWeight = rectangle.strokeWeight;
// 	}

// 	return *this;
// }

// void Graphene::Rectangle::getBoundingBox(Point& topLeft, Point& bottomRight) {
// 	topLeft = position;
// 	bottomRight = position + Point(width, height);
// }

// void Graphene::Rectangle::scale(double factor) {
// 	width *= factor;
// 	height *= factor;
// }

// void Graphene::Rectangle::draw(ScreenDriver* driver) {
// 	driver->setForegroundColor(strokeColor);
// 	driver->fillRectangle(position, width, height);
// 	// compute the position of the top left corner of the rectangle
// 	// according to the stroke weight
// 	Point topLeft = position + Point(strokeWeight, strokeWeight);
// 	// compute the width and height of the rectangle
// 	// according to the stroke weight
// 	uint32_t rectWidth = width - 2 * strokeWeight;
// 	uint32_t rectHeight = height - 2 * strokeWeight;
// 	driver->setForegroundColor(fillColor);
// 	driver->fillRectangle(topLeft, rectWidth, rectHeight);
// }
