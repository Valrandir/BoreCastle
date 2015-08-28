#include "Background.hpp"

namespace Engine
{
	namespace Layout
	{
		Background::Background(TileMode tile_mode, int x, int y, double scroll_ratio, Image* image) :
			_tile_mode{tile_mode},
			_x{x},
			_y{y},
			_scroll_ratio{scroll_ratio},
			_image{image}
		{}

		void Background::Render(int offset_x, int offset_y, const Renderer* renderer) const
		{
			int x{_x}, y{_y};

			switch(_tile_mode)
			{
				case TileMode::Single:
					renderer->DrawImage(x, y, _image);
					break;
				case TileMode::Right:
					x += renderer->Width() - _image->Width();
				case TileMode::Left:
					y = _y + offset_y * _scroll_ratio;
					for(y = -(y % _image->Height()); y < renderer->Height(); y += _image->Height())
						renderer->DrawImage(x, y, _image);
					break;
				case TileMode::Bottom:
					y += renderer->Height() - _image->Height();
				case TileMode::Top:
					x = _x + offset_x * _scroll_ratio;
					for(x = -(x % _image->Width()); x < renderer->Width(); x += _image->Width())
						renderer->DrawImage(x, y, _image);
					break;
			}
		}

		Background::~Background()
		{
			if(_image)
			{
				delete _image;
				_image = nullptr;
			}
		}
	}
}
