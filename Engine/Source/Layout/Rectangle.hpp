#pragma once
#include "Size.hpp"

namespace Engine
{
	namespace Layout
	{
		struct Rectangle
		{
			int x1, y1, x2, y2;

			Rectangle() : x1{}, y1{}, x2{}, y2{} {}
			Rectangle(int x1, int y1, int x2, int y2) : x1{x1}, y1{y1}, x2{x2}, y2{y2} {}
			Rectangle(int x, int y, Size size) : x1{x}, y1{y} { x2 = x + size.width; y2 = y + size.height; }

			Rectangle(const Rectangle& source)
			{
				x1 = source.x1;
				x2 = source.x2;
				y1 = source.y1;
				y2 = source.y2;
			}

			int Width() const { return x2 - x1; }
			int Height() const { return y2 - y1; }
		};
	}
}
