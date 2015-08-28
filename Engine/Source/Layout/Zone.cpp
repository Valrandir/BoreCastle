#include "Zone.hpp"

namespace Engine
{
	namespace Layout
	{
		Zone::Zone(const Point& size) : _size{size} {}

		Zone::~Zone()
		{
			for(auto& bg : _background_list)
				delete bg;
		}

		void Zone::AddBackground(Background* background)
		{
			_background_list.push_back(background);
		}

		void Zone::SetOffset(const Point offset)
		{
			_offset = offset;
		}

		void Zone::Render(const Renderer* renderer) const
		{
			for(auto& bg : _background_list)
				bg->Render(_offset, renderer);
		}

		int Zone::Width() const { return _size.x; }
		int Zone::Height() const { return _size.y; }
	}
}
