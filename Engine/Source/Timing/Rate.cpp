#include "Rate.hpp"

namespace Engine
{
	namespace Timing
	{
		Rate::Rate(int updates_per_second) :
			_updates_per_second{updates_per_second},
			_update_per_milliseconds{updates_per_second / 1000.0},
			_accumulated_milliseconds{}
		{}

		int Rate::Update()
		{
			double milliseconds_elapsed = _clock.Tick() + _accumulated_milliseconds;
			double update_count = milliseconds_elapsed * _update_per_milliseconds;
			int rounded_update_count = static_cast<int>(update_count);
			_accumulated_milliseconds = (update_count - rounded_update_count) / _update_per_milliseconds;
			return rounded_update_count;
		}
	}
}
