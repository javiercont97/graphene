#include "Font.h"

uint16_t Graphene::Font::getWidth() const {
	return this->Width;
}

uint16_t Graphene::Font::getHeight() const {
	return this->Height;
}

uint8_t* Graphene::Font::getCharMap() const {
	return (uint8_t*)this->charmap;
}

std::vector<std::vector<uint8_t>> Graphene::Font::getGlyph(char c) const {
	std::vector<std::vector<uint8_t>> glyph;

	uint32_t index = ((uint32_t)(c - 32)) * (this->Height * this->Width / 8);
	for (uint32_t i = 0; i < this->Height; i++) {
		std::vector<uint8_t> row;
		for (uint32_t j = 0; j < this->Width / 8; j++) {
			row.push_back(this->charmap[index + i * this->Width / 8 + j]);
		}
		glyph.push_back(row);
	}

	return glyph;
}
