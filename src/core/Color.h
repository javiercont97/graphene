#if !defined(GRAPHENE_COLOR_H)
#define GRAPHENE_COLOR_H

#include <stdint.h>

namespace Graphene {
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

   private:
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};
}  // namespace Graphene

#endif	// GRAPHENE_COLOR_H
