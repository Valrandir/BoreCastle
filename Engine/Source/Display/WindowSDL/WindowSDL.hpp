#pragma once
#include "../Window.hpp"
#include <SDL.h>

namespace Engine
{
	namespace Display
	{
		class WindowSDL : public Window
		{
			int _width, _height;
			SDL_Window* _window{};
			SDL_Renderer* _renderer{};
			SDL_Texture* _fill_texture{};

			bool _is_destroyed;

			public:
			WindowSDL(const char* title, int width, int height);
			WindowSDL(const WindowSDL&) = delete;
			WindowSDL(WindowSDL&&) = delete;
			WindowSDL& operator=(const WindowSDL&) = delete;
			WindowSDL& operator=(WindowSDL&&) = delete;
			~WindowSDL();

			void BeginDraw();
			void DrawRect(int x, int y, int w, int h, Color color);
			void EndDraw();
			bool Update();
			void Close();

			int Width() const;
			int Height() const;

			private:
			void Destroy();
		};
	}
}
