#include <Graphene.h>
#include <unity/unity.h>

void test_default_constructor() {
	Graphene::String str;
	TEST_ASSERT_EQUAL_STRING("", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(0, str.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("Hello", str.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(5, str.length());

	// Test [] operator
	TEST_ASSERT_EQUAL_CHAR('\0', str[0]);
	TEST_ASSERT_EQUAL_CHAR('\0', str[1]);
}

void test_cstyle_constructor() {
	Graphene::String str("Hello");
	TEST_ASSERT_EQUAL_STRING("Hello", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(5, str.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("World", str.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(10, str.length());

	// Test [] operator
	TEST_ASSERT_EQUAL_CHAR('H', str[0]);
	TEST_ASSERT_EQUAL_CHAR('e', str[1]);
	TEST_ASSERT_EQUAL_CHAR('l', str[2]);
	TEST_ASSERT_EQUAL_CHAR('l', str[3]);
	TEST_ASSERT_EQUAL_CHAR('o', str[4]);
	TEST_ASSERT_EQUAL_CHAR('\0', str[5]);

	// // Test out of bound
	TEST_ASSERT_EQUAL_CHAR('\0', str[6]);
	TEST_ASSERT_EQUAL_CHAR('\0', str[100]);
}

void test_copy_constructor() {
	Graphene::String str1("Hello");
	Graphene::String str2(str1);
	TEST_ASSERT_EQUAL_STRING("Hello", str2.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(5, str2.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("World", str2.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(10, str2.length());
}

void test_stdstring_constructor() {
	std::string stdStr("Hello");
	Graphene::String str(stdStr);
	TEST_ASSERT_EQUAL_STRING("Hello", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(5, str.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("World", str.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(10, str.length());
}

void test_assignment_operator() {
	Graphene::String str1("Hello");
	Graphene::String str2;
	str2 = str1;
	TEST_ASSERT_EQUAL_STRING("Hello", str2.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(5, str2.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("World", str2.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(10, str2.length());

	str1 = "World";
	TEST_ASSERT_EQUAL_STRING("World", str1.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(5, str1.length());
}

void test_concatenation_operator() {
	Graphene::String str1("Hello");
	Graphene::String str2(" World");
	Graphene::String result = str1 + str2;
	TEST_ASSERT_EQUAL_STRING("Hello World", result.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(11, result.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("Hello", result.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(5, result.length());
}

void test_concatenation_assignment_operator() {
	Graphene::String str1("Hello");
	Graphene::String str2(" World");
	str1 += str2;
	TEST_ASSERT_EQUAL_STRING("Hello World", str1.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(11, str1.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("Hello", str1.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(5, str1.length());
}

void test_comparison_operator() {
	Graphene::String str1("Hello");
	Graphene::String str2("Hello");
	Graphene::String str3("World");
	TEST_ASSERT_TRUE(str1 == str2);
	TEST_ASSERT_FALSE(str1 == str3);
	TEST_ASSERT_TRUE(str1 != str3);
	TEST_ASSERT_FALSE(str1 != str2);

	TEST_ASSERT_TRUE(str1 == "Hello");
	TEST_ASSERT_TRUE(str1 != "World");
	TEST_ASSERT_FALSE(str1 == "World");
	TEST_ASSERT_FALSE(str1 != "Hello");
}

void test_conversion_functions() {
	Graphene::String str("123");
	TEST_ASSERT_EQUAL_INT(123, str.toInt());
	TEST_ASSERT_EQUAL_FLOAT(123.0f, str.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(123.0, str.toDouble());

	Graphene::String str2("true");
	TEST_ASSERT_TRUE(str2.toBool());

	Graphene::String str3("false");
	TEST_ASSERT_FALSE(str3.toBool());

	// NEGATIVE TEST
	Graphene::String str4("Hello");
	TEST_ASSERT_EQUAL_INT(0, str4.toInt());
	TEST_ASSERT_EQUAL_FLOAT(0.0f, str4.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(0.0, str4.toDouble());
	TEST_ASSERT_FALSE(str4.toBool());

	Graphene::String str5("123.456");
	TEST_ASSERT_EQUAL_INT(123, str5.toInt());
	TEST_ASSERT_EQUAL_FLOAT(123.456f, str5.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(123.456, str5.toDouble());
	TEST_ASSERT_FALSE(str5.toBool());

	Graphene::String str6("123.456e-3");
	TEST_ASSERT_EQUAL_INT(0, str6.toInt());
	TEST_ASSERT_EQUAL_FLOAT(0.123456f, str6.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(0.123456, str6.toDouble());
	TEST_ASSERT_FALSE(str6.toBool());

	Graphene::String str7("123.456e3");
	TEST_ASSERT_EQUAL_INT(123456, str7.toInt());
	TEST_ASSERT_EQUAL_FLOAT(123456.0f, str7.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(123456.0, str7.toDouble());
	TEST_ASSERT_FALSE(str7.toBool());

	// Rounding
	Graphene::String str8("0.9999999");
	TEST_ASSERT_EQUAL_INT(1, str8.toInt());
	TEST_ASSERT_EQUAL_FLOAT(0.9999999f, str8.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(0.9999999, str8.toDouble());
	TEST_ASSERT_FALSE(str8.toBool());

	Graphene::String str9("0.9999999e-3");
	TEST_ASSERT_EQUAL_INT(0, str9.toInt());
	TEST_ASSERT_EQUAL_FLOAT(0.0009999999f, str9.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(0.0009999999, str9.toDouble());
	TEST_ASSERT_FALSE(str9.toBool());

	Graphene::String str10("0.9999999e3");
	TEST_ASSERT_EQUAL_INT(1000, str10.toInt());
	TEST_ASSERT_EQUAL_FLOAT(999.9999f, str10.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(999.9999, str10.toDouble());
	TEST_ASSERT_FALSE(str10.toBool());

	// More than one decimal dot, means not a number. Return 0
	Graphene::String str11("123.456.789");
	TEST_ASSERT_EQUAL_INT(0, str11.toInt());
	TEST_ASSERT_EQUAL_FLOAT(0.0f, str11.toFloat());
	// TEST_ASSERT_EQUAL_DOUBLE(0.0, str11.toDouble());
	TEST_ASSERT_FALSE(str11.toBool());
}

void test_printf_function() {
	Graphene::String str = Graphene::String::asPrintf("Hello %s!", "World");
	TEST_ASSERT_EQUAL_STRING("Hello World!", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(12, str.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("Hello", str.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(5, str.length());
}

void test_from_int() {
	Graphene::String str = Graphene::String::fromInt(123);
	TEST_ASSERT_EQUAL_STRING("123", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(3, str.length());

	str = Graphene::String::fromInt(-123);
	TEST_ASSERT_EQUAL_STRING("-123", str.cStyleString());

	str = Graphene::String::fromInt(0);
	TEST_ASSERT_EQUAL_STRING("0", str.cStyleString());

	str = Graphene::String::fromInt(1234567890);
	TEST_ASSERT_EQUAL_STRING("1234567890", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(10, str.length());

	str = Graphene::String::fromInt(-1234567890);
	TEST_ASSERT_EQUAL_STRING("-1234567890", str.cStyleString());
}

void test_from_float() {
	Graphene::String str = Graphene::String::fromFloat(123.456f, 3);
	TEST_ASSERT_EQUAL_STRING("123.456", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(7, str.length());

	str = Graphene::String::fromFloat(123.456789012345678f, 4);
	TEST_ASSERT_EQUAL_STRING("123.4568", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(8, str.length());

	str = Graphene::String::fromFloat(123, 3);
	TEST_ASSERT_EQUAL_STRING("123.000", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(7, str.length());
}

void test_from_double() {
	Graphene::String str = Graphene::String::fromDouble(123.456, 3);
	TEST_ASSERT_EQUAL_STRING("123.456", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(7, str.length());

	str = Graphene::String::fromDouble(123.456789012345678, 10);
	TEST_ASSERT_EQUAL_STRING("123.4567890123", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(14, str.length());
}

void test_from_bool() {
	Graphene::String str = Graphene::String::fromBool(true);
	TEST_ASSERT_EQUAL_STRING("true", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(4, str.length());
	TEST_ASSERT_TRUE(str.toBool());

	str = Graphene::String::fromBool(false);
	TEST_ASSERT_EQUAL_STRING("false", str.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(5, str.length());
	TEST_ASSERT_FALSE(str.toBool());
}

void test_negative_test() {
	Graphene::String str("Hello");
	Graphene::String str2("World");
	TEST_ASSERT_FALSE(str == str2);
	TEST_ASSERT_TRUE(str != str2);
}

void testSubstring() {
	Graphene::String str("Hello World");
	Graphene::String sub = str.subString(6, 5);
	TEST_ASSERT_EQUAL_STRING("World", sub.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(5, sub.length());
}

void testContains() {
	Graphene::String str("Hello World");
	TEST_ASSERT_TRUE(str.contains("Hello"));
	TEST_ASSERT_TRUE(str.contains("World"));
	TEST_ASSERT_TRUE(str.contains(" "));
	TEST_ASSERT_FALSE(str.contains("hello"));
	TEST_ASSERT_FALSE(str.contains("world"));

	// NEGATIVE TEST
	TEST_ASSERT_FALSE(str.contains("Hello    "));
	TEST_ASSERT_FALSE(str.contains(" World   "));
}

void testLowerUpper() {
	Graphene::String str("Hello World");
	Graphene::String lower = str.toLower();
	TEST_ASSERT_EQUAL_STRING("hello world", lower.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(11, lower.length());

	Graphene::String upper = str.toUpper();
	TEST_ASSERT_EQUAL_STRING("HELLO WORLD", upper.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(11, upper.length());
}

void testFind() {
	Graphene::String str("Hello World");
	TEST_ASSERT_EQUAL_UINT32(0, str.find("Hello"));
	TEST_ASSERT_EQUAL_UINT32(6, str.find("World"));
	TEST_ASSERT_EQUAL_UINT32(5, str.find(" "));
	TEST_ASSERT_EQUAL_UINT32(0, str.find("H"));
	TEST_ASSERT_EQUAL_UINT32(6, str.find("W"));
	TEST_ASSERT_EQUAL_UINT32(10, str.find("d"));

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL_UINT32(6, str.find("Hello"));
	TEST_ASSERT_NOT_EQUAL_UINT32(0, str.find("World"));
	TEST_ASSERT_NOT_EQUAL_UINT32(10, str.find(" "));

	// Not a substring
	TEST_ASSERT_EQUAL_UINT32(std::string::npos, str.find("Hello World!"));
}

void testFindLast() {
	Graphene::String str("Hello World");
	TEST_ASSERT_EQUAL_UINT32(0, str.findLast("Hello"));
	TEST_ASSERT_EQUAL_UINT32(6, str.findLast("World"));
	TEST_ASSERT_EQUAL_UINT32(5, str.findLast(" "));
	TEST_ASSERT_EQUAL_UINT32(0, str.findLast("H"));
	TEST_ASSERT_EQUAL_UINT32(6, str.findLast("W"));
	TEST_ASSERT_EQUAL_UINT32(5, str.findLast(" "));
	TEST_ASSERT_EQUAL_UINT32(10, str.findLast("d"));

	Graphene::String str2("Hello World World");
	TEST_ASSERT_EQUAL_UINT32(12, str2.findLast("World"));
	TEST_ASSERT_EQUAL_UINT32(11, str2.findLast(" "));
}

void testReplace() {
	Graphene::String str("Hello World");
	Graphene::String replaced = str.replace("World", "Graphene");
	TEST_ASSERT_EQUAL_STRING("Hello Graphene", replaced.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(14, replaced.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("Hello World", replaced.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(11, replaced.length());
}

void testTrim() {
	Graphene::String str("   Hello World   ");
	Graphene::String trimmed = str.trim();
	TEST_ASSERT_EQUAL_STRING("Hello World", trimmed.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(11, trimmed.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("   Hello World   ", trimmed.cStyleString());
	TEST_ASSERT_NOT_EQUAL_UINT32(15, trimmed.length());
}

void testReverse() {
	Graphene::String str("Hello World");
	Graphene::String reversed = str.reverse();
	TEST_ASSERT_EQUAL_STRING("dlroW olleH", reversed.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(11, reversed.length());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("Hello World", reversed.cStyleString());
	TEST_ASSERT_EQUAL_UINT32(11, reversed.length());
}

void testSplit() {
	Graphene::String str("Hello,World,Graphene");
	std::vector<Graphene::String> result = str.split(",");
	TEST_ASSERT_EQUAL_UINT32(3, result.size());
	TEST_ASSERT_EQUAL_STRING("Hello", result[0].cStyleString());
	TEST_ASSERT_EQUAL_STRING("World", result[1].cStyleString());
	TEST_ASSERT_EQUAL_STRING("Graphene", result[2].cStyleString());

	// NEGATIVE TEST
	TEST_ASSERT_NOT_EQUAL("Hello", result[1].cStyleString());
	TEST_ASSERT_NOT_EQUAL("World", result[2].cStyleString());
	TEST_ASSERT_NOT_EQUAL("Graphene", result[0].cStyleString());
}

void testStartsWith() {
	Graphene::String str("Hello World");
	TEST_ASSERT_TRUE(str.startsWith("Hello"));
	TEST_ASSERT_TRUE(str.startsWith("H"));
	TEST_ASSERT_FALSE(str.startsWith("World"));
	TEST_ASSERT_FALSE(str.startsWith("W"));
	TEST_ASSERT_FALSE(str.startsWith("o"));
}

void testEndsWith() {
	Graphene::String str("Hello World");
	TEST_ASSERT_TRUE(str.endsWith("World"));
	TEST_ASSERT_TRUE(str.endsWith("d"));
	TEST_ASSERT_FALSE(str.endsWith("Hello"));
	TEST_ASSERT_FALSE(str.endsWith("H"));
	TEST_ASSERT_FALSE(str.endsWith("o"));
}
