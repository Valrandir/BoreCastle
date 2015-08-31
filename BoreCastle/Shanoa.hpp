#pragma once
#include <Engine.hpp>
using namespace Engine::Display;
using namespace Engine::Geometry;

class Shanoa
{
	bool _moving;
	int _direction;
	Motion _motion;

	Sprite* _sprite_stand;
	Sprite* _sprite_run;

	public:
	Shanoa(const Point& position, const ImageLoader* image_loader);
	Shanoa(const Shanoa&) = delete;
	Shanoa& operator=(const Shanoa&) = delete;
	~Shanoa();

	void MoveLeft();
	void MoveRight();
	void Stand();

	void Update();
	void Render(const Renderer* renderer) const;

	const Point& Position() const;
};
