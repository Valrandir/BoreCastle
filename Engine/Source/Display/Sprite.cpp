#include "Sprite.hpp"

namespace Engine
{
	namespace Display
	{
		Sprite::Sprite(int updates_per_second, const Image* image) :
			_size{image->Height(), image->Height()},
			_rate(updates_per_second),
			_image{image},
			_count{image->Width() / image->Height()},
			_index{}
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
			renderer->DrawImage(position, {{_index * _size.x, 0}, {_size.x, _size.y}}, _image);

			_index += _rate.Update();
			if(_index >= _count)
				_index %= _count;
		}
	}
}
