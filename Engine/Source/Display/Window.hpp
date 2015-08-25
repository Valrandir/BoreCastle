#pragma once
#include <stdint.h>
#include "Color.hpp"
#include "Image.hpp"

namespace Engine
{
	namespace Display
	{
		class Window
		{
			public:
			static Window* Create(const char* title, int width, int height);
			Window();
			Window(const Window&) = delete;
			Window(Window&&) = delete;
			Window& operator=(const Window&) = delete;
			Window& operator=(Window&&) = delete;
			virtual ~Window();

			virtual void BeginDraw() = 0;
			virtual void DrawRect(int x, int y, int w, int h, Color color) = 0;
			virtual void DrawImage(int x, int y, const Image* image, Color color = {0xff, 0xff, 0xff}) = 0;
			virtual void EndDraw() = 0;
			virtual bool Update() = 0;
			virtual void Close() = 0;

			virtual Image* LoadImage(const char* file) const = 0;

			virtual int Width() const = 0;
			virtual int Height() const = 0;
		};
	}
}
