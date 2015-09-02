#pragma once
#include "Point.hpp"

namespace Engine
{
	namespace Geometry
	{
		struct Rectangle
		{
			Point position;
			Point size;

			Rectangle() {}
			Rectangle(const Point& position, const Point& size) : position{position}, size{size} {}

			Rectangle(const Rectangle& src)
			{
				position = src.position;
				size = src.size;
			}

			Rectangle& operator=(const Rectangle& src)
			{
				position = src.position;
				size = src.size;
				return *this;
			}

			bool operator==(const Rectangle& src) const
			{
				return position == src.position && size == src.size;
			}

			bool Intersect(const Rectangle& src) const
			{
				return
					src.position.x + src.size.x >= position.x &&
					src.position.x <= position.x + size.x &&
					src.position.y + src.size.y >= position.y &&
					src.position.y <= position.y + size.y;
			}
		};
	}
}
