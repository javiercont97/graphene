#if !defined(GRAPHENE_COLOR_H)
#define GRAPHENE_COLOR_H

#include <stdint.h>

namespace Graphene {
enum class PixelFormat { RGBA8888, ARGB8888, RGB565, RGB888, GRAY8 };

class Color {
   public:
	Color();
	Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 255);
	Color(const Color &color);

	// copy assignment operator
	Color &operator=(const Color &color);
	Color &operator=(const uint32_t &color);

	// comparison operators
	bool operator==(const Color &color) const;
	bool operator!=(const Color &color) const;

	// conversion operators
	operator uint32_t() const;

	// getters and setters
	uint8_t getRed() const;
	uint8_t getGreen() const;
	uint8_t getBlue() const;
	uint8_t getAlpha() const;

	void setRed(uint8_t red);
	void setGreen(uint8_t green);
	void setBlue(uint8_t blue);
	void setAlpha(uint8_t alpha);

	// pixel format conversion
	uint32_t toRGBA8888() const;
	void fromRGBA8888(uint32_t color);

	uint32_t toARGB8888() const;
	void fromARGB8888(uint32_t color);

	uint16_t toRGB565() const;
	void fromRGB565(uint16_t color);

	uint32_t toRGB888() const;
	void fromRGB888(uint32_t color);

	uint8_t toGray8() const;
	void fromGray8(uint8_t color);

	uint32_t toFormat(PixelFormat format) const;
	void fromFormat(uint32_t color, PixelFormat format);

   private:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};

// Default colors
const Color BLACK = Color(0, 0, 0);
const Color WHITE = Color(255, 255, 255);
const Color RED = Color(255, 0, 0);
const Color GREEN = Color(0, 255, 0);
const Color BLUE = Color(0, 0, 255);
const Color YELLOW = Color(255, 255, 0);
const Color CYAN = Color(0, 255, 255);
const Color MAGENTA = Color(255, 0, 255);
const Color GRAY = Color(128, 128, 128);
const Color LIGHT_GRAY = Color(192, 192, 192);
const Color DARK_GRAY = Color(64, 64, 64);
const Color TRANSPARENT = Color(0, 0, 0, 0);

const Color ORANGE = Color(255, 165, 0);
const Color PINK = Color(255, 192, 203);
const Color PURPLE = Color(128, 0, 128);
const Color BROWN = Color(165, 42, 42);
const Color OLIVE = Color(128, 128, 0);
const Color TEAL = Color(0, 128, 128);
const Color NAVY = Color(0, 0, 128);

const Color LIME = Color(0, 255, 0);
const Color MAROON = Color(128, 0, 0);
const Color AQUA = Color(0, 255, 255);
const Color FUCHSIA = Color(255, 0, 255);
const Color SILVER = Color(192, 192, 192);
const Color LIME_GREEN = Color(50, 205, 50);
// const Color DARK_GREEN = Color(0, 100, 0);
// const Color DARK_BLUE = Color(0, 0, 139);
// const Color DARK_RED = Color(139, 0, 0);
// const Color DARK_YELLOW = Color(139, 139, 0);
// const Color DARK_CYAN = Color(0, 139, 139);
// const Color DARK_MAGENTA = Color(139, 0, 139);
// const Color DARK_ORANGE = Color(255, 140, 0);
// const Color DARK_PINK = Color(255, 20, 147);
// const Color DARK_PURPLE = Color(148, 0, 211);
// const Color DARK_BROWN = Color(101, 67, 33);
// const Color DARK_OLIVE = Color(85, 107, 47);
// const Color DARK_TEAL = Color(0, 128, 128);
// const Color DARK_NAVY = Color(0, 0, 128);
// const Color LIGHT_GREEN = Color(144, 238, 144);
}  // namespace Graphene

#endif	// GRAPHENE_COLOR_H
