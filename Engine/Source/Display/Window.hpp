#pragma once
#include <stdint.h>
#include "Color.hpp"
#include "Image.hpp"
#include "Renderer.hpp"

namespace Engine
{
	namespace Display
	{
		class Window : public Renderer
		{
			public:
			static Window* Create(const char* title, int width, int height);
			Window() = default;
			Window(const Window&) = delete;
			Window& operator=(const Window&) = delete;
			virtual ~Window();

			virtual void BeginDraw(bool clear = true) = 0;
			virtual void EndDraw() = 0;
			virtual bool Update() = 0;
			virtual void Close() = 0;

			virtual Image* LoadImage(const char* file) const = 0;
		};
	}
}
