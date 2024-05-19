#include <Graphene.h>

#include <fstream>
#include <iostream>

int main() {
	// Create a VirtualScreenDriver
	uint32_t width = 800;
	uint32_t height = 480;
	Graphene::VirtualScreenDriver driver(width, height);
	driver.clearScreen(Graphene::DARK_GRAY);

	// Draw some shapes
	driver.setForegroundColor(Graphene::GREEN);
	driver.drawLine({0, 0}, {width, height});

	driver.setForegroundColor(Graphene::LIME);
	driver.drawLine({width, 0}, {0, height});

	driver.setForegroundColor(Graphene::TEAL);
	driver.drawRectangle({width / 4, height / 4}, width / 2 + 1, height / 2 + 1);

	driver.setForegroundColor(Graphene::FUCHSIA);
	driver.drawPixel({width / 2, height / 2});

	driver.setForegroundColor(Graphene::CYAN);
	driver.drawCircle({width / 2, height / 2}, height / 4);

	// Convert the FrameBuffer to a PPM
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();
	Graphene::String ppm = buffer.toPPM();

	// Write the PPM to a file
	Graphene::String path = "output.ppm";
	std::ofstream outfile(path.cStyleString(), std::ios::binary | std::ios::out);

	if (!outfile) {
		std::cerr << "Error opening file for writing." << std::endl;
		return 1;
	}

	outfile << ppm.cStyleString();

	outfile.close();

	// Verify that the data was written successfully
	if (outfile.good()) {
		std::cout << "Data written successfully." << std::endl;
	} else {
		std::cerr << "Error writing data to file." << std::endl;
	}

	return 0;
}