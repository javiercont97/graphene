// #if !defined(GRAPHENE_SHAPE_H)
// #define GRAPHENE_SHAPE_H

// #include <math.h>
// #include <stdint.h>

// #include "../core/Point.h"
// #include "../core/String.h"
// #include "Constants.h"

// namespace Graphene {
// class Shape {
//    public:
// 	Shape();
// 	Shape(Graphene::Point position, uint32_t width, uint32_t height, Color
// fillColor, Color strokeColor);

// 	/**
// 	 * @brief Move the shape by the given speed
// 	 * This function is used to move the shape by the given speed
// 	 * resulting in a new position for the shape
// 	 * position = position + speed
// 	 *
// 	 * @param speed
// 	 */
// 	virtual void move(Graphene::Point speed);

// 	/**
// 	 * @brief Move the shape to the given position
// 	 * This function is used to move the shape to the given position
// 	 * resulting in a new position for the shape
// 	 *
// 	 * @param position
// 	 */
// 	virtual void moveTo(Graphene::Point position);

// 	/**
// 	 * @brief Scale the shape by the given factor
// 	 *
// 	 * @param factor
// 	 */
// 	virtual void scale(double factor) = 0;

// 	/**
// 	 * @brief Draw the shape on the screen
// 	 * This function is used to draw the shape on the screen
// 	 *
// 	 * @param driver
// 	 */
// 	// virtual void draw(ScreenDriver* driver) = 0;

// 	/**
// 	 * @brief Get the Bounding Box object
// 	 * This function is used to get the bounding box of the shape
// 	 * resulting in the top left and bottom right points of the bounding box
// 	 *
// 	 * Top left point is the point with the smallest x and y coordinates
// 	 * Bottom right point is the point with the largest x and y coordinates
// 	 *
// 	 * @param topLeft
// 	 * @param bottomRight
// 	 */
// 	virtual void getBoundingBox(Point& topLeft, Point& bottomRight) = 0;

// 	// getters and setters
// 	Point getPosition() const { return position; }
// 	void setPosition(Point position) { this->position = position; }

// 	uint32_t getWidth() const { return width; }
// 	void setWidth(uint32_t width) { this->width = width; }

// 	uint32_t getHeight() const { return height; }
// 	void setHeight(uint32_t height) { this->height = height; }

// 	Color getFillColor() const { return fillColor; }
// 	void setFillColor(Color fillColor) { this->fillColor = fillColor; }

// 	Color getStrokeColor() const { return strokeColor; }
// 	void setStrokeColor(Color strokeColor) { this->strokeColor = strokeColor; }

// 	uint32_t getStrokeWeight() const { return strokeWeight; }
// 	void setStrokeWeight(uint32_t strokeWeight) { this->strokeWeight =
// strokeWeight; }

//    protected:
// 	Point position;
// 	uint32_t width;
// 	uint32_t height;

// 	Color fillColor;
// 	Color strokeColor;

// 	uint32_t strokeWeight;
// };

// }  // namespace Graphene

// #endif	// GRAPHENE_SHAPE_H
