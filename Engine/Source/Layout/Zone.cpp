#include "Zone.hpp"

namespace Engine
{
	namespace Layout
	{
		Zone::Zone(int width, int height) : _width{width}, _height{height} {}

		//When camera size is smaller then renderer size, render zone at center of renderer.
		//Else render the zone to fill the entire renderer area.
		void Zone::Render(Rectangle camera, const Renderer* renderer) const
		{
			//Not yet

			/*
			int dx = renderer->Width() - camera.Width();
			int dy = renderer->Height() - camera.Height();
			int ox = dx > 0 ? dx / 2 : 0;
			int oy = dy > 0 ? dy / 2 : 0;

			//camera.x1 += ox;
			//camera.y1 += oy;
			//camera.x2 += ox;
			//camera.y2 += oy;

			renderer->EnableClipping(ox, oy, camera.Width(), camera.Height());
			DrawCheckboard(ox, oy, camera, renderer);
			//renderer->DrawRect(0, 0, 10000, 10000, Color::Pink());
			renderer->DisableClipping();
			*/
		}

		int Zone::Width() const { return _width; }
		int Zone::Height() const { return _height; }

		void Zone::DrawCheckboard(int ox, int oy, Rectangle camera, const Renderer* renderer) const
		{
			//No

			/*
			const int size = 32;

			renderer->Clear();

			int sy = oy + ((camera.y1 % size) - size);
			int sx = ox + ((camera.x1 % size) - size);

			for(int y = sy; y < camera.y2; y += size)
			{
				int x = sx + size * (y / size % 2);
				for(; x < camera.x2; x += size + size)
					renderer->DrawRect(x + ox, y + oy, size, size, Color::Gray());
			}
			*/
		}
	}
}
