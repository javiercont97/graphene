#if !defined(GRAPHENE_DRIVER_INTERFACE_H)
#define GRAPHENE_DRIVER_INTERFACE_H

#include "../core/Color.h"
#include "../core/String.h"
#include "../math/Point.h"

namespace Graphene {

// Interface for canvas classes, which are responsible for rendering to the screen
// or to an image buffer. The canvas class should be able to draw lines, rectangles,
// circles, and text.
class AbstractCanvas {
   public:
	// Constructors and destructor
	AbstractCanvas();
	AbstractCanvas(uint32_t width, uint32_t height);
	virtual ~AbstractCanvas();

	//=====================================================
	// Drawing functions
	//=====================================================
	/**
	 * @brief Draw a pixel at a given point (x, y) with a given color.
	 *
	 * @param point
	 */
	virtual void drawPixel(Graphene::Point point, Graphene::Color color) = 0;

	/**
	 * @brief Draw a line between two points p0 and p1 with a given color.
	 *
	 * @param start
	 * @param end
	 */
	virtual void drawLine(Graphene::Point start, Graphene::Point end, Graphene::Color color) = 0;

	/**
	 * @brief Draw a rectangle with a given position, width, height.
	 *
	 * @param position
	 * @param width
	 * @param height
	 */
	virtual void drawRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) = 0;

	/**
	 * @brief Fill a rectangle with a given position, width, height.
	 *
	 * @param position
	 * @param width
	 * @param height
	 */
	virtual void fillRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) = 0;

	/**
	 * @brief Draw a circle with a given center, radius.
	 *
	 * @param center
	 * @param radius
	 */
	virtual void drawCircle(Graphene::Point center, int32_t radius, Graphene::Color color) = 0;

	/**
	 * @brief Fill a circle with a given center, radius.
	 *
	 * @param center
	 * @param radius
	 */
	virtual void fillCircle(Graphene::Point center, int32_t radius, Graphene::Color color) = 0;

	/**
	 * @brief Draw a polygon with a given list of points.
	 *
	 * @param points
	 */
	virtual void drawPolygon(std::vector<Graphene::Point> points, Graphene::Color color) = 0;

	/**
	 * @brief Fill a polygon with a given list of points.
	 *
	 * @param points
	 */
	virtual void fillPolygon(std::vector<Graphene::Point> points, Graphene::Color color) = 0;

	/**
	 * @brief Draw a string at a given position.
	 *
	 * @param position
	 * @param text
	 */
	virtual void drawString(Graphene::Point position, String text, Graphene::Color color) = 0;

	/**
	 * @brief Clear the screen with background color.
	 *
	 * @param color
	 */
	virtual void clear(Graphene::Color color) = 0;

	// TODO: Add more drawing functions
	// TODO: Add more text functions
	// TODO: Add more image functions

	//=====================================================
	// Getters and setters
	//=====================================================
	uint32_t getWidth() const;
	uint32_t getHeight() const;

   protected:
	// display geometry
	uint32_t width;
	uint32_t height;
};
}  // namespace Graphene

#endif	// GRAPHENE_DRIVER_INTERFACE_H
