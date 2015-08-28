#pragma once
#include "../Display/Renderer.hpp"
#include "../Geometry/Point.hpp"
#include "Background.hpp"
#include <vector>

namespace Engine
{
	namespace Layout
	{
		using namespace Display;

		class Zone
		{
			Point _size;
			Point _offset;
			std::vector<Background*> _background_list;

			public:
			Zone(const Point& size);
			Zone(const Zone&) = delete;
			Zone& operator=(const Zone&) = delete;
			~Zone();

			void AddBackground(Background* background);
			void SetOffset(const Point offset);
			void Render(const Renderer* renderer) const;

			int Width() const;
			int Height() const;

			private:
		};
	}
}
