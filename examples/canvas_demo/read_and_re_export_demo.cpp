#include <Graphene.h>

#include <iostream>

int main() {
	// Load a PPM3 image, add a red rectangle in the middle of the image, and save it to a PPM6 file
	Graphene::Image image;
	if (!image.importFrom("checkerboard_demo.ppm", Graphene::ImageFormat::PPM_P3)) {
		std::cerr << Graphene::String::asPrintf("Failed to load image from \"checkerboard_demo.ppm\": %s\n",
												image.getErrorMessage().cStyleString());
		return 1;
	}

	// Add a red rectangle in the middle of the image
	image.fillRectangle(Graphene::Point(100, 100), 200, 200, Graphene::RED);

	// Export the image to a PPM file P6 format
	Graphene::String fileName = "re-exported_checkerboard_demo.ppm";
	if (!image.exportTo(fileName, Graphene::ImageFormat::PPM_P6)) {
		std::cerr << Graphene::String::asPrintf(
			"Failed to save image to \"%s\": %s\n", fileName.cStyleString(), image.getErrorMessage().cStyleString());
	}

	// Load a PPM6 image, add a green rectangle in the middle of the image, and save it to a PPM3 file
	if (!image.importFrom("ppm_p6_demo.ppm", Graphene::ImageFormat::PPM_P6)) {
		std::cerr << Graphene::String::asPrintf("Failed to load image from \"checkerboard_demo.ppm\": %s\n",
												image.getErrorMessage().cStyleString());
		return 1;
	}

	// Add a green rectangle in the middle of the image
	image.fillRectangle(Graphene::Point(100, 350), 50, 50, Graphene::GREEN);

	// Export the image to a PPM file P3 format
	fileName = "re-exported_ppm_p6_demo.ppm";
	if (!image.exportTo(fileName, Graphene::ImageFormat::PPM_P3)) {
		std::cerr << Graphene::String::asPrintf(
			"Failed to save image to \"%s\": %s\n", fileName.cStyleString(), image.getErrorMessage().cStyleString());
	}

	return 0;
}