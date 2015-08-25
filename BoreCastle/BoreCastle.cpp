#include <Engine.hpp>

using namespace Engine::Display;

int BoreCastleMain()
{
	auto window = Window::Create("Hello World!", 1280, 1024);

	int cx = window->Width() / 2;
	int cy = window->Height() / 2;

	while(window->Update())
	{
		window->BeginDraw();
		window->DrawRect(cx - 10, cy - 10, 20, 20, Color{0xff, 0, 0xff, 0xff});
		window->EndDraw();

		Engine::Sleep(1U);
	}

	delete window;
	return 0;
}
