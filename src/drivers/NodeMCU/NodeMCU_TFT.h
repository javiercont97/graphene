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
#include "../../interfaces/AbstractCanvas.h"
#include "../../math/Point.h"

namespace Graphene {

class AdafruitST7735 : public Graphene::AbstractCanvas {
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
		tft->initR(INITR_144GREENTAB);
		tft->setRotation(0);
		tft->fillScreen(Graphene::BLACK.toRGB565());
	}

	//=====================================================
	// Drawing functions
	//=====================================================
	void drawPixel(Graphene::Point point, Graphene::Color color) {
		tft->drawPixel(point.getX(), point.getY(), color.toRGB565());
	}

	void drawLine(Graphene::Point start, Graphene::Point end, Graphene::Color color) {
		tft->drawLine(start.getX(), start.getY(), end.getX(), end.getY(), color.toRGB565());
	}

	void drawRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) {
		tft->drawRect(position.getX(), position.getY(), width, height, color.toRGB565());
	}

	void fillRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) {
		tft->fillRect(position.getX(), position.getY(), width, height, color.toRGB565());
	}

	void drawCircle(Graphene::Point center, int32_t radius, Graphene::Color color) {
		tft->drawCircle(center.getX(), center.getY(), radius, color.toRGB565());
	}

	void fillCircle(Graphene::Point center, int32_t radius, Graphene::Color color) {
		tft->fillCircle(center.getX(), center.getY(), radius, color.toRGB565());
	}

	/**
	 * @brief Draw a polygon with a given list of points.
	 *
	 * @param points
	 */
	void drawPolygon(std::vector<Graphene::Point> points, Graphene::Color color) {
		for (size_t i = 0; i < points.size() - 1; i++) {
			this->drawLine(points[i], points[i + 1], color);
		}
		this->drawLine(points[points.size() - 1], points[0], color);
	}

	/**
	 * @brief Fill a polygon with a given list of points.
	 *
	 * @param points
	 */
	void fillPolygon(std::vector<Graphene::Point> points, Graphene::Color color) {
		// Find the bounding box of the polygon
		int32_t minX = points[0].getX();
		int32_t minY = points[0].getY();
		int32_t maxX = points[0].getX();
		int32_t maxY = points[0].getY();

		for (size_t i = 1; i < points.size(); i++) {
			if (points[i].getX() < minX) {
				minX = points[i].getX();
			}
			if (points[i].getY() < minY) {
				minY = points[i].getY();
			}
			if (points[i].getX() > maxX) {
				maxX = points[i].getX();
			}
			if (points[i].getY() > maxY) {
				maxY = points[i].getY();
			}
		}

		// Check if a point is inside the polygon
		auto isInside = [&points](Graphene::Point point) {
			bool isInside = false;
			for (size_t i = 0, j = points.size() - 1; i < points.size(); j = i++) {
				if (((points[i].getY() > point.getY()) != (points[j].getY() > point.getY()))
					&& (point.getX() < (points[j].getX() - points[i].getX()) * (point.getY() - points[i].getY())
											   / (points[j].getY() - points[i].getY())
										   + points[i].getX())) {
					isInside = !isInside;
				}
			}
			return isInside;
		};

		for (int32_t y = minY; y <= maxY; y++) {
			for (int32_t x = minX; x <= maxX; x++) {
				if (isInside({x, y})) {
					this->drawPixel({x, y}, color);
				}
			}
		}
	}

	/**
	 * @brief Draw a string at a given position.
	 *
	 * @param position
	 * @param text
	 */
	void drawString(Graphene::Rect frame,
					String text,
					Graphene::Color color,
					Graphene::Color bgColor,
					Font font,
					TextAlignment align = TextAlignment::CENTER) {
		int16_t spacing = font.getHeight();
		int16_t textWidthInPixels = text.length() * (font.getWidth() + spacing) - spacing;
		int32_t x = position.getX() - textWidthInPixels / 2;
		tft->setCursor((int16_t)x, (int16_t)position.getY() - font.getWidth() / 2);
		tft->setTextColor(color.toRGB565(), bgColor.toRGB565());
		tft->setTextSize(font.getHeight());
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
		tft->fillScreen(color.toRGB565());
	}

   protected:
	// display geometry
	Adafruit_ST7735 *tft;
};

}  // namespace Graphene

#endif	// GRAPHENE_NODE_MCU_TFT_DRIVER_H

#endif	// ENABLE_NODEMCU_DRIVERS
