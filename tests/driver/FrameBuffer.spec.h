#include <Graphene.h>
#include <unity/unity.h>

void test_FrameBuffer() {
	Graphene::FrameBuffer frameBuffer(100, 100);

	TEST_ASSERT_EQUAL(100, frameBuffer.getWidth());
	TEST_ASSERT_EQUAL(100, frameBuffer.getHeight());

	std::vector<Graphene::Color> buffer = frameBuffer.getBuffer();
	TEST_ASSERT_EQUAL(100 * 100, buffer.size());

	frameBuffer.clear(Graphene::WHITE);
	buffer = frameBuffer.getBuffer();
	for (uint32_t i = 0; i < 100 * 100; i++) {
		TEST_ASSERT_EQUAL(Graphene::WHITE, buffer[i]);
	}

	frameBuffer.clear(Graphene::BLACK);
	buffer = frameBuffer.getBuffer();
	for (uint32_t i = 0; i < 100 * 100; i++) {
		TEST_ASSERT_EQUAL(Graphene::BLACK, buffer[i]);
	}

	frameBuffer.setPixel(0, 0, Graphene::WHITE);
	TEST_ASSERT_EQUAL(Graphene::WHITE, frameBuffer.getPixel(0, 0));

	frameBuffer.setPixel(99, 0, Graphene::GREEN);
	TEST_ASSERT_EQUAL(Graphene::GREEN, frameBuffer.getPixel(99, 0));

	frameBuffer.setPixel(99, 99, Graphene::RED);
	TEST_ASSERT_EQUAL(Graphene::RED, frameBuffer.getPixel(99, 99));

	frameBuffer.setPixel(0, 99, Graphene::NAVY);
	TEST_ASSERT_EQUAL(Graphene::NAVY, frameBuffer.getPixel(0, 99));

	buffer = frameBuffer.getBuffer();
	for (uint32_t i = 0; i < 100 * 100; i++) {
		if (i == 0) {
			// Pixel at (0, 0)
			TEST_ASSERT_EQUAL(Graphene::WHITE, buffer[i]);
		} else if (i == 99) {
			// Pixel at (99, 0)
			TEST_ASSERT_EQUAL(Graphene::GREEN, buffer[i]);
		} else if (i == 9900) {
			// Pixel at (0, 99)
			TEST_ASSERT_EQUAL(Graphene::NAVY, buffer[i]);
		} else if (i == 9999) {
			// Pixel at (99, 99)
			TEST_ASSERT_EQUAL(Graphene::RED, buffer[i]);
		} else {
			// All other pixels
			TEST_ASSERT_EQUAL(Graphene::BLACK, buffer[i]);
		}
	}
}