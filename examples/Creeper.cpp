#include <Graphene.h>

#include <fstream>
#include <iostream>

int main() {
	// Create a VirtualScreenDriver
	uint32_t side = 512;
	Graphene::VirtualScreenDriver driver(side, side);
	driver.clearScreen(Graphene::GREEN);

	// Draw a minecraft creeper face
	driver.setForegroundColor(Graphene::BLACK);
	// nose
	driver.fillRectangle({side / 2 - 50, side / 2 - 50}, 100, 50);
	// eyes
	driver.fillRectangle({side / 2 - 150, side / 2 - 150}, 100, 100);
	driver.fillRectangle({side / 2 + 50, side / 2 - 150}, 100, 100);
	// mouth
	driver.fillRectangle({side / 2 - 100, side / 2}, 200, 100);
	driver.fillRectangle({side / 2 - 100, side / 2 + 100}, 50, 50);
	driver.fillRectangle({side / 2 + 50, side / 2 + 100}, 50, 50);

	// ========================================================================
	// Convert the FrameBuffer to a PPM
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();
	Graphene::String ppm = buffer.toPPM();

	// Write the PPM to a file
	Graphene::String path = "creeper.ppm";
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