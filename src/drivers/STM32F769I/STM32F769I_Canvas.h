#if defined(ENABLE_STM32F769I_DRIVERS)

#if !defined(GRAPHENE_STM32F769I_TOUCHSCREEN_DRIVER_H)
#define GRAPHENE_STM32F769I_TOUCHSCREEN_DRIVER_H

#include <stdint.h>
#include <stm32f769i_discovery.h>
#include <stm32f769i_discovery_lcd.h>

namespace Graphene {

class STM32F769I_Canvas : public Graphene::AbstractCanvas {
   public:
	// constructor
	STM32F769I_Canvas() : AbstractCanvas(BSP_LCD_GetXSize(), BSP_LCD_GetYSize()) {
		BSP_LCD_Init();

		// this->mainFrameBuffer = LCD_FB_START_ADDRESS;
		// this->alternateFrameBuffer =
		// 	LCD_FB_START_ADDRESS + (this->getWidth() * this->getHeight() * 4);

		// set layer addresses
		BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);
		BSP_LCD_SelectLayer(LTDC_LAYER_1);

		// default font
		BSP_LCD_SetFont(&Font24);

		// clear screen
		BSP_LCD_SetBackColor(Graphene::WHITE);
		BSP_LCD_Clear(Graphene::WHITE);
	}

	//=========================================================================
	// Implement inherited pure virtual functions from Graphene::AbstractCanvas
	//=========================================================================

	void drawPixel(Graphene::Point position, Graphene::Color color) override {
		BSP_LCD_DrawPixel((uint16_t)position.getX(), (uint16_t)position.getY(), color);
	}

	void drawLine(Graphene::Point start, Graphene::Point end, Graphene::Color color) override {
		BSP_LCD_SetBackColor(Graphene::TRANSPARENT);
		BSP_LCD_SetTextColor(color);

		BSP_LCD_DrawLine((uint16_t)start.getX(), (uint16_t)start.getY(), (uint16_t)end.getX(), (uint16_t)end.getY());
	}

	void drawRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) override {
		BSP_LCD_SetBackColor(Graphene::TRANSPARENT);
		BSP_LCD_SetTextColor(color);

		BSP_LCD_DrawRect((uint16_t)position.getX(), (uint16_t)position.getY(), width, height);
	}

	void fillRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) override {
		BSP_LCD_SetBackColor(Graphene::TRANSPARENT);
		BSP_LCD_SetTextColor(color);

		BSP_LCD_FillRect((uint16_t)position.getX(), (uint16_t)position.getY(), width, height);
	}

	void drawCircle(Graphene::Point center, int32_t radius, Graphene::Color color) override {
		BSP_LCD_SetBackColor(Graphene::TRANSPARENT);
		BSP_LCD_SetTextColor(color);

		BSP_LCD_DrawCircle((uint16_t)center.getX(), (uint16_t)center.getY(), radius);
	}

	void fillCircle(Graphene::Point center, int32_t radius, Graphene::Color color) override {
		BSP_LCD_SetBackColor(Graphene::TRANSPARENT);
		BSP_LCD_SetTextColor(color);

		BSP_LCD_FillCircle((uint16_t)center.getX(), (uint16_t)center.getY(), radius);
	}

	void drawPolygon(std::vector<Graphene::Point> points, Graphene::Color color) override {
		BSP_LCD_SetBackColor(Graphene::TRANSPARENT);
		BSP_LCD_SetTextColor(color);

		pPoint corners = new Point[points.size()];
		for (std::size_t i = 0; i < points.size(); i++) {
			corners[i].X = points[i].getX();
			corners[i].Y = points[i].getY();
		}
		BSP_LCD_DrawPolygon(corners, points.size());

		delete[] corners;
	}

	void fillPolygon(std::vector<Graphene::Point> points, Graphene::Color color) override {
		BSP_LCD_SetBackColor(Graphene::TRANSPARENT);
		BSP_LCD_SetTextColor(color);

		pPoint corners = new Point[points.size()];
		for (std::size_t i = 0; i < points.size(); i++) {
			corners[i].X = points[i].getX();
			corners[i].Y = points[i].getY();
		}
		BSP_LCD_FillPolygon(corners, points.size());

		delete[] corners;
	}

	void drawString(Graphene::Point position,
					Graphene::String text,
					Graphene::Color color,
					Graphene::Color bgColor,
					Graphene::Font font,
					Graphene::TextAlignment alignment) override {
		BSP_LCD_SetBackColor(bgColor);
		BSP_LCD_SetTextColor(color);

		Graphene::Point textLeftCorner(position.getX() - text.length() * Font24.Width / 2,
									   position.getY() - Font24.Height / 2);

		BSP_LCD_DisplayStringAt((uint16_t)textLeftCorner.getX(),
								(uint16_t)textLeftCorner.getY(),
								(uint8_t *)text.cStyleString(),
								LEFT_MODE);

		// switch (alignment) {
		// 	case Graphene::TextAlignment::LEFT:
		// 		BSP_LCD_DisplayStringAt(
		// 			(uint16_t)position.getX(), (uint16_t)position.getY(),
		// (uint8_t *)text.c_str(), LEFT_MODE); 		break; 	case
		// Graphene::TextAlignment::CENTER: 		BSP_LCD_DisplayStringAt(
		// 			(uint16_t)position.getX(), (uint16_t)position.getY(),
		// (uint8_t *)text.c_str(), CENTER_MODE); 		break; 	case
		// Graphene::TextAlignment::RIGHT: 		BSP_LCD_DisplayStringAt(
		// 			(uint16_t)position.getX(), (uint16_t)position.getY(),
		// (uint8_t *)text.c_str(), RIGHT_MODE); 		break;
		// }
	}

	void clear(Graphene::Color color) override {
		BSP_LCD_Clear(color);
	}
};

}  // namespace Graphene

#endif	// GRAPHENE_STM32F769I_TOUCHSCREEN_DRIVER_H

#endif	// ENABLE_STM32F769I_DRIVERS
