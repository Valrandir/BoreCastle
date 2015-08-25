#include <Engine.hpp>

using namespace Engine::Display;

int BoreCastleMain()
{
	auto window = Window::Create("Hello World!", 800, 600);

	int cx = window->Width() / 2;
	int cy = window->Height() / 2;

	Image* img1 = window->LoadImage("C:\\TFS\\DALA011\\Untitled.png"); //256x256
	Image* img2 = window->LoadImage("C:\\TFS\\DALA011\\Untitled2.png"); //64x64

	while(window->Update())
	{
		window->BeginDraw();
		window->DrawRect(cx - 10, cy - 10, 20, 20, Color{0xff, 0, 0xff});
		window->DrawImage(0, 0, img1);
		window->DrawImage(400, 0, img2);

		window->DrawImage(60, 80, img2, Color(0xff, 0x0, 0x0));
		window->DrawImage(160, 180, img2, Color(0x80, 0x0, 0x80));
		window->EndDraw();

		Engine::Sleep(1U);
	}

	delete img1;
	delete img2;
	delete window;
	return 0;
}
