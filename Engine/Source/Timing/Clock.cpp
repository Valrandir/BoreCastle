#include "Clock.hpp"

#include "../Engine.hpp"

namespace Engine
{
	namespace Timing
	{
		Clock::Clock()
		{
			_last_tick = GetTickCount();
		}

		int Clock::Tick()
		{
			long long tick = GetTickCount();
			long long elapsed = tick - _last_tick;
			_last_tick = tick;
			return static_cast<int>(elapsed);
		}
	}
}
