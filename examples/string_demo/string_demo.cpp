#include <Graphene.h>

#include <iostream>

int main() {
	std::cout << "String Demo" << std::endl;

	Graphene::String str1 = "Hello";
	Graphene::String str2 = " World";

	std::cout << str1 + str2 << std::endl;

	Graphene::String str3 = "hello world!";

	std::cout << str3.toUpper() << std::endl;

	Graphene::Color color = Graphene::Color::ColorFactory::fromFormat(0xFF0000FF, Graphene::PixelFormat::ARGB8888);

	Graphene::String str4 = Graphene::String::asPrintf(
		"Color: %d, %d, %d, %d", color.getRed(), color.getGreen(), color.getBlue(), color.getAlpha());

	std::cout << str4 << std::endl;

	return 0;
}