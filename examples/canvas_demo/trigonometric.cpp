#include <Graphene.h>

#include <fstream>
#include <iostream>

int main() {
#if defined(ENABLE_GRAPHENE_IMAGE_FORMAT)
	int32_t width = 1920 / 2;
	int32_t height = 1080 / 2;

	Graphene::Image image(width, height);
	image.clear(Graphene::DARK_GRAY);

	// Draw plotter axes
	image.drawLine({width / 2, 0}, {width / 2, height}, Graphene::WHITE);
	image.drawLine({0, height / 2}, {width, height / 2}, Graphene::WHITE);

	// grid
	image.drawLine({width * 3 / 4, 0}, {width * 3 / 4, height}, Graphene::GRAY);
	image.drawLine({width / 4, 0}, {width / 4, height}, Graphene::GRAY);
	image.drawLine({0, height * 3 / 4}, {width, height * 3 / 4}, Graphene::GRAY);
	image.drawLine({0, height / 4}, {width, height / 4}, Graphene::GRAY);

	uint32_t amplitude = height / 4;
	// Draw a sine wave
	for (int x = 0; x < width; x++) {
		double y = height / 2 + amplitude * sin(2 * M_PI * x / width);
		image.drawPixel({x, (int)y}, Graphene::GREEN);
	}

	// Draw a cosine wave
	for (int x = 0; x < width; x++) {
		double y = height / 2 + amplitude * cos(2 * M_PI * x / width);
		image.drawPixel({x, (int)y}, Graphene::RED);
	}

	// Draw a tangent wave
	for (int x = 0; x < width; x++) {
		double y = height / 2 + amplitude * tan(2 * M_PI * x / width);
		image.drawPixel({x, (int)y}, Graphene::BLUE);
	}

	// Convert the FrameBuffer to a PPM
	Graphene::String fileName = "trigonometric_demo.ppm";

	if (!image.exportTo(fileName, Graphene::ImageFormat::PPM_P6)) {
		std::cerr << Graphene::String::asPrintf(
			"Failed to save image to \"%s\": %s\n", fileName.cStyleString(), image.getErrorMessage().cStyleString());
	}
#else
	std::cerr << "Graphene was built without image format support\n";
#endif	// ENABLE_GRAPHENE_IMAGE_FORMAT
	return 0;
}