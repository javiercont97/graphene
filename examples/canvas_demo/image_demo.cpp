#include <Graphene.h>

#include <iostream>

int main() {
	Graphene::Image image(800, 600);

	// Draw a rectangle
	image.drawRectangle(Graphene::Point(50, 50), 100, 100, Graphene::RED);

	// Fill a rectangle
	image.fillRectangle(Graphene::Point(100, 100), 200, 200, Graphene::NAVY);

	// Draw a circle
	image.drawCircle(Graphene::Point(400, 300), 100, Graphene::MAROON);

	// Fill a circle
	image.fillCircle(Graphene::Point(600, 300), 100, Graphene::PURPLE);

	// Draw a line
	image.drawLine(Graphene::Point(0, 0), Graphene::Point(800, 600), Graphene::GREEN);

	// Draw a triangle
	image.drawPolygon({Graphene::Point(200, 200), Graphene::Point(400, 200), Graphene::Point(300, 400)},
					  Graphene::OLIVE);

	// Draw a filled triangle
	image.fillPolygon({Graphene::Point(500, 200), Graphene::Point(600, 100), Graphene::Point(700, 400)},
					  Graphene::TEAL);

	// Export the image to a PPM file P3 format
	Graphene::String fileName = "ppm_p3_demo.ppm";
	if (!image.exportTo(fileName, Graphene::ImageFormat::PPM_P3)) {
		std::cerr << Graphene::String::asPrintf(
			"Failed to save image to \"%s\": %s\n", fileName.cStyleString(), image.getErrorMessage().cStyleString());
	}

	// Export the image to a PPM file P6 format
	fileName = "ppm_p6_demo.ppm";
	if (!image.exportTo(fileName, Graphene::ImageFormat::PPM_P6)) {
		std::cerr << Graphene::String::asPrintf(
			"Failed to save image to \"%s\": %s\n", fileName.cStyleString(), image.getErrorMessage().cStyleString());
	}

	return 0;
}