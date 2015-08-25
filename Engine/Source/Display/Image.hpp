#pragma once

namespace Engine
{
	namespace Display
	{
		class Image
		{
			public:
			Image();
			Image(const Image&) = delete;
			Image(Image&&) = delete;
			Image& operator=(const Image&) = delete;
			Image& operator=(Image&&) = delete;
			virtual ~Image();

			int Width() const;
			int Height() const;
		};
	}
}
