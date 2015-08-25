#pragma once
#include "Clock.hpp"

namespace Engine
{
	namespace Timing
	{
		class Rate
		{
			private:
			Clock _clock;
			int _updates_per_second;
			double _update_per_milliseconds;
			double _accumulated_milliseconds;

			public:
			Rate(int updates_per_second);
			int Update();

			private:
		};
	}
}
