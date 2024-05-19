#include <Graphene.h>

#include <fstream>
#include <iostream>

int main() {
	// Create a VirtualScreenDriver
	uint32_t side = 512;
	Graphene::VirtualScreenDriver driver(side, side);
	driver.clearScreen(Graphene::BLACK);

	// Draw a checkerboard pattern
	uint32_t squareSize = side / 8;
	Graphene::Color color = Graphene::WHITE;
	for (uint32_t y = 0; y < side; y += squareSize) {
		for (uint32_t x = 0; x < side; x += squareSize) {
			driver.setForegroundColor(color);
			driver.fillRectangle({x, y}, squareSize, squareSize);
			color = (color == Graphene::WHITE) ? Graphene::BLACK : Graphene::WHITE;
		}
		color = (color == Graphene::WHITE) ? Graphene::BLACK : Graphene::WHITE;
	}

	// Convert the FrameBuffer to a PPM
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();
	Graphene::String ppm = buffer.toPPM();

	// Write the PPM to a file
	Graphene::String path = "checkerboard.ppm";
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