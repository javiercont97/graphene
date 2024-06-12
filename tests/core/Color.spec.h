#include <Graphene.h>
#include <unity/unity.h>

void testColor(void) {
	Graphene::Color color;
	TEST_ASSERT_EQUAL(0, color.getRed());
	TEST_ASSERT_EQUAL(0, color.getGreen());
	TEST_ASSERT_EQUAL(0, color.getBlue());
	TEST_ASSERT_EQUAL(255, color.getAlpha());

	Graphene::Color color2(255, 0, 0, 255);
	TEST_ASSERT_EQUAL(255, color2.getAlpha());
	TEST_ASSERT_EQUAL(255, color2.getRed());
	TEST_ASSERT_EQUAL(0, color2.getGreen());
	TEST_ASSERT_EQUAL(0, color2.getBlue());

	Graphene::Color color3(color2);
	TEST_ASSERT_EQUAL(255, color3.getRed());
	TEST_ASSERT_EQUAL(0, color3.getGreen());
	TEST_ASSERT_EQUAL(0, color3.getBlue());
	TEST_ASSERT_EQUAL(255, color3.getAlpha());

	Graphene::Color color4;
	color4 = color3;
	TEST_ASSERT_EQUAL(255, color4.getRed());
	TEST_ASSERT_EQUAL(0, color4.getGreen());
	TEST_ASSERT_EQUAL(0, color4.getBlue());
	TEST_ASSERT_EQUAL(255, color4.getAlpha());

	// Test assignment operator with uint32_t value
	// Color is in ARGB8888 format
	// 0xFF0000FF -> 255, 0, 0, 255
	Graphene::Color color5;
	color5 = 0xFF0000FF;
	TEST_ASSERT_EQUAL(255, color5.getAlpha());
	TEST_ASSERT_EQUAL(0, color5.getRed());
	TEST_ASSERT_EQUAL(0, color5.getGreen());
	TEST_ASSERT_EQUAL(255, color5.getBlue());

	// Test comparison operators
	TEST_ASSERT_TRUE(color2 == color3);
	TEST_ASSERT_TRUE(color2 != color);

	// Test conversion operators
	// Color is in ARGB8888 format
	TEST_ASSERT_EQUAL(0xFFFF0000, (uint32_t)color2);

	// Test getters and setters
	color.setRed(0);
	color.setGreen(255);
	color.setBlue(0);
	color.setAlpha(255);
	TEST_ASSERT_EQUAL(0, color.getRed());
	TEST_ASSERT_EQUAL(255, color.getGreen());
	TEST_ASSERT_EQUAL(0, color.getBlue());
	TEST_ASSERT_EQUAL(255, color.getAlpha());

	// Test pixel format conversion
	TEST_ASSERT_EQUAL(0xFF0000FF, color2.toRGBA8888());
	color2 = Graphene::Color::ColorFactory::fromRGBA8888(0xFF0000FF);
	TEST_ASSERT_EQUAL(255, color2.getRed());
	TEST_ASSERT_EQUAL(0, color2.getGreen());
	TEST_ASSERT_EQUAL(0, color2.getBlue());
	TEST_ASSERT_EQUAL(255, color2.getAlpha());

	TEST_ASSERT_EQUAL(0xFFFF0000, color2.toARGB8888());
	color2 = Graphene::Color::ColorFactory::fromARGB8888(0xFF0000FF);
	TEST_ASSERT_EQUAL(255, color2.getAlpha());
	TEST_ASSERT_EQUAL(0, color2.getRed());
	TEST_ASSERT_EQUAL(0, color2.getGreen());
	TEST_ASSERT_EQUAL(255, color2.getBlue());

	color2 = 0xffff0000;
	TEST_ASSERT_EQUAL(0xF800, color2.toRGB565());
	color2 = Graphene::Color::ColorFactory::fromRGB565(0xF800);
	TEST_ASSERT_EQUAL(255, color2.getRed());
	TEST_ASSERT_EQUAL(0, color2.getGreen());
	TEST_ASSERT_EQUAL(0, color2.getBlue());
	TEST_ASSERT_EQUAL(255, color2.getAlpha());

	TEST_ASSERT_EQUAL(0xFF0000, color2.toRGB888());
	color2 = Graphene::Color::ColorFactory::fromRGB888(0x00FF00);
	TEST_ASSERT_EQUAL(0, color2.getRed());
	TEST_ASSERT_EQUAL(255, color2.getGreen());
	TEST_ASSERT_EQUAL(0, color2.getBlue());
	TEST_ASSERT_EQUAL(255, color2.getAlpha());
}

void testGrayScale() {
	Graphene::Color color;
	TEST_ASSERT_EQUAL(0, color.toGray8());
	color = Graphene::Color::ColorFactory::fromGray8(255);
	TEST_ASSERT_EQUAL(255, color.getRed());
	TEST_ASSERT_EQUAL(255, color.getGreen());
	TEST_ASSERT_EQUAL(255, color.getBlue());
	TEST_ASSERT_EQUAL(255, color.getAlpha());

	Graphene::Color color2;
	color2 = 0xff555555;
	TEST_ASSERT_EQUAL(85, color2.toGray8());
}