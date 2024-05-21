#include <Graphene.h>

#include <fstream>
#include <iostream>

int main() {
	// Create a VirtualScreenDriver
	uint32_t width = 1920 / 2;
	uint32_t height = 1080 / 2;

	Graphene::VirtualScreenDriver driver(width, height);
	driver.clearScreen(Graphene::DARK_GRAY);

	// Draw plotter axes
	driver.setForegroundColor(Graphene::WHITE);
	driver.drawLine({width / 2, 0}, {width / 2, height});
	driver.drawLine({0, height / 2}, {width, height / 2});

	// grid
	driver.setForegroundColor(Graphene::GRAY);
	driver.drawLine({width * 3 / 4, 0}, {width * 3 / 4, height});
	driver.drawLine({width / 4, 0}, {width / 4, height});
	driver.drawLine({0, height * 3 / 4}, {width, height * 3 / 4});
	driver.drawLine({0, height / 4}, {width, height / 4});

	uint32_t amplitude = height / 4;
	// Draw a sine wave
	driver.setForegroundColor(Graphene::GREEN);
	for (int x = 0; x < width; x++) {
		double y = height / 2 + amplitude * sin(2 * M_PI * x / width);
		driver.drawPixel({x, y});
	}

	// Draw a cosine wave
	driver.setForegroundColor(Graphene::RED);
	for (int x = 0; x < width; x++) {
		double y = height / 2 + amplitude * cos(2 * M_PI * x / width);
		driver.drawPixel({x, y});
	}

	// Draw a tangent wave
	driver.setForegroundColor(Graphene::BLUE);
	for (int x = 0; x < width; x++) {
		double y = height / 2 + amplitude * tan(2 * M_PI * x / width);
		driver.drawPixel({x, y});
	}

	// Convert the FrameBuffer to a PPM
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();
	Graphene::String ppm = buffer.toPPM();

	// Write the PPM to a file
	Graphene::String path = "trigonometric.ppm";
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