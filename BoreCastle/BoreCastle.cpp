#include <Engine.hpp>

using namespace Engine::Display;
using namespace Engine::Layout;

int BoreCastleMain()
{
	const int width = 800;
	const int height = 600;

	auto window = Window::Create("Hello World!", width, height);

	Image* img1 = window->LoadImage("..\\..\\..\\Data\\Untitled.png"); //256x256
	Image* img2 = window->LoadImage("..\\..\\..\\Data\\Untitled2.png"); //64x64

	Zone zone(width, height);
	Rectangle camera(16, 8, Size(width / 2, height / 2));

	while(window->Update())
	{
		window->BeginDraw();

		zone.Render(camera, window);

		window->DrawImage(0, 0, img1, Color::Gray());

		window->DrawImage(400, 0, img2);
		window->DrawImage(60, 80, img2, Color(0xff, 0x0, 0x0));
		window->DrawImage(160, 180, img2, Color(0x80, 0x0, 0x80));

		window->DrawRect(width / 2 - 10, height / 2 - 10, 20, 20, Color{0xff, 0, 0xff});

		window->EndDraw();

		Engine::Sleep(1U);
	}

	delete img1;
	delete img2;
	delete window;
	return 0;
}
