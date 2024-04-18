#if !defined(GRAPHENE_SCREEN_DRIVER_H)
#define GRAPHENE_SCREEN_DRIVER_H

#include <stdint.h>

#include <vector>

#include "Color.h"
#include "Point.h"
#include "String.h"

namespace Graphene {
// enum class Orientation { LANDSCAPE, PORTRAIT };

class ScreenDriver {
   public:
	/**
	 * @brief Get the screen height in pixels
	 * Subclasses must implement this method calling the actual hardware display
	 * underlying library.
	 *
	 * For example:
	 * return BSP_LCD_GetYSize();
	 *
	 * @return uint32_t
	 */
	virtual uint32_t getHeight() const = 0;

	/**
	 * @brief Get the screen width in pixels
	 * Subclasses must implement this method calling the actual hardware display
	 * underlying library.
	 *
	 * For example:
	 * return BSP_LCD_GetXSize();
	 *
	 * @return uint32_t
	 */
	virtual uint32_t getWidth() const = 0;

	//=========================================================================
	// Drawing methods
	//=========================================================================

	/**
	 * @brief Set the foreground color for drawing operations.
	 *
	 */
	virtual void setForegroundColor(Color color) = 0;

	/**
	 * @brief Set the background color for drawing operations.
	 *
	 */
	virtual void setBackgroundColor(Color color) = 0;

	/**
	 * @brief Draw a pixel at a given point (x, y) with a given color.
	 *
	 * @param point
	 */
	virtual void drawPixel(Graphene::Point point) = 0;

	/**
	 * @brief Draw a line between two points p0 and p1 with a given color.
	 *
	 * @param start
	 * @param end
	 */
	virtual void drawLine(Graphene::Point start, Graphene::Point end) = 0;

	/**
	 * @brief Draw a rectangle with a given position, width, height.
	 *
	 * @param position
	 * @param width
	 * @param height
	 */
	virtual void drawRectangle(Graphene::Point position, uint32_t width,
							   uint32_t height) = 0;

	/**
	 * @brief Fill a rectangle with a given position, width, height.
	 *
	 * @param position
	 * @param width
	 * @param height
	 */
	virtual void fillRectangle(Graphene::Point position, uint32_t width,
							   uint32_t height) = 0;

	/**
	 * @brief Draw a circle with a given center, radius.
	 *
	 * @param center
	 * @param radius
	 */
	virtual void drawCircle(Graphene::Point center, uint32_t radius) = 0;

	/**
	 * @brief Fill a circle with a given center, radius.
	 *
	 * @param center
	 * @param radius
	 */
	virtual void fillCircle(Graphene::Point center, uint32_t radius) = 0;

	/**
	 * @brief Draw a polygon with a given list of points.
	 *
	 * @param points
	 */
	virtual void drawPolygon(std::vector<Graphene::Point> points) = 0;

	/**
	 * @brief Fill a polygon with a given list of points.
	 *
	 * @param points
	 */
	virtual void fillPolygon(std::vector<Graphene::Point> points) = 0;

	/**
	 * @brief Draw a string at a given position.
	 *
	 * @param position
	 * @param text
	 */
	virtual void drawString(Graphene::Point position, String text) = 0;

	/**
	 * @brief Clear the screen with a given color.
	 *
	 * @param color
	 */
	virtual void clearScreen(Color color) = 0;

	// virtual void drawBitmap(Graphene::Point position, uint32_t width,
	// 						uint32_t height, const uint8_t *bitmap) = 0;

	//=========================================================================
	// Display methods
	//=========================================================================

	/**
	 * @brief Sleep the display. This method should put the display into a
	 * low-power mode or turn it off.
	 *
	 */
	virtual void sleep() = 0;

	/**
	 * @brief Wake the display. This method should wake the display from a
	 * low-power mode or turn it on.
	 *
	 */
	virtual void wake() = 0;

	/**
	 * @brief Enable the display backlight.
	 *
	 */
	virtual void enableBacklight() = 0;

	/**
	 * @brief Disable the display backlight.
	 *
	 */
	virtual void disableBacklight() = 0;

	/**
	 * @brief Set the display brightness.
	 *
	 */
	virtual void setBrightness(uint8_t brightness) = 0;

	// TODO: font, orientation and screen rotation methods

   private:
	// uint32_t width;
	// uint32_t height;
	// uint32_t *buffer;
	// PixelFormat pixelFormat;
};

}  // namespace Graphene

#endif	// GRAPHENE_SCREEN_DRIVER_H
