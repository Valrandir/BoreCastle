#include "Background.hpp"

namespace Engine
{
	namespace Layout
	{
		Background::Background(TileMode tile_mode, const Point& position, double scroll_ratio, const Image* image) :
			_tile_mode{tile_mode},
			_position{position},
			_scroll_ratio{scroll_ratio},
			_image{image}
		{}

		void Background::Render(const Point& offset, const Renderer* renderer) const
		{
			int x{_position.x}, y{_position.y};

			switch(_tile_mode)
			{
				case TileMode::Single:
					renderer->DrawImage({x, y}, _image);
					break;
				case TileMode::Right:
					x += renderer->Width() - _image->Width();
				case TileMode::Left:
					y = _position.y + static_cast<int>(offset.y * _scroll_ratio);
					for(y = -(y % _image->Height()); y < renderer->Height(); y += _image->Height())
						renderer->DrawImage({x, y}, _image);
					break;
				case TileMode::Bottom:
					y += renderer->Height() - _image->Height();
				case TileMode::Top:
					x = _position.x + static_cast<int>(offset.x * _scroll_ratio);
					for(x = -(x % _image->Width()); x < renderer->Width(); x += _image->Width())
						renderer->DrawImage({x, y}, _image);
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
