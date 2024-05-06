#include <Graphene.h>
#include <unity/unity.h>

void test_virtual_screen_constructor() {
	Graphene::VirtualScreenDriver driver(128, 64);
	TEST_ASSERT_EQUAL(128, driver.getWidth());
	TEST_ASSERT_EQUAL(64, driver.getHeight());

	Graphene::VirtualScreenDriver driver2(64, 128);
	TEST_ASSERT_EQUAL(64, driver2.getWidth());
	TEST_ASSERT_EQUAL(128, driver2.getHeight());

	Graphene::VirtualScreenDriver driver3(0, 0);
	TEST_ASSERT_EQUAL(0, driver3.getWidth());
	TEST_ASSERT_EQUAL(0, driver3.getHeight());

	// frame buffer should be initialized
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();
	TEST_ASSERT_EQUAL(128, buffer.getWidth());
	TEST_ASSERT_EQUAL(64, buffer.getHeight());

	Graphene::FrameBuffer buffer2 = driver2.getCurrentFrame();
	TEST_ASSERT_EQUAL(64, buffer2.getWidth());
	TEST_ASSERT_EQUAL(128, buffer2.getHeight());

	Graphene::FrameBuffer buffer3 = driver3.getCurrentFrame();
	TEST_ASSERT_EQUAL(0, buffer3.getWidth());
	TEST_ASSERT_EQUAL(0, buffer3.getHeight());

	// foreground and background colors should be initialized
	TEST_ASSERT_EQUAL(Graphene::WHITE, driver.getForegroundColor());
	TEST_ASSERT_EQUAL(Graphene::BLACK, driver.getBackgroundColor());

	// frame buffer should be cleared
	for (uint32_t x = 0; x < driver.getWidth(); x++) {
		for (uint32_t y = 0; y < driver.getHeight(); y++) {
			TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(x, y)));
		}
	}
}

void test_virtual_screen_draw_pixel() {
	Graphene::VirtualScreenDriver driver(128, 64);
	TEST_ASSERT_EQUAL(0, driver.currentFrameIndex());  // first frame buffer

	// check first frame buffer to be empty
	Graphene::FrameBuffer buffer1 = driver.getCurrentFrame();
	for (uint32_t x = 0; x < driver.getWidth(); x++) {
		for (uint32_t y = 0; y < driver.getHeight(); y++) {
			TEST_ASSERT_EQUAL(Graphene::BLACK, buffer1.getPixel(Graphene::Point(x, y)));
		}
	}

	// check second frame buffer to be empty
	driver.swapBuffers();
	TEST_ASSERT_EQUAL(1, driver.currentFrameIndex());  // second frame buffer
	Graphene::FrameBuffer buffer2 = driver.getCurrentFrame();
	for (uint32_t x = 0; x < driver.getWidth(); x++) {
		for (uint32_t y = 0; y < driver.getHeight(); y++) {
			TEST_ASSERT_EQUAL(Graphene::BLACK, buffer2.getPixel(Graphene::Point(x, y)));
		}
	}

	// return to first frame buffer
	driver.swapBuffers();
	TEST_ASSERT_EQUAL(0, driver.currentFrameIndex());  // first frame buffer
	// draw some pixels
	driver.drawPixel(Graphene::Point(0, 0));
	driver.drawPixel(Graphene::Point(127, 63));
	driver.drawPixel(Graphene::Point(64, 32));
	driver.drawPixel(Graphene::Point(0, 63));
	driver.drawPixel(Graphene::Point(127, 0));

	// check pixels are drawn to the buffer
	driver.swapBuffers();
	TEST_ASSERT_EQUAL(1, driver.currentFrameIndex());  // second frame buffer
	Graphene::FrameBuffer buffer3 = driver.getCurrentFrame();

	TEST_ASSERT_EQUAL(Graphene::WHITE, buffer3.getPixel(Graphene::Point(0, 0)));
	TEST_ASSERT_EQUAL(Graphene::WHITE, buffer3.getPixel(Graphene::Point(127, 63)));
	TEST_ASSERT_EQUAL(Graphene::WHITE, buffer3.getPixel(Graphene::Point(64, 32)));
	TEST_ASSERT_EQUAL(Graphene::WHITE, buffer3.getPixel(Graphene::Point(0, 63)));
	TEST_ASSERT_EQUAL(Graphene::WHITE, buffer3.getPixel(Graphene::Point(127, 0)));
}

void test_virtual_screen_driver_draw_line() {
	Graphene::VirtualScreenDriver driver(16, 9);
	// draw some lines
	driver.setForegroundColor(Graphene::NAVY);
	driver.drawLine(Graphene::Point(0, 0), Graphene::Point(15, 8));

	driver.setForegroundColor(Graphene::GREEN);
	driver.drawLine(Graphene::Point(0, 8), Graphene::Point(9, 6));

	driver.setForegroundColor(Graphene::RED);
	driver.drawLine(Graphene::Point(15, 0), Graphene::Point(15, 5));

	driver.setForegroundColor(Graphene::PINK);
	driver.drawLine(Graphene::Point(1, 7), Graphene::Point(0, 2));

	driver.setForegroundColor(Graphene::SILVER);
	driver.drawLine(Graphene::Point(11, 0), Graphene::Point(13, 5));

	// check pixels are drawn to the buffer
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();

	// check pixels are drawn to the buffer according to
	// Bresenham's line algorithm
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(0, 0)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(1, 1)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(2, 1)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(3, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(4, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(5, 3)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(6, 3)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(7, 4)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(8, 4)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(9, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(10, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(11, 6)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(12, 6)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(13, 7)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(14, 7)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(15, 8)));

	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(0, 8)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(1, 8)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(2, 8)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(3, 7)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(4, 7)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(5, 7)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(6, 7)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(7, 6)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(8, 6)));
	TEST_ASSERT_EQUAL(Graphene::GREEN, buffer.getPixel(Graphene::Point(9, 6)));

	TEST_ASSERT_EQUAL(Graphene::RED, buffer.getPixel(Graphene::Point(15, 0)));
	TEST_ASSERT_EQUAL(Graphene::RED, buffer.getPixel(Graphene::Point(15, 1)));
	TEST_ASSERT_EQUAL(Graphene::RED, buffer.getPixel(Graphene::Point(15, 2)));
	TEST_ASSERT_EQUAL(Graphene::RED, buffer.getPixel(Graphene::Point(15, 3)));
	TEST_ASSERT_EQUAL(Graphene::RED, buffer.getPixel(Graphene::Point(15, 4)));
	TEST_ASSERT_EQUAL(Graphene::RED, buffer.getPixel(Graphene::Point(15, 5)));

	TEST_ASSERT_EQUAL(Graphene::PINK, buffer.getPixel(Graphene::Point(1, 7)));
	TEST_ASSERT_EQUAL(Graphene::PINK, buffer.getPixel(Graphene::Point(1, 6)));
	TEST_ASSERT_EQUAL(Graphene::PINK, buffer.getPixel(Graphene::Point(1, 5)));
	TEST_ASSERT_EQUAL(Graphene::PINK, buffer.getPixel(Graphene::Point(0, 4)));
	TEST_ASSERT_EQUAL(Graphene::PINK, buffer.getPixel(Graphene::Point(0, 3)));
	TEST_ASSERT_EQUAL(Graphene::PINK, buffer.getPixel(Graphene::Point(0, 2)));

	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(11, 0)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(11, 1)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(12, 2)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(12, 3)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(13, 4)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(13, 5)));

	// ' ' -> BLACK
	// '1' -> NAVY
	// '2' -> GREEN
	// '3' -> RED
	// '4' -> PINK
	// '5' -> SILVER
	//   |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 0 |  1 |    |    |    |    |    |    |    |    |    |    |  5 |    |    |    |  3 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 1 |    |  1 |  1 |    |    |    |    |    |    |    |    |  5 |    |    |    |  3 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 2 |  4 |    |    |  1 |  1 |    |    |    |    |    |    |    |  5 |    |    |  3 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 3 |  4 |    |    |    |    |  1 |  1 |    |    |    |    |    |  5 |    |    |  3 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 4 |  4 |    |    |    |    |    |    |  1 |  1 |    |    |    |    |  5 |    |  3 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 5 |    |  4 |    |    |    |    |    |    |    |  1 |  1 |    |    |  5 |    |  3 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 6 |    |  4 |    |    |    |    |    |  2 |  2 |  2 |    |  1 |  1 |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 7 |    |  4 |    |  2 |  2 |  2 |  2 |    |    |    |    |    |    |  1 |  1 |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 8 |  2 |  2 |  2 |    |    |    |    |    |    |    |    |    |    |    |    |  1 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
}

void test_virtual_screen_driver_draw_rectangle() {
	Graphene::VirtualScreenDriver driver(16, 9);
	// draw some rectangles
	driver.setForegroundColor(Graphene::NAVY);
	driver.drawRectangle(Graphene::Point(3, 2), 8, 4);

	driver.setForegroundColor(Graphene::SILVER);
	driver.drawRectangle(Graphene::Point(12, 1), 3, 3);

	// check pixels are drawn to the buffer
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();

	// check pixels are drawn to the buffer

	// NAVY rectangle
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(3, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(4, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(5, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(6, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(7, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(8, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(9, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(10, 2)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(3, 3)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(3, 4)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(10, 3)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(10, 4)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(3, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(4, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(5, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(6, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(7, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(8, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(9, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(10, 5)));

	// SILVER rectangle
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(12, 1)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(13, 1)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(14, 1)));

	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(12, 2)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(14, 2)));

	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(12, 3)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(13, 3)));
	TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(14, 3)));

	// ' ' -> BLACK
	// '1' -> NAVY
	// '2' -> SILVER
	//   |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 0 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 1 |    |    |    |    |    |    |    |    |    |    |    |    |  2 |  2 |  2 |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 2 |    |    |    |  1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |    |  2 |    |  2 |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 3 |    |    |    |  1 |    |    |    |    |    |    |  1 |    |  2 |  2 |  2 |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 4 |    |    |    |  1 |    |    |    |    |    |    |  1 |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 5 |    |    |    |  1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 6 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 7 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 8 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
}

void test_virtual_screen_driver_fill_rectangle() {
	Graphene::VirtualScreenDriver driver(16, 9);
	// draw some rectangles
	driver.setForegroundColor(Graphene::NAVY);
	driver.fillRectangle(Graphene::Point(3, 2), 8, 4);

	driver.setForegroundColor(Graphene::SILVER);
	driver.fillRectangle(Graphene::Point(12, 1), 3, 3);

	// check pixels are drawn to the buffer
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();

	// check pixels are drawn to the buffer

	// NAVY rectangle
	for (uint32_t x = 3; x < 11; x++) {
		for (uint32_t y = 2; y < 6; y++) {
			TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(x, y)));
		}
	}

	// SILVER rectangle
	for (uint32_t x = 12; x < 15; x++) {
		for (uint32_t y = 1; y < 4; y++) {
			TEST_ASSERT_EQUAL(Graphene::SILVER, buffer.getPixel(Graphene::Point(x, y)));
		}
	}

	// borders should remain empty
	TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(2, 1)));
	TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(11, 1)));
	TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(11, 6)));
	TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(2, 6)));

	TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(11, 0)));
	TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(15, 0)));
	TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(15, 4)));
	TEST_ASSERT_EQUAL(Graphene::BLACK, buffer.getPixel(Graphene::Point(11, 4)));

	// ' ' -> BLACK
	// '1' -> NAVY
	// '2' -> SILVER
	//   |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 0 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 1 |    |    |    |    |    |    |    |    |    |    |    |    |  2 |  2 |  2 |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 2 |    |    |    |  1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |    |  2 |  2 |  2 |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 3 |    |    |    |  1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |    |  2 |  2 |  2 |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 4 |    |    |    |  1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 5 |    |    |    |  1 |  1 |  1 |  1 |  1 |  1 |  1 |  1 |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 6 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 7 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 8 |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
}

void test_draw_circle() {
	Graphene::VirtualScreenDriver driver(16, 9);
	// draw some circles
	driver.setForegroundColor(Graphene::NAVY);
	driver.drawCircle(Graphene::Point(8, 4), 5);

	// check pixels are drawn to the buffer
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();

	// check pixels are drawn to the buffer
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(7, 0)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(8, 0)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(9, 0)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(5, 1)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(6, 1)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(10, 1)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(11, 1)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(5, 2)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(11, 2)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(4, 3)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(12, 3)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(4, 4)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(12, 4)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(4, 5)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(12, 5)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(5, 6)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(11, 6)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(5, 7)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(6, 7)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(10, 7)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(11, 7)));

	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(7, 8)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(8, 8)));
	TEST_ASSERT_EQUAL(Graphene::NAVY, buffer.getPixel(Graphene::Point(9, 8)));

	// ' ' -> BLACK
	// '0' -> center of the circle
	// '1' -> NAVY
	//   |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 0 |    |    |    |    |    |    |    |  1 |  1 |  1 |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 1 |    |    |    |    |    |  1 |  1 |    |    |    |  1 |  1 |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 2 |    |    |    |    |    |  1 |    |    |    |    |    |  1 |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 3 |    |    |    |    |  1 |    |    |    |    |    |    |    |  1 |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 4 |    |    |    |    |  1 |    |    |    |  0 |    |    |    |  1 |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 5 |    |    |    |    |  1 |    |    |    |    |    |    |    |  1 |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 6 |    |    |    |    |    |  1 |    |    |    |    |    |  1 |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 7 |    |    |    |    |    |  1 |  1 |    |    |    |  1 |  1 |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
	// 8 |    |    |    |    |    |    |    |  1 |  1 |  1 |    |    |    |    |    |    |
	//   +----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
}