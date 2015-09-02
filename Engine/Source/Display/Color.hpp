#pragma once
#include <stdint.h>

namespace Engine
{
	namespace Display
	{
		struct Color
		{
			uint8_t
				red,
				green,
				blue,
				alpha;

			Color();
			Color(uint8_t red, uint8_t green, uint8_t blue);
			Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha);

			static Color White();
			static Color Black();
			static Color Red();
			static Color Green();
			static Color Blue();
			static Color Teal();
			static Color Pink();
			static Color Yellow();
			static Color Gray();

			static Color Random();
		};
	}
}
