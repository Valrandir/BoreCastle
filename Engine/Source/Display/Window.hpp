#pragma once
#include <stdint.h>
#include "Color.hpp"
#include "Image.hpp"
#include "Renderer.hpp"
#include "../Input/Input.hpp"

namespace Engine
{
	namespace Display
	{
		using namespace Input;

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

			using OnKeyProc = void(*)(KeyEvent ke, void* userdata);
			OnKeyProc& OnKeyEvent(void* userdata = nullptr);

			protected:
			void OnKey(KeyEvent ke);

			private:
			struct OnKeyCallback { OnKeyProc proc; void* user_data; } _on_key{};
		};
	}
}
