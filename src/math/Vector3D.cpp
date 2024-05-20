#include "Vector3D.h"

Graphene::Vector3D::Vector3D() {
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}

Graphene::Vector3D::Vector3D(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

float Graphene::Vector3D::getX() const {
	return this->x;
}

float Graphene::Vector3D::getY() const {
	return this->y;
}

float Graphene::Vector3D::getZ() const {
	return this->z;
}

void Graphene::Vector3D::setX(float x) {
	this->x = x;
}

void Graphene::Vector3D::setY(float y) {
	this->y = y;
}

void Graphene::Vector3D::setZ(float z) {
	this->z = z;
}

Graphene::Vector3D Graphene::Vector3D::operator+(const Vector3D& other) const {
	Vector3D result;
	result.x = this->x + other.x;
	result.y = this->y + other.y;
	result.z = this->z + other.z;

	return result;
}

Graphene::Vector3D Graphene::Vector3D::operator-(const Vector3D& other) const {
	Vector3D result;
	result.x = this->x - other.x;
	result.y = this->y - other.y;
	result.z = this->z - other.z;

	return result;
}

Graphene::Vector3D Graphene::Vector3D::operator*(const Vector3D& other) const {
	Vector3D result;
	result.x = this->y * other.z - this->z * other.y;  // a2b3 - a3b2
	result.y = this->z * other.x - this->x * other.z;  // a3b1 - a1b3
	result.z = this->x * other.y - this->y * other.x;  // a1b2 - a2b1

	return result;
}

float Graphene::Vector3D::operator^(const Vector3D& other) const {
	return x * other.x + y * other.y + z * other.z;
}

Graphene::Vector3D Graphene::Vector3D::operator*(float scalar) const {
	Vector3D result;
	result.x = this->x * scalar;
	result.y = this->y * scalar;
	result.z = this->z * scalar;

	return result;
}

Graphene::Vector3D Graphene::Vector3D::operator/(float scalar) const {
	Vector3D result;
	result.x = this->x / scalar;
	result.y = this->y / scalar;
	result.z = this->z / scalar;

	return result;
}

Graphene::Vector3D Graphene::Vector3D::unit() const {
	float mod = modulus();
	return *this / mod;
}

float Graphene::Vector3D::modulus() const {
	return std::sqrt(x * x + y * y + z * z);
}

float Graphene::Vector3D::operator%(const Vector3D& other) const {
	float mod = modulus();
	float otherMod = other.modulus();
	float dot = *this ^ other;

	return std::acos(dot / (mod * otherMod));
}

Graphene::Vector3D Graphene::Vector3D::projectToVector(const Vector3D& other) const {
	float dot = *this ^ other;
	float otherMod = other.modulus();

	return other * (dot / (otherMod * otherMod));
}

Graphene::Vector3D Graphene::Vector3D::projectToPlane(const Vector3D& normal) const {
	Graphene::Vector3D projectionToNormal = this->projectToVector(normal);

	return *this - projectionToNormal;
}

bool Graphene::Vector3D::operator==(const Vector3D& other) const {
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Graphene::Vector3D::operator!=(const Vector3D& other) const {
	return this->x != other.x || this->y != other.y || this->z != other.z;
}

bool Graphene::Vector3D::operator<(const Vector3D& other) const {
	return this->modulus() < other.modulus();
}

bool Graphene::Vector3D::operator>(const Vector3D& other) const {
	return this->modulus() > other.modulus();
}

bool Graphene::Vector3D::operator<=(const Vector3D& other) const {
	return this->modulus() <= other.modulus();
}

bool Graphene::Vector3D::operator>=(const Vector3D& other) const {
	return this->modulus() >= other.modulus();
}

Graphene::String Graphene::Vector3D::toString() const {
	return Graphene::String::asPrintf("Vector3D(%f, %f, %f)", x, y, z);
}
