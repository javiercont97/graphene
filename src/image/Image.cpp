#if defined(ENABLE_GRAPHENE_IMAGE_FORMAT)
#include "Image.h"

Graphene::Image::Image() : AbstractCanvas() {
	for (uint32_t i = 0; i < getBounds().getWidth() * getBounds().getHeight(); i++) {
		this->pixels.push_back(Graphene::BLACK);
	}
}

Graphene::Image::Image(uint32_t width, uint32_t height) : AbstractCanvas(width, height) {
	for (uint32_t i = 0; i < width * height; i++) {
		this->pixels.push_back(Graphene::BLACK);
	}
}

Graphene::Image::Image(const String& filename, ImageFormat format) : AbstractCanvas() {
	this->importFrom(filename, format);
}

Graphene::Image::~Image() {
}

Graphene::String Graphene::Image::getErrorMessage() const {
	return this->errorMessage;
}

bool Graphene::Image::exportToPPM_P3(const String& filename) {
	std::ofstream file(filename, std::ios::binary | std::ios::out);
	if (!file) {
		this->errorMessage = "Error opening file for writing.";
		return false;
	}

	file << Graphene::String::asPrintf("P3\n%d %d\n255\n", getBounds().getWidth(), getBounds().getHeight());

	for (int32_t i = 0; i < getBounds().getWidth() * getBounds().getHeight(); i++) {
		file << Graphene::String::asPrintf("%d ", this->pixels[i].getRed());
		file << Graphene::String::asPrintf("%d ", this->pixels[i].getGreen());
		file << Graphene::String::asPrintf("%d ", this->pixels[i].getBlue());
	}

	if (!file.good()) {
		this->errorMessage = "Error writing data to file.";
		file.close();
		return false;
	}

	file.flush();
	file.close();
	return true;
}

bool Graphene::Image::exportToPPM_P6(const String& filename) {
	std::ofstream file(filename, std::ios::binary | std::ios::out);
	if (!file) {
		this->errorMessage = "Error opening file for writing.";
		return false;
	}

	file << Graphene::String::asPrintf("P6\n%d %d\n255\n", getBounds().getWidth(), getBounds().getHeight());

	for (int32_t i = 0; i < getBounds().getWidth() * getBounds().getHeight(); i++) {
		file << this->pixels[i].getRed();
		file << this->pixels[i].getGreen();
		file << this->pixels[i].getBlue();
	}

	if (!file.good()) {
		this->errorMessage = "Error writing data to file.";
		file.close();
		return false;
	}

	file.flush();
	file.close();
	return true;
}

bool Graphene::Image::exportTo(const String& filename, ImageFormat format) {
	switch (format) {
		case ImageFormat::PPM_P3:
			return this->exportToPPM_P3(filename);
		case ImageFormat::PPM_P6:
			return this->exportToPPM_P6(filename);
	}

	this->errorMessage = "Invalid image format";
	return false;
}

bool Graphene::Image::importFromPPM_P3(const String& filename) {
	std::ifstream file(filename, std::ios::binary | std::ios::in);
	if (!file) {
		this->errorMessage = "Error opening file for reading.";
		return false;
	}

	std::string magic;
	file >> magic;
	if (magic != "P3") {
		this->errorMessage = "Invalid magic number.";
		file.close();
		return false;
	}

	uint32_t width;
	uint32_t height;
	file >> width;
	file >> height;
	this->bounds = Graphene::Rect(0, 0, width, height);

	int maxColor;
	file >> maxColor;
	if (maxColor != 255) {
		this->errorMessage = "Invalid max color value.";
		file.close();
		return false;
	}

	this->pixels.clear();
	for (int32_t i = 0; i < getBounds().getWidth() * getBounds().getHeight(); i++) {
		int red, green, blue;
		file >> red;
		file >> green;
		file >> blue;
		this->pixels.push_back(Graphene::Color(red, green, blue));
	}

	if (!file.good()) {
		this->errorMessage = "Error reading data from file.";
		file.close();
		return false;
	}

	file.close();
	return true;
}

bool Graphene::Image::importFromPPM_P6(const String& filename) {
	std::ifstream file(filename, std::ios::binary | std::ios::in);
	if (!file) {
		this->errorMessage = "Error opening file for reading.";
		return false;
	}

	std::string magic;
	file >> magic;
	if (magic != "P6") {
		this->errorMessage = "Invalid magic number.";
		file.close();
		return false;
	}

	uint32_t width;
	uint32_t height;
	file >> width;
	file >> height;
	this->bounds = Graphene::Rect(0, 0, width, height);

	int maxColor;
	file >> maxColor;
	if (maxColor != 255) {
		this->errorMessage = "Invalid max color value.";
		file.close();
		return false;
	}

	this->pixels.clear();

	char extraByte;
	file.read(&extraByte, 1);  // read the newline character

	char red, green, blue;
	for (int32_t i = 0; i < getBounds().getWidth() * getBounds().getHeight(); i++) {
		file.read(&red, 1);
		file.read(&green, 1);
		file.read(&blue, 1);
		this->pixels.push_back(Graphene::Color((uint8_t)red, (uint8_t)green, (uint8_t)blue));
	}

	if (!file.good()) {
		this->errorMessage = "Error reading data from file.";
		file.close();
		return false;
	}

	file.close();
	return true;
}

bool Graphene::Image::importFrom(const String& filename, ImageFormat format) {
	switch (format) {
		case ImageFormat::PPM_P3:
			return this->importFromPPM_P3(filename);
		case ImageFormat::PPM_P6:
			return this->importFromPPM_P6(filename);
	}

	this->errorMessage = "Invalid image format";
	return false;
}

void Graphene::Image::drawPixel(Graphene::Point point, Graphene::Color color) {
	// if out of bounds, return
	if (point.getX() < 0 || point.getX() >= getBounds().getWidth() || point.getY() < 0
		|| point.getY() >= getBounds().getHeight()) {
		return;
	}

	this->pixels[point.getY() * getBounds().getWidth() + point.getX()] = color;
}

void Graphene::Image::drawLine(Graphene::Point start, Graphene::Point end, Graphene::Color color) {
	// Bresenham's line algorithm
	int32_t dx = std::abs((float)end.getX() - (float)start.getX());
	int32_t dy = std::abs((float)end.getY() - (float)start.getY());
	int32_t sx = start.getX() < end.getX() ? 1 : -1;
	int32_t sy = start.getY() < end.getY() ? 1 : -1;
	int32_t err = dx - dy;

	while (true) {
		this->drawPixel(start, color);

		if (start.getX() == end.getX() && start.getY() == end.getY()) {
			break;
		}

		int32_t e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			start.setX(start.getX() + sx);
		}
		if (e2 < dx) {
			err += dx;
			start.setY(start.getY() + sy);
		}
	}
}

void Graphene::Image::drawRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) {
	this->drawLine(position, {position.getX() + width, position.getY()}, color);
	this->drawLine(
		{position.getX() + width, position.getY()}, {position.getX() + width, position.getY() + height}, color);
	this->drawLine(
		{position.getX() + width, position.getY() + height}, {position.getX(), position.getY() + height}, color);
	this->drawLine({position.getX(), position.getY() + height}, position, color);
}

void Graphene::Image::fillRectangle(Graphene::Point position, int32_t width, int32_t height, Graphene::Color color) {
	for (int32_t y = position.getY(); y < position.getY() + height; y++) {
		for (int32_t x = position.getX(); x < position.getX() + width; x++) {
			this->drawPixel({x, y}, color);
		}
	}
}

void Graphene::Image::drawCircle(Graphene::Point center, int32_t radius, Graphene::Color color) {
	// midpoint circle algorithm
	radius = radius - 1;  // consider 0 based indexing

	int x = 0;
	int y = radius;
	int p = 1 - radius;	 // Initial decision parameter

	// Plot the initial point
	drawPixel({center.getX() + x, center.getY() + y}, color);
	drawPixel({center.getX() - x, center.getY() + y}, color);
	drawPixel({center.getX() + x, center.getY() - y}, color);
	drawPixel({center.getX() - x, center.getY() - y}, color);
	drawPixel({center.getX() + y, center.getY() + x}, color);
	drawPixel({center.getX() - y, center.getY() + x}, color);
	drawPixel({center.getX() + y, center.getY() - x}, color);
	drawPixel({center.getX() - y, center.getY() - x}, color);

	// Iteratively plot points using Midpoint Algorithm
	while (x < y) {
		x++;
		if (p < 0)
			p += 2 * x + 1;
		else {
			y--;
			p += 2 * (x - y) + 1;
		}
		drawPixel({center.getX() + x, center.getY() + y}, color);
		drawPixel({center.getX() - x, center.getY() + y}, color);
		drawPixel({center.getX() + x, center.getY() - y}, color);
		drawPixel({center.getX() - x, center.getY() - y}, color);
		drawPixel({center.getX() + y, center.getY() + x}, color);
		drawPixel({center.getX() - y, center.getY() + x}, color);
		drawPixel({center.getX() + y, center.getY() - x}, color);
		drawPixel({center.getX() - y, center.getY() - x}, color);
	}
}

void Graphene::Image::fillCircle(Graphene::Point center, int32_t radius, Graphene::Color color) {
	// midpoint circle algorithm
	radius = radius - 1;  // consider 0 based indexing

	int x = 0;
	int y = radius;
	int p = 1 - radius;	 // Initial decision parameter

	// Plot the initial point
	drawPixel({center.getX() + x, center.getY() + y}, color);
	drawPixel({center.getX() - x, center.getY() + y}, color);
	drawPixel({center.getX() + x, center.getY() - y}, color);
	drawPixel({center.getX() - x, center.getY() - y}, color);
	drawPixel({center.getX() + y, center.getY() + x}, color);
	drawPixel({center.getX() - y, center.getY() + x}, color);
	drawPixel({center.getX() + y, center.getY() - x}, color);
	drawPixel({center.getX() - y, center.getY() - x}, color);

	// draw center line
	drawLine({center.getX() - y, center.getY() + x}, {center.getX() + y, center.getY() + x}, color);

	// Iteratively plot points using Midpoint Algorithm
	while (x < y) {
		x++;
		if (p < 0)
			p += 2 * x + 1;
		else {
			y--;
			p += 2 * (x - y) + 1;
		}
		drawPixel({center.getX() + x, center.getY() + y}, color);
		drawPixel({center.getX() - x, center.getY() + y}, color);
		drawPixel({center.getX() + x, center.getY() - y}, color);
		drawPixel({center.getX() - x, center.getY() - y}, color);
		drawPixel({center.getX() + y, center.getY() + x}, color);
		drawPixel({center.getX() - y, center.getY() + x}, color);
		drawPixel({center.getX() + y, center.getY() - x}, color);
		drawPixel({center.getX() - y, center.getY() - x}, color);

		this->drawLine({center.getX() - x, center.getY() + y}, {center.getX() + x, center.getY() + y}, color);
		this->drawLine({center.getX() - x, center.getY() - y}, {center.getX() + x, center.getY() - y}, color);
		this->drawLine({center.getX() - y, center.getY() + x}, {center.getX() + y, center.getY() + x}, color);
		this->drawLine({center.getX() - y, center.getY() - x}, {center.getX() + y, center.getY() - x}, color);
	}
}

void Graphene::Image::drawPolygon(std::vector<Graphene::Point> points, Graphene::Color color) {
	for (size_t i = 0; i < points.size() - 1; i++) {
		this->drawLine(points[i], points[i + 1], color);
	}
	this->drawLine(points[points.size() - 1], points[0], color);
}

void Graphene::Image::fillPolygon(std::vector<Graphene::Point> points, Graphene::Color color) {
	// Find the bounding box of the polygon
	int32_t minX = points[0].getX();
	int32_t minY = points[0].getY();
	int32_t maxX = points[0].getX();
	int32_t maxY = points[0].getY();

	for (size_t i = 1; i < points.size(); i++) {
		if (points[i].getX() < minX) {
			minX = points[i].getX();
		}
		if (points[i].getY() < minY) {
			minY = points[i].getY();
		}
		if (points[i].getX() > maxX) {
			maxX = points[i].getX();
		}
		if (points[i].getY() > maxY) {
			maxY = points[i].getY();
		}
	}

	// Check if a point is inside the polygon
	auto isInside = [&points](Graphene::Point point) {
		bool isInside = false;
		for (size_t i = 0, j = points.size() - 1; i < points.size(); j = i++) {
			if (((points[i].getY() > point.getY()) != (points[j].getY() > point.getY()))
				&& (point.getX() < (points[j].getX() - points[i].getX()) * (point.getY() - points[i].getY())
										   / (points[j].getY() - points[i].getY())
									   + points[i].getX())) {
				isInside = !isInside;
			}
		}
		return isInside;
	};

	for (int32_t y = minY; y <= maxY; y++) {
		for (int32_t x = minX; x <= maxX; x++) {
			if (isInside({x, y})) {
				this->drawPixel({x, y}, color);
			}
		}
	}
}

void Graphene::Image::drawString(Graphene::Point position,
								 Graphene::String text,
								 Graphene::Color color,
								 Graphene::Color bgColor,
								 Graphene::Font font,
								 Graphene::TextAlignment align) {
	// Center the text
	Graphene::Point textTopLeft;
}

void Graphene::Image::clear(Graphene::Color color) {
	this->pixels.clear();
	for (uint32_t i = 0; i < getBounds().getWidth() * getBounds().getHeight(); i++) {
		this->pixels.push_back(color);
	}
}
#endif	// ENABLE_GRAPHENE_IMAGE_FORMAT