#pragma once

namespace Engine
{
	namespace Layout
	{
		struct Point
		{
			int x, y;

			Point() : x{}, y{} {}
			Point(int x, int y) : x{x}, y{y} {}

			Point(const Point& src) { x = src.x; y = src.y; }
			Point& operator=(const Point& src) { x = src.x; y = src.y; return *this; }

			bool operator==(const Point& src) const { return x == src.x && y == src.y; }

			Point operator+(const Point& src) const { return Point{x + src.x, y + src.y}; }
			Point operator-(const Point& src) const { return Point{x - src.x, y - src.y}; }
			Point operator*(const Point& src) const { return Point{x * src.x, y * src.y}; }
			Point operator/(const Point& src) const { return Point{x / src.x, y / src.y}; }

			Point operator+(int val) const { return Point{x + val, y + val}; }
			Point operator-(int val) const { return Point{x - val, y - val}; }
			Point operator*(int val) const { return Point{x * val, y * val}; }
			Point operator/(int val) const { return Point{x / val, y / val}; }

			Point& operator+=(const Point& src) { x + src.x, y + src.y; return *this; }
			Point& operator-=(const Point& src) { x - src.x, y - src.y; return *this; }
			Point& operator*=(const Point& src) { x * src.x, y * src.y; return *this; }
			Point& operator/=(const Point& src) { x / src.x, y / src.y; return *this; }

			Point& operator+=(int val) { x + val, y + val; return *this; }
			Point& operator-=(int val) { x - val, y - val; return *this; }
			Point& operator*=(int val) { x * val, y * val; return *this; }
			Point& operator/=(int val) { x / val, y / val; return *this; }

			Point& operator++() { ++x, ++y; return *this; }
			Point& operator--() { --x, --y; return *this; }
			Point operator++(int) { Point result(*this); ++x, ++y; return result; }
			Point operator--(int) { Point result(*this); --x, --y; return result; }
		};
	}
}
