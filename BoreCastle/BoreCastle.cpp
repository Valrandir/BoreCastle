#include "Shanoa.hpp"

#include <Engine.hpp>

using namespace Engine::Display;
using namespace Engine::Layout;

#define DATA_PATH "..\\..\\..\\Data\\"

Zone* CreateTestZone(int width, int height, const Window* window);

void OnKey(KeyEvent ke, void* userdata)
{
	if(ke.key == Keys::KeyEscape)
		reinterpret_cast<Window*>(userdata)->Close();
}

int BoreCastleMain()
{
	const int width = 1920 / 2;
	const int height = 1080 / 2;

	Window* window = Window::Create("Hello World!", width, height);
	window->OnKeyEvent(window) = OnKey;

	Shanoa shanoa({130, height - 128 + 2 - 24}, window);

	Zone* zone = CreateTestZone(width, height, window);
	Sprite sprite_energy(24, window->LoadImage(DATA_PATH "Sprite.png"), 60);

	Point zone_offset;
	Rate rate(60);

	while(window->Update())
	{
		for(int i = rate.Update(); i > 0; --i)
		{
			if(GetKeyState(Keys::KeyLeft))
				shanoa.MoveLeft();
			else if(GetKeyState(Keys::KeyRight))
				shanoa.MoveRight();
			else
				shanoa.Stand();

			shanoa.Update();
		}

		window->BeginDraw(false);
		window->Clear({0, 0, 0x20});
			zone->RenderBackground(window);
				sprite_energy.Draw({530, 55}, window);

				shanoa.Render(window);
			zone->RenderForeground(window);
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
	zone->AddLayer(-9, new Background(Background::TileMode::Single, {width - img_moon->Width(), 0}, 0.0, img_moon));
	zone->AddLayer(-5, new Background(Background::TileMode::Top, {}, 1.0, window->LoadImage(DATA_PATH "Cloud.png")));
	zone->AddLayer(-2, new Background(Background::TileMode::Bottom, {}, 1.0, window->LoadImage(DATA_PATH "Grass.png")));
	zone->AddLayer(-1, new Background(Background::TileMode::Bottom, {}, 2.0, window->LoadImage(DATA_PATH "Ground.png")));
	zone->AddLayer(1, new Background(Background::TileMode::Bottom, {}, 3.0, window->LoadImage(DATA_PATH "GrassFront.png")));

	return zone;
}
