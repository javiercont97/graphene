#if !defined(GRAPHENE_FONT_H)
#define GRAPHENE_FONT_H

#include <stdint.h>

#include <vector>

namespace Graphene {

class Font {
   public:
	Font() {
	}

	Font(const uint8_t *charmap, uint16_t Width, uint16_t Height) : charmap(charmap), Width(Width), Height(Height) {
	}

	// getters
	uint16_t getWidth() const;
	uint16_t getHeight() const;
	uint8_t *getCharMap() const;
	std::vector<std::vector<uint8_t>> getGlyph(char c) const;

   private:
	const uint8_t *charmap;
	uint16_t Width;
	uint16_t Height;
};
}  // namespace Graphene

#endif	// GRAPHENE_FONT_H
