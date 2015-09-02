#pragma once
#include <Engine.hpp>
using namespace Engine::Display;
using namespace Engine::Geometry;
using namespace Engine::Timing;

class Shanoa
{
	bool _moving;
	bool _jumping;
	bool _attacking;
	int _direction;
	Motion _motion;
	double _jump_start_y;

	Sprite* _sprite_stand;
	Sprite* _sprite_run;
	Sprite* _sprite_jump;
	Sprite* _sprite_attack;
	Sprite* _sprite_BFS;

	Sprite* _sprite_active;

	public:
	Shanoa(const Point& position, const ImageLoader* image_loader);
	Shanoa(const Shanoa&) = delete;
	Shanoa& operator=(const Shanoa&) = delete;
	~Shanoa();

	void MoveLeft();
	void MoveRight();
	void Jump();
	void Stand();
	void Attack();

	void Update();
	void Render(const Renderer* renderer) const;

	Point Position() const;
	Rectangle Rect() const;
};
