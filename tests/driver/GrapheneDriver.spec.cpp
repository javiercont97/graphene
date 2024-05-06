#include <Graphene.h>
#include <unity/unity.h>

#include "FrameBuffer.spec.h"
#include "VirtualScreenDriver.spec.h"

void setUp() {
}

void tearDown() {
}

int main() {
	UNITY_BEGIN();
	//======================
	// Test FrameBuffer class
	//======================
	RUN_TEST(test_FrameBuffer);

	//======================
	// Test VirtualScreenDriver class
	//======================
	RUN_TEST(test_virtual_screen_constructor);
	RUN_TEST(test_virtual_screen_draw_pixel);
	RUN_TEST(test_virtual_screen_driver_draw_line);

	UNITY_END();
}