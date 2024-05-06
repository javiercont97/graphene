#include <Graphene.h>
#include <unity/unity.h>

#include "FrameBuffer.spec.h"

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

	UNITY_END();
}