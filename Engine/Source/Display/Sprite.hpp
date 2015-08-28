#pragma once
#include "../Timing/Rate.hpp"
#include "Image.hpp"
#include "Renderer.hpp"

namespace Engine
{
	namespace Display
	{
		using namespace Timing;

		class Sprite
		{
			Point _size;
			Rate _rate;
			const Image* _image;
			int _count;
			int _index;

			public:
			Sprite(int updates_per_second, const Image* image);
			Sprite(const Sprite&) = delete;
			Sprite& operator=(const Sprite&) = delete;
			~Sprite();

			void Draw(const Point& position, const Renderer* renderer);
		};
	}
}
