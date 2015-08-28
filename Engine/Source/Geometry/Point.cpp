#include "Point.hpp"

namespace Engine
{
	namespace Geometry
	{
		Point::Point() : x{}, y{} {}
		Point::Point(int x, int y) : x{x}, y{y} {}

		Point::Point(const Point& src) { x = src.x; y = src.y; }
		Point& Point::operator=(const Point& src) { x = src.x; y = src.y; return *this; }

		Point Point::operator-() const { return Point(-x, -y); }
		bool Point::operator==(const Point& src) const { return x == src.x && y == src.y; }

		Point Point::operator+(const Point& src) const { return Point{x + src.x, y + src.y}; }
		Point Point::operator-(const Point& src) const { return Point{x - src.x, y - src.y}; }
		Point Point::operator*(const Point& src) const { return Point{x * src.x, y * src.y}; }
		Point Point::operator/(const Point& src) const { return Point{x / src.x, y / src.y}; }

		Point Point::operator+(int val) const { return Point{x + val, y + val}; }
		Point Point::operator-(int val) const { return Point{x - val, y - val}; }
		Point Point::operator*(int val) const { return Point{x * val, y * val}; }
		Point Point::operator/(int val) const { return Point{x / val, y / val}; }

		Point& Point::operator+=(const Point& src) { x + src.x, y + src.y; return *this; }
		Point& Point::operator-=(const Point& src) { x - src.x, y - src.y; return *this; }
		Point& Point::operator*=(const Point& src) { x * src.x, y * src.y; return *this; }
		Point& Point::operator/=(const Point& src) { x / src.x, y / src.y; return *this; }

		Point& Point::operator+=(int val) { x + val, y + val; return *this; }
		Point& Point::operator-=(int val) { x - val, y - val; return *this; }
		Point& Point::operator*=(int val) { x * val, y * val; return *this; }
		Point& Point::operator/=(int val) { x / val, y / val; return *this; }

		Point& Point::operator++() { ++x, ++y; return *this; }
		Point& Point::operator--() { --x, --y; return *this; }
		Point Point::operator++(int) { Point result(*this); ++x, ++y; return result; }
		Point Point::operator--(int) { Point result(*this); --x, --y; return result; }
	}
}
