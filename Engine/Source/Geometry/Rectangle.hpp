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

			Rectangle(const Rectangle& source)
			{
				position = source.position;
				size = source.size;
			}

			Rectangle& operator=(const Rectangle& source)
			{
				position = source.position;
				size = source.size;
				return *this;
			}

			bool operator==(const Rectangle& source) const
			{
				return position == source.position && size == source.size;
			}
		};
	}
}
