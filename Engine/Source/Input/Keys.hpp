#pragma once

namespace Engine
{
	namespace Input
	{
		enum class Keys
		{
			KeyLeft,
			KeyRight,
			KeyUp,
			KeyDown,

			KeyEscape,
			KeyEnter
		};

		const unsigned int KeyMod_Shift = 0x1;
		const unsigned int KeyMod_Ctrl= 0x2;
		const unsigned int KeyMod_Alt = 0x4;

		enum class KeyDirection
		{
			Down,
			Up
		};

		struct KeyEvent
		{
			KeyDirection up_or_down;
			Keys key;
			unsigned int mod;
		};
	}
}
