#include "Color.hpp"
#include "../Engine.hpp"

namespace Engine
{
	namespace Display
	{
		Color::Color() : red{}, green{}, blue{}, alpha{} {}
		Color::Color(uint8_t red, uint8_t green, uint8_t blue) : red{red}, green{green}, blue{blue}, alpha{0xff} {}
		Color::Color(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) : red{red}, green{green}, blue{blue}, alpha{alpha} {}

		Color Color::White() { return Color{0xff, 0xff, 0xff}; }
		Color Color::Black() { return Color{0x0, 0x0, 0x0}; }
		Color Color::Red() { return Color{0xff, 0x0, 0x0}; }
		Color Color::Green() { return Color{0x0, 0xff, 0x0}; }
		Color Color::Blue() { return Color{0x0, 0x0, 0xff}; }
		Color Color::Teal() { return Color{0x00, 0xff, 0xff}; }
		Color Color::Pink() { return Color{0xff, 0x0, 0xff}; }
		Color Color::Yellow() { return Color{0xff, 0xff, 0x00}; }
		Color Color::Gray() { return Color{0x7f, 0x7f, 0x7f}; }

		Color Color::Random()
		{
			int red = Engine::Random(0, 0xff);
			int green = Engine::Random(0, 0xff);
			int blue = Engine::Random(0, 0xff);

			return Color(red, green, blue);
		}
	}
}
