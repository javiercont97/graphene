#include <Graphene.h>

#include <fstream>
#include <iostream>

int main() {
#if defined(ENABLE_GRAPHENE_IMAGE_FORMAT)
	// Create a VirtualScreenDriver
	int32_t side = 512;
	Graphene::Image image(side, side);
	image.clear(Graphene::GREEN);

	// Draw a minecraft creeper face
	// nose
	image.fillRectangle({side / 2 - 50, side / 2 - 50}, 100, 50, Graphene::BLACK);
	// eyes
	image.fillRectangle({side / 2 - 150, side / 2 - 150}, 100, 100, Graphene::BLACK);
	image.fillRectangle({side / 2 + 50, side / 2 - 150}, 100, 100, Graphene::BLACK);
	// mouth
	image.fillRectangle({side / 2 - 100, side / 2}, 200, 100, Graphene::BLACK);
	image.fillRectangle({side / 2 - 100, side / 2 + 100}, 50, 50, Graphene::BLACK);
	image.fillRectangle({side / 2 + 50, side / 2 + 100}, 50, 50, Graphene::BLACK);

	// ========================================================================
	// Convert the FrameBuffer to a PPM
	// ========================================================================
	Graphene::String fileName = "creeper.ppm";
	if (!image.exportTo(fileName, Graphene::ImageFormat::PPM_P6)) {
		std::cerr << Graphene::String::asPrintf(
			"Failed to save image to \"%s\": %s\n", fileName.cStyleString(), image.getErrorMessage().cStyleString());
	}
#else
	std::cerr << "Graphene was built without image format support\n";
#endif	// ENABLE_GRAPHENE_IMAGE_FORMAT
	return 0;
}