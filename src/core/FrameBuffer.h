#if !defined(GRAPHENE_FRAME_H)
#define GRAPHENE_FRAME_H

#include <stdint.h>

#include "Color.h"
#include "Point.h"

namespace Graphene {
class FrameBuffer {
   public:
	FrameBuffer(uint32_t width, uint32_t height);
	~FrameBuffer();

	uint32_t getWidth() const;
	uint32_t getHeight() const;

	std::vector<Graphene::Color> getBuffer() const;

	void clear(Color color);
	void setPixel(Point point, Color color);
	void setPixel(uint32_t x, uint32_t y, Color color);
	Color getPixel(Point point) const;
	Color getPixel(uint32_t x, uint32_t y) const;

   private:
	uint32_t width;
	uint32_t height;

	// The frame buffer
	std::vector<Graphene::Color> buffer;
};

}  // namespace Graphene

#endif	// GRAPHENE_FRAME_H
