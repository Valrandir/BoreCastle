#include "Image.hpp"

namespace Engine
{
	namespace Display
	{
		//Move this into ImageSDL and make Image pure virtual and create it with Display::LoadImage
		Image::Image(const char* file)
		{
			//SDL_Surface* surface = IMG_Load(file);
			//SDL_ConvertSurface(surface, )
			//SDL_FreeSurface(surface);
		}

		Image::~Image()
		{
			_width = 0;
			_height = 0;

			if(_texture)
			{
				SDL_DestroyTexture(_texture);
				_texture = nullptr;
			}
		}

		int Image::Width() const { return _width; }
		int Image::Height() const { return _height; }
	}
}
