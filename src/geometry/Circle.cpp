// #include "Circle.h"

// Graphene::Circle::Circle(): Shape() {}

// Graphene::Circle::Circle(Point center, uint32_t radius, Color fillColor,
// 						 Color strokeColor): Shape(center, radius, radius,
// fillColor, strokeColor) {}

// Graphene::Circle& Graphene::Circle::operator=(const Circle& circle) {
// 	if (this != &circle) {
// 		position = circle.position;
// 		width = circle.width;
// 		height = circle.height;
// 		fillColor = circle.fillColor;
// 		strokeColor = circle.strokeColor;
// 		strokeWeight = circle.strokeWeight;
// 	}

// 	return *this;
// }

// void Graphene::Circle::getBoundingBox(Point& topLeft, Point& bottomRight) {
// 	topLeft = position;
// 	bottomRight = position + Point(width, height);
// }

// void Graphene::Circle::scale(double factor) {
// 	width *= factor;
// 	height *= factor;
// }

// void Graphene::Circle::draw(ScreenDriver* driver) {
// 	// center of the circle
// 	Point center = this->position + Point(width/2, height/2);

// 	driver->setForegroundColor(strokeColor);
// 	driver->fillCircle(center, width/2);
// 	// compute inner radius
// 	uint32_t innerRadius = width/2 - strokeWeight;
// 	driver->setForegroundColor(fillColor);
// 	driver->fillCircle(center, innerRadius);
// }
