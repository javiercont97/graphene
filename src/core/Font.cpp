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
