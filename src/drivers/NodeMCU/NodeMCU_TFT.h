#if defined(ENABLE_NODEMCU_DRIVERS)

#if !defined(GRAPHENE_NODE_MCU_TFT_DRIVER_H)
#define GRAPHENE_NODE_MCU_TFT_DRIVER_H

#include <Adafruit_ST7735.h>
#include <Arduino.h>
#include <SPI.h>

#include "../../core/Color.h"
#include "../../core/Font.h"
#include "../../core/GrapheneFonts.h"
#include "../../core/String.h"
#include "../../math/Point.h"

namespace Graphene {

class AdafruitST7735 {
   public:
	/**
	 * @brief Construct a new Adafruit ST7735 display driver for Graphene
	 *
	 * @param width
	 * @param height
	 * @param TFT_CS Chip Select pin
	 * @param TFT_DC Data/Command pin (AKA Register Select pin/A0 pin)
	 * @param TFT_RST Reset pin
	 */
	AdafruitST7735(uint32_t width, uint32_t height, uint8_t TFT_CS, uint8_t TFT_DC, uint8_t TFT_RST)
		: Graphene::AbstractCanvas(width, height) {
		tft = new Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
	}

	//=====================================================
	// Drawing functions
	//=====================================================
	void drawPixel(Graphene::Point point, Graphene::Color color) {
		tft->drawPixel(point.getX(), point.getY(), color.to565());
	}

	void drawLine(Graphene::Point start, Graphene::Point end, Graphene::Color color) {
		tft->drawLine(start.getX(), start.getY(), end.getX(), end.getY(), color.to565());
	}

	void drawRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) {
		tft->drawRect(position.getX(), position.getY(), width, height, color.to565());
	}

	void fillRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) {
		tft->fillRect(position.getX(), position.getY(), width, height, color.to565());
	}

	void drawCircle(Graphene::Point center, int32_t radius, Graphene::Color color) {
		tft->drawCircle(center.getX(), center.getY(), radius, color.to565());
	}

	void fillCircle(Graphene::Point center, int32_t radius, Graphene::Color color) {
		tft->fillCircle(center.getX(), center.getY(), radius, color.to565());
	}

	/**
	 * @brief Draw a polygon with a given list of points.
	 *
	 * @param points
	 */
	void drawPolygon(std::vector<Graphene::Point> points, Graphene::Color color) {
		// Convert vector of Graphene::Point to Adafruit GFX Point
		std::vector<Adafruit_GFX::Point> adafruitPoints;
		for (Graphene::Point point : points) {
			adafruitPoints.push_back(Adafruit_GFX::Point(point.getX(), point.getY()));
		}

		// tft->drawPolygon(adafruitPoints.data(), adafruitPoints.size(), color.to565());

		for (int i = 0; i < adafruitPoints.size(); i++) {
			tft->drawLine(adafruitPoints[i].x,
						  adafruitPoints[i].y,
						  adafruitPoints[(i + 1) % adafruitPoints.size()].x,
						  adafruitPoints[(i + 1) % adafruitPoints.size()].y,
						  color.to565());
		}
		tft->drawLine(adafruitPoints[0].x,
					  adafruitPoints[0].y,
					  adafruitPoints[adafruitPoints.size() - 1].x,
					  adafruitPoints[adafruitPoints.size() - 1].y,
					  color.to565());
	}

	/**
	 * @brief Fill a polygon with a given list of points.
	 *
	 * @param points
	 */
	void fillPolygon(std::vector<Graphene::Point> points, Graphene::Color color) {
		// Convert vector of Graphene::Point to Adafruit GFX Point
		std::vector<Adafruit_GFX::Point> adafruitPoints;
		for (Graphene::Point point : points) {
			adafruitPoints.push_back(Adafruit_GFX::Point(point.getX(), point.getY()));
		}

		tft->fillPolygon(adafruitPoints.data(), adafruitPoints.size(), color.to565());
	}

	/**
	 * @brief Draw a string at a given position.
	 *
	 * @param position
	 * @param text
	 */
	void drawString(Graphene::Point position,
					String text,
					Graphene::Color color,
					Graphene::Color bgColor,
					Font font,
					TextAlignment align = TextAlignment::CENTER) {
		tft->setCursor(position.getX(), position.getY());
		tft->setTextColor(color.to565(), bgColor.to565());
		tft->setTextSize(font.size);
		tft->setTextWrap(true);
		tft->print(text);
		// TODO: Convert Graphene::Font to Adafruit GFX Font
		// tft->setFont(&gfxFont);
	}

	/**
	 * @brief Clear the screen with background color.
	 *
	 * @param color
	 */
	void clear(Graphene::Color color) {
		tft->fillScreen(color.to565());
	}

   protected:
	// display geometry
	Adafruit_ST7735 *tft;
};

}  // namespace Graphene

#endif	// GRAPHENE_NODE_MCU_TFT_DRIVER_H

#endif	// ENABLE_NODEMCU_DRIVERS
