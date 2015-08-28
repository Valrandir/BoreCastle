#include <Engine.hpp>

using namespace Engine::Display;
using namespace Engine::Layout;

int BoreCastleMain()
{
	const int width = 800;
	const int height = 600;

	auto window = Window::Create("Hello World!", width, height);

	Image* img_star = window->LoadImage("..\\..\\..\\Data\\StarTest.png"); //256x256
	Image* img_round = window->LoadImage("..\\..\\..\\Data\\RoundTest.png"); //64x64

	Background bg_clouds(Background::TileMode::Top, 0, 0, 1.0, window->LoadImage("..\\..\\..\\Data\\Cloud.png"));

	Image* img_moon = window->LoadImage("..\\..\\..\\Data\\Moon.png");
	Background bg_moon(Background::TileMode::Single, width - img_moon->Width(), 0, 0.0, window->LoadImage("..\\..\\..\\Data\\Moon.png"));
	
	Background bg_grass(Background::TileMode::Bottom, 0, 0, 1.0, window->LoadImage("..\\..\\..\\Data\\Grass.png"));
	Background bg_ground(Background::TileMode::Bottom, 0, 0, 2.0, window->LoadImage("..\\..\\..\\Data\\Ground.png"));
	Background bg_grass_front(Background::TileMode::Bottom, 0, 0, 3.0, window->LoadImage("..\\..\\..\\Data\\GrassFront.png"));

	Background bg_left(Background::TileMode::Left, 0, 0, 1.0, window->LoadImage("..\\..\\..\\Data\\RoundTest.png"));
	Background bg_right(Background::TileMode::Right, 0, 0, 1.0, window->LoadImage("..\\..\\..\\Data\\RoundTest.png"));

	int ox{}, oy{};

	while(window->Update())
	{
		window->BeginDraw();

		bg_moon.Render(ox, oy, window);
		bg_clouds.Render(ox, oy, window);
		bg_grass.Render(ox, oy, window);
		bg_ground.Render(ox, oy, window);
		bg_grass_front.Render(ox, oy, window);
		bg_left.Render(ox, oy, window);
		bg_right.Render(ox, oy, window);

		window->DrawImage(0, 0, img_star, Color::Gray());
		window->DrawImage(400, 0, img_round);
		window->DrawImage(60, 80, img_round, Color(0xff, 0x0, 0x0));
		window->DrawImage(160, 180, img_round, Color(0x80, 0x0, 0x80));
		window->DrawRect(width / 2 - 10, height / 2 - 10, 20, 20, Color{0xff, 0, 0xff});

		window->EndDraw();

		Engine::Sleep(1U);

		++ox;
		++oy;
	}

	delete img_star;
	delete img_round;
	delete window;
	return 0;
}
