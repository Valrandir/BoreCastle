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
			int _frame_count;
			int _frame_index;
			const Image* _image;
			Rate _rate;

			public:
			Sprite(int frame_count, const Image* image, int updates_per_second);
			Sprite(const Sprite&) = delete;
			Sprite& operator=(const Sprite&) = delete;
			~Sprite();

			void Draw(const Point& position, const Renderer* renderer);
		};
	}
}
