#include <Engine.hpp>

using namespace Engine::Display;
using namespace Engine::Layout;

#define DATA_PATH "..\\..\\..\\Data\\"

Zone* CreateTestZone(int width, int height, const Window* window);

int BoreCastleMain()
{
	const int width = 1920 / 2;
	const int height = 1080 / 2;

	Window* window = Window::Create("Hello World!", width, height);

	Zone* zone = CreateTestZone(width, height, window);
	Image* img_sprite = window->LoadImage(DATA_PATH "Sprite.png");
	Sprite sprite_energy(60, img_sprite);

	Point zone_offset;

	while(window->Update())
	{
		window->BeginDraw();

		zone->Render(window);
		sprite_energy.Draw({530, 55}, window);

		window->EndDraw();

		++zone_offset;
		zone->SetOffset(zone_offset);
	}

	delete zone;
	delete window;
	return 0;
}

Zone* CreateTestZone(int width, int height, const Window* window)
{
	Zone* zone = new Zone({width, height});

	Image* img_moon = window->LoadImage(DATA_PATH "Moon.png");
	zone->AddBackground(new Background(Background::TileMode::Single, {width - img_moon->Width(), 0}, 0.0, img_moon));

	zone->AddBackground(new Background(Background::TileMode::Top, {}, 1.0, window->LoadImage(DATA_PATH "Cloud.png")));
	zone->AddBackground(new Background(Background::TileMode::Bottom, {}, 1.0, window->LoadImage(DATA_PATH "Grass.png")));
	zone->AddBackground(new Background(Background::TileMode::Bottom, {}, 2.0, window->LoadImage(DATA_PATH "Ground.png")));
	zone->AddBackground(new Background(Background::TileMode::Left, {}, 1.0, window->LoadImage(DATA_PATH "RoundTest.png")));
	zone->AddBackground(new Background(Background::TileMode::Right, {}, 1.0, window->LoadImage(DATA_PATH "RoundTest.png")));
	zone->AddBackground(new Background(Background::TileMode::Bottom, {}, 3.0, window->LoadImage(DATA_PATH "GrassFront.png")));

	return zone;
}
