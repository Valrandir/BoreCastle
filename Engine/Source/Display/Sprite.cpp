#include "Sprite.hpp"

namespace Engine
{
	namespace Display
	{
		Sprite::Sprite(int width, int height, int updates_per_second, const Image* image) :
			_width{width},
			_height{height},
			_rate(updates_per_second),
			_image{image},
			_count{image->Width() / width},
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

		void Sprite::Draw(int x, int y, const Renderer* renderer)
		{
			renderer->DrawImage(x, y, _index * _width, 0, _width, _height, _image);

			_index += _rate.Update();
			if(_index >= _count)
				_index %= _count;
		}
	}
}
