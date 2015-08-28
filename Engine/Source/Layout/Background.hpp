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
			public:
			enum class TileMode { Single, Mosaic, Left, Top, Right, Bottom };

			private:
			TileMode _tile_mode;
			int _x, _y;
			double _scroll_ratio;
			Image* _image;

			public:
			//image is owned by this class, do not delete it from outside.
			Background(TileMode tile_mode, int x, int y, double scroll_ratio, Image* image);

			Background(const Background&) = delete;
			Background& operator=(const Background&) = delete;

			void Render(int offset_x, int offset_y, const Renderer* renderer) const;

			~Background();
		};
	}
}
