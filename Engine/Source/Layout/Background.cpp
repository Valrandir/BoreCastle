#include "Background.hpp"

namespace Engine
{
	namespace Layout
	{
		Background::Background() :
			_fixed_image_x{},
			_fixed_image_y{},
			_fixed_image{},
			_tile_image_y{},
			_tile_image_z{},
			_tile_image{}
		{}

		void Background::SetFixedImage(int x, int y, Image* image)
		{
			_fixed_image_x = x;
			_fixed_image_y = y;
			_fixed_image = image;
		}

		void Background::SetTileImage(double z, int y, Image* image)
		{
			_tile_image_y = y;
			_tile_image_z = z;
			_tile_image = image;
		}

		void Background::Render(int offset_x, int offset_y, int width, int height, const Renderer* renderer) const
		{
			if(_fixed_image)
				renderer->DrawImage(_fixed_image_x, _fixed_image_y, _fixed_image);

			if(_tile_image)
			{
				offset_x = offset_x * _tile_image_z;
				int image_width = _tile_image->Width();
				for(int x = -(offset_x % image_width); x < width; x += image_width)
					renderer->DrawImage(x, _tile_image_y, _tile_image);
			}
		}

		Background::~Background()
		{
			if(_fixed_image)
			{
				delete _fixed_image;
				_fixed_image = nullptr;
			}

			if(_tile_image)
			{
				delete _tile_image;
				_tile_image = nullptr;
			}
		}
	}
}
