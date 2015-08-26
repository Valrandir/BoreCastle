#pragma once
#include "../Display/Renderer.hpp"
#include "Rectangle.hpp"

namespace Engine
{
	namespace Layout
	{
		using namespace Display;

		class Zone
		{
			int _width, _height;

			public:
			Zone(int width, int height);

			void Render(Rectangle camera, const Renderer* renderer) const;

			int Width() const;
			int Height() const;

			private:
			void DrawCheckboard(int ox, int oy, Rectangle camera, const Renderer* renderer) const;
		};
	}
}
