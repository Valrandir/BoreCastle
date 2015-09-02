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
	Sprite sprite_elskeletto(2, window->LoadImage(DATA_PATH "ElSkeletto/ElSkeletto.png"), 5);
	Point elskeletto_position = {450, window->Height() - 128 - 32};

	Point zone_offset;
	Rate rate(60);

	Shape s1(shanoa.Rect());
	Shape s2({elskeletto_position, sprite_elskeletto.Size()});

	//Obvious memory leak
	auto quartz = [](Shape& shape)
	{
		auto& hs = shape.size / 2; //half size
		shape.AddShape(new Shape({{shape.position}, hs}));
		shape.AddShape(new Shape({{shape.position.x + hs.x, shape.position.y}, hs}));
		shape.AddShape(new Shape({{shape.position.x, shape.position.y + hs.y}, hs}));
		shape.AddShape(new Shape({{shape.position.x + hs.x, shape.position.y + hs.y}, hs}));
	};

	quartz(s1);
	quartz(s2);

	s1.MoveTo(shanoa.Position());
	s2.MoveTo(elskeletto_position);

	while(window->Update())
	{
		for(int i = rate.Update(); i > 0; --i)
		{
			if(GetKeyState(Keys::KeyF))
				shanoa.Attack();

			if(GetKeyState(Keys::KeySpace))
				shanoa.Jump();

			if(GetKeyState(Keys::KeyLeft))
			{
				shanoa.MoveLeft();
				--zone_offset;
			}
			else if(GetKeyState(Keys::KeyRight))
			{
				shanoa.MoveRight();
				++zone_offset;
			}
			else
				shanoa.Stand();

			shanoa.Update();

			s1.MoveTo(shanoa.Position());
			s1.Intersect(s2);
		}

		window->BeginDraw(false);
		window->Clear({0, 0, 0x20});
			zone->RenderBackground(window);
				sprite_energy.Draw({530, 55}, window);

				s1.Render(*window);
				s2.Render(*window);

				sprite_elskeletto.Draw(elskeletto_position, window);
				shanoa.Render(window);
			zone->RenderForeground(window);
		window->EndDraw();

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
