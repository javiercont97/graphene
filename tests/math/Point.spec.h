#include <Graphene.h>
#include <unity/unity.h>

void testPointDefaultConstructor() {
	Graphene::Point point;

	TEST_ASSERT_EQUAL_UINT32(0, point.getX());
	TEST_ASSERT_EQUAL_UINT32(0, point.getY());
}

void testPointParameterizedConstructor() {
	Graphene::Point point(10, 20);

	TEST_ASSERT_EQUAL_UINT32(10, point.getX());
	TEST_ASSERT_EQUAL_UINT32(20, point.getY());
}

void testPointCopyConstructor() {
	Graphene::Point point1(10, 20);
	Graphene::Point point2(point1);

	TEST_ASSERT_EQUAL_UINT32(10, point2.getX());
	TEST_ASSERT_EQUAL_UINT32(20, point2.getY());
}

void testPointAssignmentOperator() {
	Graphene::Point point1(10, 20);
	Graphene::Point point2 = point1;

	TEST_ASSERT_EQUAL_UINT32(10, point2.getX());
	TEST_ASSERT_EQUAL_UINT32(20, point2.getY());
}

void testPointGetX() {
	Graphene::Point point(10, 20);

	TEST_ASSERT_EQUAL_UINT32(10, point.getX());
}

void testPointGetY() {
	Graphene::Point point(10, 20);

	TEST_ASSERT_EQUAL_UINT32(20, point.getY());
}

void testPointSetX() {
	Graphene::Point point;

	point.setX(10);

	TEST_ASSERT_EQUAL_UINT32(10, point.getX());
}

void testPointSetY() {
	Graphene::Point point;

	point.setY(20);

	TEST_ASSERT_EQUAL_UINT32(20, point.getY());
}

void testPointEqualityOperator() {
	Graphene::Point point1(10, 20);
	Graphene::Point point2(10, 20);

	TEST_ASSERT_TRUE(point1 == point2);
}

void testPointInequalityOperator() {
	Graphene::Point point1(10, 20);
	Graphene::Point point2(20, 30);

	TEST_ASSERT_TRUE(point1 != point2);
}

void testPointAdditionOperator() {
	Graphene::Point point1(10, 20);
	Graphene::Point point2(20, 30);
	Graphene::Point point3 = point1 + point2;

	TEST_ASSERT_EQUAL_UINT32(30, point3.getX());
	TEST_ASSERT_EQUAL_UINT32(50, point3.getY());
}

void testPointSubtractionOperator() {
	Graphene::Point point1(20, 30);
	Graphene::Point point2(10, 20);
	Graphene::Point point3 = point1 - point2;

	TEST_ASSERT_EQUAL_UINT32(10, point3.getX());
	TEST_ASSERT_EQUAL_UINT32(10, point3.getY());
}

void testPointDistanceTo() {
	Graphene::Point point1(10, 20);
	Graphene::Point point2(20, 30);

	TEST_ASSERT_EQUAL_UINT32(14, point1.distanceTo(point2));
}

void testPointToString() {
	Graphene::Point point(10, 20);

	TEST_ASSERT_EQUAL_STRING("(10, 20)", point.toString().cStyleString());
}
