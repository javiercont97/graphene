#if !defined(GRAPHENE_FONT_H)
#define GRAPHENE_FONT_H

#include <stdint.h>

namespace Graphene {

class Font {
   public:
	Font(const uint8_t *charmap, uint16_t Width, uint16_t Height) : charmap(charmap), Width(Width), Height(Height) {
	}

	// getters
	uint16_t getWidth() const;
	uint16_t getHeight() const;

   private:
	const uint8_t *charmap;
	uint16_t Width;
	uint16_t Height;
};
}  // namespace Graphene

#endif	// GRAPHENE_FONT_H
