#include "Sprite.hpp"

namespace Engine
{
	namespace Display
	{
		Sprite::Sprite(int frame_count, const Image* image, int updates_per_second) :
			_size{image->Width() / frame_count, image->Height()},
			_rate(updates_per_second),
			_image{image},
			_frame_count{frame_count},
			_frame_index{}
		{}

		Sprite::~Sprite()
		{
			if(_image)
			{
				delete _image;
				_image = nullptr;
			}
		}

		void Sprite::Draw(const Point& position, const Renderer* renderer)
		{
			renderer->DrawImage(position, {{_frame_index * _size.x, 0}, {_size.x, _size.y}}, _image);

			_frame_index += _rate.Update();
			if(_frame_index >= _frame_count)
				_frame_index %= _frame_count;
		}
	}
}
