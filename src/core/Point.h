#if !defined(GRAPHENE_POINT_H)
#define GRAPHENE_POINT_H

#include <math.h>
#include <stdint.h>

#include "String.h"

namespace Graphene {
class Point {
   public:
	Point();

	Point(uint32_t x, uint32_t y);

	Point(const Point &point);

	Point &operator=(const Point &point);

	uint32_t getX() const;

	uint32_t getY() const;

	void setX(uint32_t x);

	void setY(uint32_t y);

	bool operator==(const Point &point) const;

	bool operator!=(const Point &point) const;

	Point operator+(const Point &point) const;

	Point operator-(const Point &point) const;

	Point operator+=(const Point &point);

	Point operator-=(const Point &point);

	uint32_t distanceTo(const Point &point) const;

	String toString() const;

   private:
	uint32_t x;
	uint32_t y;
};

}  // namespace Graphene

#endif	// GRAPHENE_POINT_H
