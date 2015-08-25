#pragma once
#include <SDL.h>
#include <SDL_image.h>

namespace Engine
{
	namespace Display
	{
		class Image
		{
			int _width{}, _height{};
			SDL_Texture* _texture;

			public:
			Image(const char* file);
			Image(const Image&) = delete;
			Image(Image&&) = delete;
			Image& operator=(const Image&) = delete;
			Image& operator=(Image&&) = delete;
			~Image();

			int Width() const;
			int Height() const;
		};
	}
}
