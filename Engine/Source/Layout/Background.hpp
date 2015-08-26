#pragma once

#include "../Display/Color.hpp"
#include "../Display/Image.hpp"
#include "../Display/Renderer.hpp"

namespace Engine
{
	namespace Layout
	{
		using namespace Display;

		class Background
		{
			int _fixed_image_x;
			int _fixed_image_y;
			Image* _fixed_image;
			int _tile_image_y;
			double _tile_image_z;
			Image* _tile_image;

			public:
			Background();
			Background(const Background&) = delete;
			Background& operator=(const Background&) = delete;

			//Background class own image pointer
			void SetFixedImage(int x, int y, Image* image);

			//Background class own image pointer
			void SetTileImage(double z, int y, Image* image);

			void Render(int offset_x, int offset_y, int width, int height, const Renderer* renderer) const;

			~Background();
		};
	}
}
