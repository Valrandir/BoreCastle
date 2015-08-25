#pragma once

namespace Engine
{
	namespace Timing
	{
		class Clock
		{
			private:
			long long _last_tick;

			public:
			Clock();
			int Tick();
		};
	}
}
