#if !defined(GRAPHENE_SCREEN_DRIVER_H)
#define GRAPHENE_SCREEN_DRIVER_H

#include <math.h>
#include <stdint.h>

#include <vector>

#include "../core/Color.h"
#include "../core/Point.h"
#include "../core/String.h"
#include "FrameBuffer.h"

namespace Graphene {
/**
 * @brief Class to draw on a virtual screen.
 * Uses FrameBuffer to store the dual buffer.
 * This class is used to draw on a virtual screen
 * and swap the display buffer to display the final frame
 *
 * Actual display drivers can use this to manipulate the frame buffers
 * but should copy the final frame to the display hardware themselves
 *
 * Similar to the virtual DOM in react.js where the virtual screen
 * is the virtual DOM and the hardware display is the actual DOM
 *
 */
class VirtualScreenDriver {
   public:
	VirtualScreenDriver(uint32_t width, uint32_t height);
	virtual ~VirtualScreenDriver();

	//======================== Drawing functions ========================
	/**
	 * @brief Draw a pixel at a given point (x, y) with a given color.
	 *
	 * @param point
	 */
	void drawPixel(Graphene::Point point);

	/**
	 * @brief Draw a line between two points p0 and p1 with a given color.
	 *
	 * @param start
	 * @param end
	 */
	void drawLine(Graphene::Point start, Graphene::Point end);

	/**
	 * @brief Draw a rectangle with a given position, width, height.
	 *
	 * @param position
	 * @param width
	 * @param height
	 */
	void drawRectangle(Graphene::Point position,
					   uint32_t width,
					   uint32_t height);

	/**
	 * @brief Fill a rectangle with a given position, width, height.
	 *
	 * @param position
	 * @param width
	 * @param height
	 */
	void fillRectangle(Graphene::Point position,
					   uint32_t width,
					   uint32_t height);

	/**
	 * @brief Draw a circle with a given center, radius.
	 *
	 * @param center
	 * @param radius
	 */
	void drawCircle(Graphene::Point center, uint32_t radius);

	/**
	 * @brief Fill a circle with a given center, radius.
	 *
	 * @param center
	 * @param radius
	 */
	void fillCircle(Graphene::Point center, uint32_t radius);

	/**
	 * @brief Draw a polygon with a given list of points.
	 *
	 * @param points
	 */
	void drawPolygon(std::vector<Graphene::Point> points);

	/**
	 * @brief Fill a polygon with a given list of points.
	 *
	 * @param points
	 */
	void fillPolygon(std::vector<Graphene::Point> points);

	/**
	 * @brief Draw a string at a given position.
	 *
	 * @param position
	 * @param text
	 */
	void drawString(Graphene::Point position, String text);

	/**
	 * @brief Clear the screen with a given color.
	 *
	 * @param color
	 */
	void clearScreen(Color color);

	//======================== Display functions ========================
	/**
	 * @brief Swap the display buffer.
	 * This function is used to swap the display buffer
	 * resulting in the current frame being displayed on the screen
	 * and the next frame being drawn on the other buffer
	 * This function should be called after all drawing functions
	 * have been called to display the final frame
	 * on the screen
	 *
	 * Equivalent to flushing the display buffer
	 *
	 * This function should be implemented by the display driver
	 * to swap the display buffer because the implementation
	 * is dependent on the display hardware (e.g. SPI, I2C, HDMI, DSI)
	 */
	virtual void swapBuffers();

	/**
	 * @brief Get the current display buffer.
	 * This function is used to get the current display buffer
	 * resulting in the current frame being returned
	 *
	 * @return FrameBuffer
	 */
	Graphene::FrameBuffer getCurrentFrame();

	//======================== Getters and Setters ========================
	void setForegroundColor(Color color);
	void setBackgroundColor(Color color);
	Color getForegroundColor() const;
	Color getBackgroundColor() const;
	uint32_t getWidth() const;
	uint32_t getHeight() const;
	uint8_t currentFrameIndex() const;

   private:
	// display geometry
	uint32_t width;
	uint32_t height;

	// display colors
	Color foregroundColor;
	Color backgroundColor;

	// display buffer
	std::vector<Graphene::FrameBuffer> frames;
	uint8_t currentFrame;
};

}  // namespace Graphene

#endif	// GRAPHENE_SCREEN_DRIVER_H
