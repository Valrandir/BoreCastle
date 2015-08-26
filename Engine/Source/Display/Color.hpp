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

			Color() : red{}, green{}, blue{}, alpha{} {}
			Color(uint8_t red, uint8_t green, uint8_t blue) : red{red}, green{green}, blue{blue}, alpha{0xff} {}
			Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : red{red}, green{green}, blue{blue}, alpha{alpha} {}

			static Color White() { return Color{0xff, 0xff, 0xff}; }
			static Color Black() { return Color{0x0, 0x0, 0x0}; }
			static Color Red() { return Color{0xff, 0x0, 0x0}; }
			static Color Green() { return Color{0x0, 0xff, 0x0}; }
			static Color Blue() { return Color{0x0, 0x0, 0xff}; }
			static Color Teal() { return Color{0x00, 0xff, 0xff}; }
			static Color Pink() { return Color{0xff, 0x0, 0xff}; }
			static Color Yellow() { return Color{0xff, 0xff, 0x00}; }
			static Color Gray() { return Color{0x7f, 0x7f, 0x7f}; }
		};
	}
}
