#include <Engine.hpp>

using namespace Engine::Display;
using namespace Engine::Layout;

#define DATA_PATH "..\\..\\..\\Data\\"

int BoreCastleMain()
{
	const int width = 1920 / 2;
	const int height = 1080 / 2;

	auto window = Window::Create("Hello World!", width, height);

	Image* img_star = window->LoadImage(DATA_PATH "StarTest.png"); //256x256
	Image* img_round = window->LoadImage(DATA_PATH "RoundTest.png"); //64x64

	Background bg_clouds(Background::TileMode::Top, {}, 1.0, window->LoadImage(DATA_PATH "Cloud.png"));

	Image* img_moon = window->LoadImage(DATA_PATH "Moon.png");
	Background bg_moon(Background::TileMode::Single, {width - img_moon->Width(), 0}, 0.0, window->LoadImage(DATA_PATH "Moon.png"));
	
	Background bg_grass(Background::TileMode::Bottom, {}, 1.0, window->LoadImage(DATA_PATH "Grass.png"));
	Background bg_ground(Background::TileMode::Bottom, {}, 2.0, window->LoadImage(DATA_PATH "Ground.png"));
	Background bg_grass_front(Background::TileMode::Bottom, {}, 3.0, window->LoadImage(DATA_PATH "GrassFront.png"));

	Background bg_left(Background::TileMode::Left, {}, 1.0, window->LoadImage(DATA_PATH "RoundTest.png"));
	Background bg_right(Background::TileMode::Right, {}, 1.0, window->LoadImage(DATA_PATH "RoundTest.png"));

	Image* img_sprite = window->LoadImage(DATA_PATH "Sprite.png");
	Sprite sprite_energy(60, img_sprite);

	Point offset;

	while(window->Update())
	{
		window->BeginDraw();

		bg_moon.Render(offset, window);
		bg_clouds.Render(offset, window);
		bg_grass.Render(offset, window);
		bg_ground.Render(offset, window);

		window->DrawImage({0, 0}, img_star, Color::Gray());
		window->DrawImage({400, 0}, img_round);
		window->DrawImage({60, 80}, img_round, Color(0xff, 0x0, 0x0));
		window->DrawImage({160, 180}, img_round, Color(0x80, 0x0, 0x80));
		window->DrawRect({{width / 2 - 10, height / 2 - 10}, {20, 20}}, Color{0xff, 0, 0xff});

		bg_left.Render(offset, window);
		bg_right.Render(offset, window);

		sprite_energy.Draw({530, 55}, window);

		bg_grass_front.Render(offset, window);

		window->EndDraw();

		Engine::Sleep(1U);

		++offset;
	}

	delete img_star;
	delete img_round;
	delete window;
	return 0;
}
