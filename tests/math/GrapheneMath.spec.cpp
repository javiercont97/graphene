#include <Graphene.h>
#include <unity/unity.h>

#include "Point.spec.h"

void setUp() {
}

void tearDown() {
}

int main() {
	UNITY_BEGIN();
	//======================
	// Test Point class
	//======================
	// Test constructors
	RUN_TEST(testPointDefaultConstructor);
	RUN_TEST(testPointParameterizedConstructor);
	RUN_TEST(testPointCopyConstructor);
	RUN_TEST(testPointAssignmentOperator);

	// Test accessors
	RUN_TEST(testPointGetX);
	RUN_TEST(testPointGetY);
	RUN_TEST(testPointSetX);
	RUN_TEST(testPointSetY);

	// Test operators
	RUN_TEST(testPointEqualityOperator);
	RUN_TEST(testPointInequalityOperator);
	RUN_TEST(testPointAdditionOperator);
	RUN_TEST(testPointSubtractionOperator);

	// Test utility functions
	RUN_TEST(testPointDistanceTo);
	RUN_TEST(testPointToString);

	return UNITY_END();
}