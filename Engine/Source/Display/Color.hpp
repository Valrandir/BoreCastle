#pragma once
#include <stdint.h>

namespace Engine
{
	namespace Display
	{
		struct Color
		{
			uint8_t r, g, b, a;
			Color() : r{}, g{}, b{}, a{} {}
			Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) : r{r}, g{g}, b{b}, a{a} {}
		};
	}
}
