#include <Graphene.h>
#include <unity/unity.h>

void testVariant() {
	Graphene::Variant v;
	v = 42;
	TEST_ASSERT_EQUAL_INT(42, v.toInt());

	Graphene::Variant v2(43);
	TEST_ASSERT_EQUAL_INT(43, v2.toInt());

	Graphene::Variant v3 = Graphene::Variant(44);
	TEST_ASSERT_EQUAL_INT(44, v3.toInt());

	Graphene::Variant v4;
	v4 = 3.14f;
	TEST_ASSERT_EQUAL_FLOAT(3.14f, v4.toFloat());

	Graphene::Variant v5;
	v5 = true;
	TEST_ASSERT_EQUAL_INT(1, v5.toBool());

	Graphene::Variant v6 = Graphene::Variant(std::string("Hello, World!"));
	TEST_ASSERT_EQUAL_STRING("Hello, World!", v6.toString().c_str());

	Graphene::Variant v7 = Graphene::Variant("Hello, World!");
	TEST_ASSERT_EQUAL_STRING("Hello, World!", v7.toString().c_str());

	Graphene::Variant v8 = 100;
	TEST_ASSERT_EQUAL_INT(100, v8.toInt());

	Graphene::Variant v9 = v6;
	TEST_ASSERT_EQUAL_STRING("Hello, World!", v9.toString().c_str());

	Graphene::Variant v10 = std::vector<int>{1, 2, 3, 4, 5};
	std::vector<int> v10Vector = v10.toIntVector();
	TEST_ASSERT_EQUAL_INT(1, v10Vector[0]);
	TEST_ASSERT_EQUAL_INT(2, v10Vector[1]);
	TEST_ASSERT_EQUAL_INT(3, v10Vector[2]);
	TEST_ASSERT_EQUAL_INT(4, v10Vector[3]);
	TEST_ASSERT_EQUAL_INT(5, v10Vector[4]);

	Graphene::Variant v11 = std::vector<float>{1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	std::vector<float> v11Vector = v11.toFloatVector();
	TEST_ASSERT_EQUAL_FLOAT(1.1f, v11Vector[0]);
	TEST_ASSERT_EQUAL_FLOAT(2.2f, v11Vector[1]);
	TEST_ASSERT_EQUAL_FLOAT(3.3f, v11Vector[2]);
	TEST_ASSERT_EQUAL_FLOAT(4.4f, v11Vector[3]);
	TEST_ASSERT_EQUAL_FLOAT(5.5f, v11Vector[4]);

	Graphene::Variant v12 = std::vector<double>{1.1, 2.2, 3.3, 4.4, 5.5};
	std::vector<double> v12Vector = v12.toDoubleVector();
	TEST_ASSERT_EQUAL_FLOAT(1.1, v12Vector[0]);
	TEST_ASSERT_EQUAL_FLOAT(2.2, v12Vector[1]);
	TEST_ASSERT_EQUAL_FLOAT(3.3, v12Vector[2]);
	TEST_ASSERT_EQUAL_FLOAT(4.4, v12Vector[3]);
	TEST_ASSERT_EQUAL_FLOAT(5.5, v12Vector[4]);

	Graphene::Variant v14 =
		std::vector<std::string>{"Hello", "World", "Goodbye", "Cruel", "World"};
	std::vector<std::string> v14Vector = v14.toStringVector();
	TEST_ASSERT_EQUAL_STRING("Hello", v14Vector[0].c_str());
	TEST_ASSERT_EQUAL_STRING("World", v14Vector[1].c_str());
	TEST_ASSERT_EQUAL_STRING("Goodbye", v14Vector[2].c_str());
	TEST_ASSERT_EQUAL_STRING("Cruel", v14Vector[3].c_str());
	TEST_ASSERT_EQUAL_STRING("World", v14Vector[4].c_str());
}
