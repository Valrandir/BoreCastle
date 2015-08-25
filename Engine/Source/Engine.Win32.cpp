#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <stdint.h>
#include <stdlib.h>

#undef MessageBox

namespace Engine
{
	void MessageBox(const wchar_t* caption, const wchar_t* message)
	{
		MessageBoxW(0, message, caption, MB_OK | MB_ICONINFORMATION);
	}

	void Sleep(uint32_t milliseconds)
	{
		::Sleep(milliseconds);
	}

	uint64_t GetTickCount()
	{
		static LARGE_INTEGER frequency;
		LARGE_INTEGER counter;

		if(!frequency.QuadPart)
		{
			QueryPerformanceFrequency(&frequency); //counts per second
			frequency.QuadPart /= 1000; //counts per milliseconds
		}

		QueryPerformanceCounter(&counter);

		return counter.QuadPart / frequency.QuadPart;
	}

	int Random(int min, int max)
	{
		static bool initialized;

		if(!initialized)
		{
			srand(::GetTickCount());
			initialized = true;
		}

		return (rand() % (max - min)) + min;
	}
}
