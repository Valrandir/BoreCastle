#include "ImageSDL.hpp"
#include <SDL_image.h>

namespace Engine
{
	namespace Display
	{
		ImageSDL::ImageSDL(const char* file, SDL_Renderer* renderer)
		{
			SDL_Surface* surface = IMG_Load(file);

			_width = surface->w;
			_height = surface->h;
			_texture = SDL_CreateTextureFromSurface(renderer, surface);

			SDL_FreeSurface(surface);
		}

		ImageSDL::~ImageSDL()
		{
			_width = 0;
			_height = 0;

			if(_texture)
			{
				SDL_DestroyTexture(_texture);
				_texture = nullptr;
			}
		}

		SDL_Texture* ImageSDL::Texture() const { return _texture; }
		int ImageSDL::Width() const { return _width; }
		int ImageSDL::Height() const { return _height; }
	}
}
