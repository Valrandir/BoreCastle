#pragma once
#include "Color.hpp"
#include "Image.hpp"
#include "../Layout/Rectangle.hpp"
#include "../Layout/Point.hpp"

namespace Engine
{
	namespace Display
	{
		using namespace Layout;

		class Renderer
		{
			public:
			Renderer() = default;
			Renderer(const Renderer&) = delete;
			Renderer& operator=(const Renderer&) = delete;

			virtual void Clear(Color color = Color()) const = 0;
			virtual void DrawRect(const Rectangle& rectangle, Color color) const = 0;
			virtual void DrawImage(const Point& position, const Image* image, Color color = {0xff, 0xff, 0xff}) const = 0;
			virtual void DrawImage(const Point& position, Rectangle source, const Image* image, Color color = {0xff, 0xff, 0xff}) const = 0;

			virtual int Width() const = 0;
			virtual int Height() const = 0;
		};
	}
}
