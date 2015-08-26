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
			WindowSDL& operator=(const WindowSDL&) = delete;
			~WindowSDL();

			void BeginDraw(bool clear = true);

			void Clear(Color color = Color()) const;
			void EnableClipping(int x, int y, int w, int h) const;
			void DisableClipping() const;
			void DrawRect(int x, int y, int w, int h, Color color) const;
			void DrawImage(int x, int y, const Image* image, Color color = {0xff, 0xff, 0xff}) const;

			void EndDraw();
			bool Update();
			void Close();

			Image* LoadImage(const char* file) const;

			int Width() const;
			int Height() const;

			private:
			void Destroy();
		};
	}
}