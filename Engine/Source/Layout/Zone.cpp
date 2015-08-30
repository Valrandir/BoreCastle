#include "Zone.hpp"

namespace Engine
{
	namespace Layout
	{
		Zone::Zone(const Point& size) : _size{size} {}

		Zone::~Zone()
		{
			for(auto& bg : _layer_list)
				delete bg.second;
		}

		void Zone::AddLayer(int zorder, Background* background)
		{
			_layer_list.insert({zorder, background});
		}

		void Zone::SetOffset(const Point offset)
		{
			_offset = offset;
		}

		void Zone::RenderBackground(const Renderer* renderer) const
		{
			for(auto& bg : _layer_list)
				if(bg.first < 0)
					bg.second->Render(_offset, renderer);
		}

		void Zone::RenderForeground(const Renderer* renderer) const
		{
			for(auto& bg : _layer_list)
				if(bg.first >= 0)
					bg.second->Render(_offset, renderer);
		}

		int Zone::Width() const { return _size.x; }
		int Zone::Height() const { return _size.y; }
	}
}
