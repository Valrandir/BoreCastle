#pragma once

#include "../Display/Color.hpp"
#include "../Display/Image.hpp"
#include "../Display/Renderer.hpp"
#include "../Geometry/Point.hpp"

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
			Point _position;
			double _scroll_ratio;
			const Image* _image;

			public:
			//image is owned by this class, do not delete it from outside.
			Background(TileMode tile_mode, const Point& position, double scroll_ratio, const Image* image);

			Background(const Background&) = delete;
			Background& operator=(const Background&) = delete;

			void Render(const Point& offset, const Renderer* renderer) const;

			~Background();
		};
	}
}
