#include <Graphene.h>
#include <unity/unity.h>

#include "Color.spec.h"
#include "String.spec.h"

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
	// Test Color class
	//======================
	RUN_TEST(testColor);
	RUN_TEST(testGrayScale);
	RUN_TEST(testInvertColor);

	return UNITY_END();
}
