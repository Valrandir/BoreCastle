#include "InputSDL.hpp"

namespace Engine
{
	using namespace Input;

	namespace Display
	{
		KeyEvent ToKeyEvent(uint32_t sdl_event_type, SDL_Keysym sdl_keysym)
		{
			KeyEvent ke{};

			if(sdl_event_type == SDL_KEYDOWN)
				ke.up_or_down = KeyDirection::Down;
			else if(sdl_event_type == SDL_KEYUP)
				ke.up_or_down = KeyDirection::Up;
			else
				return ke;

			switch(sdl_keysym.sym)
			{
				case SDLK_LEFT: ke.key = Keys::KeyLeft; break;
				case SDLK_RIGHT: ke.key = Keys::KeyRight; break;
				case SDLK_UP: ke.key = Keys::KeyUp; break;
				case SDLK_DOWN: ke.key = Keys::KeyDown; break;
				case SDLK_ESCAPE: ke.key = Keys::KeyEscape; break;
				case SDLK_RETURN: ke.key = Keys::KeyEnter; break;
			}

			if(sdl_keysym.mod | KMOD_LSHIFT || sdl_keysym.mod | KMOD_RSHIFT) ke.mod |= KeyMod_Shift;
			if(sdl_keysym.mod | KMOD_LCTRL || sdl_keysym.mod | KMOD_RCTRL) ke.mod |= KeyMod_Ctrl;
			if(sdl_keysym.mod | KMOD_LALT || sdl_keysym.mod | KMOD_RALT) ke.mod |= KeyMod_Alt;

			return ke;
		}
	}
}
