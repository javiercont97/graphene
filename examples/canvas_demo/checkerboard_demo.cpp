#include <Graphene.h>

#include <iostream>

int main() {
	Graphene::Image image(800, 800);

	// Draw a checkerboard pattern
	int rows = 8;
	int cols = 8;
	int cellWidth = image.getWidth() / cols;
	int cellHeight = image.getHeight() / rows;
	for (int row = 0; row < rows; ++row) {
		for (int col = 0; col < cols; ++col) {
			Graphene::Color color = (row + col) % 2 == 0 ? Graphene::WHITE : Graphene::BLACK;
			image.fillRectangle(Graphene::Point(col * cellWidth, row * cellHeight), cellWidth, cellHeight, color);
		}
	}

	// Export the image to a PPM file P6 format
	Graphene::String fileName = "checkerboard_demo.ppm";
	if (!image.exportTo(fileName, Graphene::ImageFormat::PPM_P6)) {
		std::cerr << Graphene::String::asPrintf(
			"Failed to save image to \"%s\": %s\n", fileName.cStyleString(), image.getErrorMessage().cStyleString());
	}

	return 0;
}