namespace Engine
{
	namespace Display
	{
		struct ImageLoader
		{
			virtual Image* LoadImage(const char* file) const = 0;
		};
	}
}
