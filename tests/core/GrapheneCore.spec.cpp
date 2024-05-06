#include <Graphene.h>
#include <unity/unity.h>

#include "Color.spec.h"
#include "Object.spec.h"
#include "Point.spec.h"
#include "String.spec.h"
#include "Variant.spec.h"

void setUp() {
}

void tearDown() {
}

int main() {
	UNITY_BEGIN();
	//======================
	// Test String class
	//======================
	// Test constructors
	RUN_TEST(test_default_constructor);
	RUN_TEST(test_cstyle_constructor);
	RUN_TEST(test_copy_constructor);
	RUN_TEST(test_std_string_constructor);

	// Test operators
	RUN_TEST(test_assignment_operator);
	RUN_TEST(test_concatenation_operator);
	RUN_TEST(test_concatenation_assignment_operator);
	RUN_TEST(test_comparison_operator);
	RUN_TEST(test_negative_test);

	// Test conversion functions
	RUN_TEST(test_conversion_functions);
	RUN_TEST(test_from_int);
	RUN_TEST(test_from_float);
	RUN_TEST(test_from_double);
	RUN_TEST(test_from_bool);

	// Test utility function
	RUN_TEST(test_printf_function);
	RUN_TEST(testContains);
	RUN_TEST(testFind);
	RUN_TEST(testFindLast);
	RUN_TEST(testStartsWith);
	RUN_TEST(testEndsWith);
	RUN_TEST(testSplit);

	// Test string manipulation functions
	RUN_TEST(testSubstring);
	RUN_TEST(testLowerUpper);
	RUN_TEST(testReplace);
	RUN_TEST(testTrim);
	RUN_TEST(testReverse);

	//======================
	// Test Object class
	//======================
	// Test Object properties
	RUN_TEST(testSetProperty);
	RUN_TEST(testGetProperty);
	RUN_TEST(testHasProperty);
	RUN_TEST(testRemoveProperty);
	RUN_TEST(testClearProperties);
	RUN_TEST(testGetPropertyNames);

	// Test Object event handling
	RUN_TEST(testPublish);
	RUN_TEST(testCircularPublish);

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

	//======================
	// Test Color class
	//======================
	RUN_TEST(testColor);
	RUN_TEST(testGrayScale);

	//======================
	// Test Variant class
	//======================
	RUN_TEST(testVariant);

	return UNITY_END();
}
