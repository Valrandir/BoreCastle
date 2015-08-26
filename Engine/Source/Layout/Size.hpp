#pragma once

namespace Engine
{
	namespace Layout
	{
		struct Size
		{
			int width, height;
			Size() : width{}, height{} {}
			Size(int width, int height) : width{width}, height{height} {}
		};
	}
}
