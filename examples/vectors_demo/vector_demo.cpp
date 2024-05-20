#include <Graphene.h>

#include <iostream>

using namespace Graphene;

int main() {
	Vector3D A(4, 2, 1);
	Vector3D B(5, -3, 3);

	Vector3D C = A.projectToVector(B);

	std::cout << "Projection of A onto B: " << C.toString() << std::endl;

	std::cout << "||C|| = " << C.modulus() << std::endl;

	std::cout << "Norm(B) = " << B.unit().toString() << std::endl;
	std::cout << "Norm(C) = " << C.unit().toString() << std::endl;

	Vector3D v1(1.0f, 2.0f, 3.0f);

	Vector3D xyPlaneNormal(0.0f, 0.0f, 1.0f);

	Vector3D projection = v1.projectToPlane(xyPlaneNormal);

	std::cout << "Projection to XY plane: " << projection.toString() << std::endl;

	return 0;
}