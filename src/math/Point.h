#if !defined(GRAPHENE_POINT_H)
#define GRAPHENE_POINT_H

#include <math.h>
#include <stdint.h>

#include "../core/String.h"

// DEPRECATED

namespace Graphene {
class Point {
   public:
	Point();

	Point(int32_t x, int32_t y);

	Point(const Point &point);

	Point &operator=(const Point &point);

	int32_t getX() const;

	int32_t getY() const;

	void setX(int32_t x);

	void setY(int32_t y);

	bool operator==(const Point &point) const;

	bool operator!=(const Point &point) const;

	Point operator+(const Point &point) const;

	Point operator-(const Point &point) const;

	Point operator+=(const Point &point);

	Point operator-=(const Point &point);

	int32_t distanceTo(const Point &point) const;

	String toString() const;

   private:
	int32_t x;
	int32_t y;
};

}  // namespace Graphene

#endif	// GRAPHENE_POINT_H
