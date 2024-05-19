#include <Graphene.h>

#include <fstream>
#include <iostream>

// #define WIDTH 512
#define WIDTH (150 + 14 * 40)
#define HEIGHT (2 * (150 + 14 * 40))

Graphene::VirtualScreenDriver driver(WIDTH, HEIGHT);

void drawPixel(int x, int y, Graphene::Color color) {
	driver.setForegroundColor(color);
	driver.fillRectangle({x, y}, 40, 40);
}

int main() {
	// Create a VirtualScreenDriver
	driver.clearScreen(Graphene::WHITE);

	// Draw a minecraft creeper face
	driver.setForegroundColor(Graphene::BLACK);
	// frame
	driver.setForegroundColor(Graphene::BLACK);
	driver.fillRectangle({0, 0}, WIDTH, HEIGHT);
	int frameWidth = 50;
	driver.setForegroundColor(Graphene::Color(48, 47, 44));
	driver.fillRectangle({frameWidth, frameWidth}, WIDTH - 2 * frameWidth, HEIGHT - 2 * frameWidth);

	// head
	driver.setForegroundColor(Graphene::Color(118, 118, 118));
	int headMargin = 25;
	driver.fillRectangle({frameWidth + headMargin, frameWidth + headMargin},
						 WIDTH - 2 * frameWidth - 2 * headMargin,
						 HEIGHT - 2 * frameWidth - 2 * headMargin);

	// eyebrows
	driver.setForegroundColor(Graphene::Color(60, 61, 61));
	driver.fillRectangle({frameWidth + headMargin, HEIGHT / 2}, 80, 40);
	driver.fillRectangle({WIDTH - frameWidth - headMargin - 80, HEIGHT / 2}, 80, 40);

	driver.setForegroundColor(Graphene::Color(99, 109, 119));
	driver.fillRectangle({frameWidth + headMargin, HEIGHT / 2 - 40}, 40, 40);
	driver.fillRectangle({WIDTH - frameWidth - headMargin - 40, HEIGHT / 2 - 40}, 40, 40);

	driver.setForegroundColor(Graphene::Color(104, 104, 97));
	driver.fillRectangle({frameWidth + headMargin, HEIGHT / 2 + 40}, 40, 40);
	driver.fillRectangle({WIDTH - frameWidth - headMargin - 40, HEIGHT / 2 + 40}, 40, 40);

	drawPixel(frameWidth + headMargin + 40, HEIGHT / 2 + 40, Graphene::Color(78, 79, 73));

	drawPixel(WIDTH - frameWidth - headMargin - 80, HEIGHT / 2 + 40, Graphene::Color(78, 79, 73));

	driver.setForegroundColor(Graphene::Color(199, 201, 201));
	driver.fillRectangle({frameWidth + headMargin, HEIGHT / 2 + 80}, 80, 120);
	driver.fillRectangle({WIDTH - frameWidth - headMargin - 80, HEIGHT / 2 + 80}, 80, 120);

	drawPixel(frameWidth + headMargin + 80, HEIGHT / 2 + 160, Graphene::Color(199, 201, 201));
	drawPixel(WIDTH - frameWidth - headMargin - 120, HEIGHT / 2 + 160, Graphene::Color(199, 201, 201));

	driver.setForegroundColor(Graphene::Color(142, 141, 137));
	driver.fillRectangle({frameWidth + headMargin, HEIGHT / 2 + 200}, 120, 40);
	driver.fillRectangle({WIDTH - frameWidth - headMargin - 120, HEIGHT / 2 + 200}, 120, 40);

	driver.setForegroundColor(Graphene::Color(105, 124, 146));
	driver.fillRectangle({frameWidth + headMargin + 80, HEIGHT / 2 + 80}, 40, 80);
	driver.fillRectangle({WIDTH - frameWidth - headMargin - 120, HEIGHT / 2 + 80}, 40, 80);

	driver.setForegroundColor(Graphene::Color(66, 91, 120));
	driver.fillRectangle({frameWidth + headMargin + 120, HEIGHT / 2 + 120}, 40, 40);
	driver.fillRectangle({WIDTH - frameWidth - headMargin - 160, HEIGHT / 2 + 120}, 40, 40);

	drawPixel(frameWidth + headMargin + 120, HEIGHT / 2 + 160, Graphene::Color(105, 124, 146));
	drawPixel(WIDTH - frameWidth - headMargin - 160, HEIGHT / 2 + 160, Graphene::Color(105, 124, 146));

	driver.setForegroundColor(Graphene::Color(104, 104, 97));
	driver.fillRectangle({frameWidth + headMargin + 160, HEIGHT / 2 + 120}, 80, 40);
	driver.fillRectangle({WIDTH - frameWidth - headMargin - 240, HEIGHT / 2 + 120}, 80, 40);
	driver.fillRectangle({frameWidth + headMargin + 240, HEIGHT / 2 + 160}, 80, 40);

	drawPixel(frameWidth + headMargin + 160, HEIGHT / 2 + 160, Graphene::Color(58, 69, 81));
	drawPixel(WIDTH - frameWidth - headMargin - 200, HEIGHT / 2 + 160, Graphene::Color(58, 69, 81));

	drawPixel(frameWidth + headMargin + 200, HEIGHT / 2 + 160, Graphene::Color(60, 61, 61));
	drawPixel(WIDTH - frameWidth - headMargin - 240, HEIGHT / 2 + 160, Graphene::Color(60, 61, 61));

	driver.setForegroundColor(Graphene::Color(78, 79, 73));
	driver.fillRectangle({frameWidth + headMargin + 160, HEIGHT / 2 + 200}, 240, 440);

	driver.setForegroundColor(Graphene::Color(60, 61, 61));
	driver.fillRectangle({frameWidth + headMargin + 200, HEIGHT / 2 + 200}, 160, 440);

	// ========================================================================
	// Convert the FrameBuffer to a PPM
	driver.swapBuffers();
	Graphene::FrameBuffer buffer = driver.getCurrentFrame();
	Graphene::String ppm = buffer.toPPM();

	// Write the PPM to a file
	Graphene::String path = "pillager.ppm";
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