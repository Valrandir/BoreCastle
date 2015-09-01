#include "Keys.hpp"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace Engine
{
	namespace Input
	{
		unsigned int ToVirtualKeyCode(Keys key)
		{
			switch(key)
			{
				case Keys::KeyLeft: return VK_LEFT;
				case Keys::KeyRight: return VK_RIGHT;
				case Keys::KeyUp: return VK_UP;
				case Keys::KeyDown: return VK_DOWN;
				case Keys::KeyEscape: return VK_ESCAPE;
				case Keys::KeyReturn: return VK_RETURN;
				case Keys::KeySpace: return VK_SPACE;
			}

			return 0;
		}

		bool GetKeyState(Keys key)
		{
			return ::GetAsyncKeyState(ToVirtualKeyCode(key)) != 0;
		}
	}
}
