#if defined(ENABLE_GRAPHENE_IMAGE_FORMAT)

#if !defined(GRAPHENE_IMAGE_H)
#define GRAPHENE_IMAGE_H

#include <cstdint>
#include <fstream>
#include <vector>

#include "../core/Color.h"
#include "../interfaces/AbstractCanvas.h"
#include "../math/Point.h"
#include "../math/Rect.h"

namespace Graphene {
enum class ImageFormat { PPM_P3, PPM_P6 };

class Image : public AbstractCanvas {
   public:
	// Constructors and destructor
	Image();
	Image(uint32_t width, uint32_t height);
	Image(const String &filename, ImageFormat format);
	~Image();

	//=====================================================
	// utility functions
	//=====================================================
   public:
	// Get error message
	String getErrorMessage() const;

	//=====================================================
	// Export functions
	//=====================================================
   private:
	// Export the image to a PPM file (P3 format)
	bool exportToPPM_P3(const String &filename);

	// Export the image to a PPM file (P6 format)
	bool exportToPPM_P6(const String &filename);

   public:
	// export the image to a file with a given format
	bool exportTo(const String &filename, ImageFormat format);

	//=====================================================
	// Import functions
	//=====================================================
   private:
	// Import an image from a PPM file (P3 format)
	bool importFromPPM_P3(const String &filename);

	// Import an image from a PPM file (P6 format)
	bool importFromPPM_P6(const String &filename);

   public:
	// Import an image from a file with a given format
	bool importFrom(const String &filename, ImageFormat format);

	//=====================================================
	// Manipulation functions
	//=====================================================
	//    public:
	// 	// Resize the image to a given width and height
	// 	void resize(uint32_t width, uint32_t height);

	// 	// Rotate the image by a given angle and center
	// 	void rotate(float angle, Point center);

	// 	// Crop the image to a given rectangle
	// 	void crop(Point position, uint32_t width, uint32_t height);

	// 	// Flip the image horizontally
	// 	void flipHorizontal();

	// 	// Flip the image vertically
	// 	void flipVertical();

	// 	// Invert the colors of the image
	// 	void invertColors();

	// 	// Convert the image to grayscale
	// 	void toGrayScale();

	// 	// Convert the image to black and white
	// 	void toBlackAndWhite(uint8_t threshold);

	// 	// Apply a blur effect to the image
	// 	void blur(uint8_t radius);

	//=====================================================
	// Drawing functions
	//=====================================================
   public:
	// Inherited via AbstractCanvas
	virtual void drawPixel(Graphene::Point point, Graphene::Color color);
	virtual void drawLine(Graphene::Point start, Graphene::Point end, Graphene::Color color);
	virtual void drawRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color);
	virtual void fillRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color);
	virtual void drawCircle(Graphene::Point center, int32_t radius, Graphene::Color color);
	virtual void fillCircle(Graphene::Point center, int32_t radius, Graphene::Color color);
	virtual void drawPolygon(std::vector<Graphene::Point> points, Graphene::Color color);
	virtual void fillPolygon(std::vector<Graphene::Point> points, Graphene::Color color);
	virtual void drawString(Graphene::Point position,
							Graphene::String text,
							Graphene::Color color,
							Graphene::Color bgColor,
							Graphene::Font font,
							Graphene::TextAlignment align = TextAlignment::CENTER) override;
	virtual void clear(Graphene::Color color);

   private:
	std::vector<Color> pixels;

	String errorMessage;
};

}  // namespace Graphene

#endif	// GRAPHENE_IMAGE_H

#endif	// ENABLE_GRAPHENE_IMAGE_FORMAT