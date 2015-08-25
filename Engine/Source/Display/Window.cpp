#include "WindowSDL\WindowSDL.hpp"
#include "Window.hpp"

namespace Engine
{
	namespace Display
	{
		Window* Window::Create(const char* title, int width, int height)
		{
			return new WindowSDL(title, width, height);
		}

		Window::Window(){}
		Window::~Window(){}
	}
}
