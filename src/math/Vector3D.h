#if !defined(GRAPHENE_VECTOR_2D_H)
#define GRAPHENE_VECTOR_2D_H

#include <math.h>

#include "../core/String.h"

namespace Graphene {

class Vector3D {
   public:
	Vector3D();
	Vector3D(float x, float y, float z);

	float getX() const;
	float getY() const;
	float getZ() const;

	void setX(float x);
	void setY(float y);
	void setZ(float z);

	// Vector addition
	Vector3D operator+(const Vector3D& other) const;

	// Vector subtraction
	Vector3D operator-(const Vector3D& other) const;

	// Cross product
	// a x b = (a2b3 - a3b2, a3b1 - a1b3, a1b2 - a2b1)
	Vector3D operator*(const Vector3D& other) const;

	// Dot product
	// sum of the products of the corresponding entries of the two sequences of numbers
	// sum(a[i] * b[i])
	float operator^(const Vector3D& other) const;

	// Scalar multiplication
	Vector3D operator*(float scalar) const;

	// Scalar division
	Vector3D operator/(float scalar) const;

	// Unit vector
	Vector3D unit() const;

	// Vector length, or modulus or magnitude
	float modulus() const;

	// Angle between two vectors
	float operator%(const Vector3D& other) const;

	// projection of a vector a on a vector b
	Vector3D projectToVector(const Vector3D& other) const;

	// projection of a vector a on a plane defined by a normal vector n
	Vector3D projectToPlane(const Vector3D& normal) const;

	// ================================
	// Comparison operators
	// ================================

	// compare two vectors
	bool operator==(const Vector3D& other) const;

	// compare two vectors
	bool operator!=(const Vector3D& other) const;

	// compare two vectors
	bool operator<(const Vector3D& other) const;

	// compare two vectors
	bool operator>(const Vector3D& other) const;

	// compare two vectors
	bool operator<=(const Vector3D& other) const;

	// compare two vectors
	bool operator>=(const Vector3D& other) const;

	// To string
	String toString() const;

   private:
	float x;
	float y;
	float z;
};

}  // namespace Graphene

#endif	// GRAPHENE_VECTOR_2D_H
