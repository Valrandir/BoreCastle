#pragma once
#include <stdint.h>

namespace Engine
{
	void MessageBox(const wchar_t* caption, const wchar_t* message);
	void Sleep(uint32_t milliseconds);
	uint64_t GetTickCount();
	int Random(int min, int max);
}
