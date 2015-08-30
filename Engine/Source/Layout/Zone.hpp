#pragma once
#include "../Display/Renderer.hpp"
#include "../Geometry/Point.hpp"
#include "Background.hpp"
#include <map>

namespace Engine
{
	namespace Layout
	{
		using namespace Display;

		class Zone
		{
			Point _size;
			Point _offset;
			std::map<int, Background*> _layer_list;

			public:
			Zone(const Point& size);
			Zone(const Zone&) = delete;
			Zone& operator=(const Zone&) = delete;
			~Zone();

			//Negative zorder for layers behind sprites, positive zorder for layers in front.
			void AddLayer(int zorder, Background* background);

			void SetOffset(const Point offset);

			//Render only layers with zorder < 0
			void RenderBackground(const Renderer* renderer) const;

			//Render only layers with zorder >= 0
			void RenderForeground(const Renderer* renderer) const;

			int Width() const;
			int Height() const;

			private:
		};
	}
}
