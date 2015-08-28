#pragma once
#include "Color.hpp"
#include "Image.hpp"

namespace Engine
{
	namespace Display
	{
		class Renderer
		{
			public:
			Renderer() = default;
			Renderer(const Renderer&) = delete;
			Renderer& operator=(const Renderer&) = delete;

			virtual void Clear(Color color = Color()) const = 0;
			virtual void EnableClipping(int x, int y, int w, int h) const = 0;
			virtual void DisableClipping() const = 0;
			virtual void DrawRect(int x, int y, int w, int h, Color color) const = 0;
			virtual void DrawImage(int x, int y, const Image* image, Color color = {0xff, 0xff, 0xff}) const = 0;
			virtual void DrawImage(int target_x, int target_y, int source_x, int source_y, int source_width, int source_height, const Image* image, Color color = {0xff, 0xff, 0xff}) const = 0;

			virtual int Width() const = 0;
			virtual int Height() const = 0;
		};
	}
}
