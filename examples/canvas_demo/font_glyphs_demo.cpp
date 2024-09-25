#include <Graphene.h>

#include <fstream>
#include <iostream>

int main() {
#if defined(ENABLE_GRAPHENE_IMAGE_FORMAT)
	Graphene::Image image(128, 64);
	image.clear(Graphene::GREEN);

	image.drawString(Graphene::Rect(0, 0, 128, 64),
					 "Hello, World!",
					 Graphene::WHITE,
					 Graphene::DARK_GRAY,
					 Graphene::SYSTEM::getSystemFont("ubuntu_light_9px"),
					 Graphene::TextAlignment::CENTER);

	Graphene::Font font = Graphene::SYSTEM::getSystemFont("ubuntu_light_9px");

	// 0x00,   -> '        '
	// 0x00,   -> '        '
	// 0x60,   -> ' ##     '
	// 0x60,   -> ' ##     '
	// 0xe0,   -> '###     '
	// 0xf0,   -> '####    '
	// 0xf0,   -> '####    '
	// 0x90,   -> '#  #    '
	// 0x00,   -> '        '
	// char c = 'A'; // 0x41

	// 0x00,   -> '        '
	// 0x00,   -> '        '
	// 0xc0,   -> '##      '
	// 0xc0,   -> '##      '
	// 0xc0,   -> '##      '
	// 0x80,   -> '#       '
	// 0x80,   -> '#       '
	// 0xc0,   -> '##      '
	// 0x80,   -> '#       '
	// c = '!'; // 0x21

	// 0x00,   -> '        '
	// 0x80,   -> '#       '
	// 0x80,   -> '#       '
	// 0x80,   -> '#       '
	// 0x00,   -> '        '
	// 0x00,   -> '        '
	// 0x00,   -> '        '
	// 0x00,   -> '        '
	// 0x00,   -> '        '
	// c = '\''; // 0x20

	// for (char c = 20; c < 127; c++) {
	for (char c = 32; c <= 42; c++) {
		std::vector<std::vector<uint8_t>> glyph = font.getGlyph(c);
		uint32_t index = ((uint32_t)(c - 32)) * (font.getHeight());

		std::cout << Graphene::String::asPrintf("Glyph for '%c' (%d)[%d]:\n", c, (int)c, index);

		Graphene::String glyphStr = "\"";
		for (uint16_t y = 0; y < font.getHeight(); y++) {
			for (uint16_t x = 0; x < font.getWidth() / 8; x++) {
				const char *bit_rep[16] = {
					[0] = "0000",
					[1] = "0001",
					[2] = "0010",
					[3] = "0011",
					[4] = "0100",
					[5] = "0101",
					[6] = "0110",
					[7] = "0111",
					[8] = "1000",
					[9] = "1001",
					[10] = "1010",
					[11] = "1011",
					[12] = "1100",
					[13] = "1101",
					[14] = "1110",
					[15] = "1111",
				};

				glyphStr += Graphene::String::asPrintf("%s", bit_rep[glyph[y][x]]);
			}
			glyphStr += "\"\n";
		}
		std::cout << glyphStr;
		// for (uint16_t y = 0; y < font.getHeight(); y++) {
		// 	std::cout << "\"";
		// 	for (uint16_t x = 0; x < font.getWidth(); x++) {
		// 		std::cout << (glyph[y][x] ? '#' : ' ');
		// 	}
		// 	std::cout << "\"\n";
		// }
	}

	// ========================================================================
	// Convert the FrameBuffer to a PPM
	// ========================================================================
	Graphene::String fileName = "font_demo.ppm";
	if (!image.exportTo(fileName, Graphene::ImageFormat::PPM_P6)) {
		std::cerr << Graphene::String::asPrintf(
			"Failed to save image to \"%s\": %s\n", fileName.cStyleString(), image.getErrorMessage().cStyleString());
	}
#else
	std::cerr << "Graphene was built without image format support\n";
#endif	// ENABLE_GRAPHENE_IMAGE_FORMAT
	return 0;
}