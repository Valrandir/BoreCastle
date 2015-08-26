#include <Engine.hpp>

using namespace Engine::Display;
using namespace Engine::Layout;

int BoreCastleMain()
{
	const int width = 800;
	const int height = 600;

	auto window = Window::Create("Hello World!", width, height);

	Image* img1 = window->LoadImage("..\\..\\..\\Data\\StarTest.png"); //256x256
	Image* img2 = window->LoadImage("..\\..\\..\\Data\\RoundTest.png"); //64x64

	Zone zone(width, height);
	Rectangle camera(16, 8, Size(width / 2, height / 2));

	Background bg4;
	bg4.SetTileImage(1.0, 0, window->LoadImage("..\\..\\..\\Data\\Cloud.png"));

	Background bg3;
	{
		Image* img = window->LoadImage("..\\..\\..\\Data\\Moon.png");
		bg3.SetFixedImage(width - img->Width(), 0, img);
	}
	bg3.SetTileImage(1.0, height - 64, window->LoadImage("..\\..\\..\\Data\\Grass.png"));

	Background bg2;
	bg2.SetTileImage(2.0, height - 32, window->LoadImage("..\\..\\..\\Data\\Ground.png"));

	Background bg1;
	bg1.SetTileImage(3.0, height - 96, window->LoadImage("..\\..\\..\\Data\\GrassFront.png"));

	int ox = 0;

	while(window->Update())
	{
		window->BeginDraw();

		bg3.Render(ox, 0, width, height, window);
		bg2.Render(ox, 0, width, height, window);
		bg1.Render(ox, 0, width, height, window);
		zone.Render(camera, window);

		window->DrawImage(0, 0, img1, Color::Gray());

		window->DrawImage(400, 0, img2);
		window->DrawImage(60, 80, img2, Color(0xff, 0x0, 0x0));
		window->DrawImage(160, 180, img2, Color(0x80, 0x0, 0x80));

		window->DrawRect(width / 2 - 10, height / 2 - 10, 20, 20, Color{0xff, 0, 0xff});

		bg4.Render(ox, 0, width, height, window);
		window->EndDraw();

		Engine::Sleep(1U);

		++ox;
	}

	delete img1;
	delete img2;
	delete window;
	return 0;
}
