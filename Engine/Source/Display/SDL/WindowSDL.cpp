#include "WindowSDL.hpp"
#include "ImageSDL.hpp"

namespace Engine
{
	namespace Display
	{
		WindowSDL::WindowSDL(const char* title, int width, int height) : _width{width}, _height{height}
		{
			_is_destroyed = true;

			_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

			if(_window == nullptr)
				return;

			_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(_renderer == nullptr)
			{
				Destroy();
				return;
			}

			_is_destroyed = false;
		}

		WindowSDL::~WindowSDL()
		{
			Destroy();
		}

		void WindowSDL::BeginDraw(bool clear)
		{
			if(clear)
				Clear();
		}

		void WindowSDL::Clear(Color color) const
		{
			SDL_SetRenderDrawColor(_renderer, color.red, color.green, color.blue, color.alpha);
			SDL_RenderClear(_renderer);
		}
		
		void WindowSDL::EnableClipping(int x, int y, int w, int h) const
		{
			SDL_Rect rect{x, y, w, h};
			SDL_RenderSetClipRect(_renderer, &rect);
			//SDL_RenderSetViewport(_renderer, &rect);
		}

		void WindowSDL::DisableClipping() const
		{
			SDL_RenderSetClipRect(_renderer, nullptr);
			//SDL_RenderSetViewport(_renderer, nullptr);
		}

		void WindowSDL::DrawRect(int x, int y, int w, int h, Color color) const
		{
			SDL_SetRenderDrawColor(_renderer, color.red, color.green, color.blue, color.alpha);
			SDL_Rect rect{x, y, w, h};
			SDL_RenderFillRect(_renderer, &rect);
		}

		void WindowSDL::DrawImage(int x, int y, const Image* image, Color color) const
		{
			const ImageSDL* image_sdl = dynamic_cast<const ImageSDL*>(image);
			SDL_Texture* texture = image_sdl->Texture();
			SDL_SetTextureColorMod(texture, color.red, color.green, color.blue);
			SDL_Rect target{x, y, image_sdl->Width(), image_sdl->Height()};
			SDL_RenderCopy(_renderer, texture, nullptr, &target);
		}

		void WindowSDL::DrawImage(int target_x, int target_y, int source_x, int source_y, int source_width, int source_height, const Image* image, Color color) const
		{
			const ImageSDL* image_sdl = dynamic_cast<const ImageSDL*>(image);
			SDL_Texture* texture = image_sdl->Texture();
			SDL_SetTextureColorMod(texture, color.red, color.green, color.blue);
			SDL_Rect source{source_x, source_y, source_width, source_height};
			SDL_Rect target{target_x, target_y, source_width, source_height};
			SDL_RenderCopy(_renderer, texture, &source, &target);
		}

		void WindowSDL::EndDraw()
		{
			SDL_RenderPresent(_renderer);
		}

		bool WindowSDL::Update()
		{
			if(_is_destroyed)
				return false;

			SDL_Event e;
			while(SDL_PollEvent(&e))
			{
				if(e.type == SDL_WINDOWEVENT && e.window.event == SDL_WINDOWEVENT_CLOSE)
					_is_destroyed = true;
			}

			return !_is_destroyed;
		}

		void WindowSDL::Close()
		{
			_is_destroyed = true;
		}
		
		Image* WindowSDL::LoadImage(const char* file) const
		{
			return new ImageSDL(file, _renderer);
		}

		int WindowSDL::Width() const { return _width; }
		int WindowSDL::Height() const { return _height; }

		void WindowSDL::Destroy()
		{
			_width = 0;
			_height = 0;
			_is_destroyed = true;

			if(_fill_texture)
			{
				SDL_DestroyTexture(_fill_texture);
				_fill_texture = nullptr;
			}

			if(_renderer)
			{
				SDL_DestroyRenderer(_renderer);
				_renderer = nullptr;
			}

			if(_window)
			{
				SDL_DestroyWindow(_window);
				_window = nullptr;
			}
		}
	}
}
