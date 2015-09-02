#include "Shanoa.hpp"

Shanoa::Shanoa(const Point& position, const ImageLoader* image_loader)
{
	_moving = false;
	_jumping = false;
	_direction = 0;
	_motion.SetPosition(position.ToVector());

	_sprite_stand = new Sprite(10, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_stand.png"), 10);
	_sprite_run = new Sprite(6, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_run.png"), 10);
	_sprite_jump = new Sprite(6, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_jump.png"), 10);
}

Shanoa::~Shanoa()
{
	if(_sprite_stand)
	{
		delete _sprite_stand;
		_sprite_stand = nullptr;
	}

	if(_sprite_run)
	{
		delete _sprite_run;
		_sprite_run = nullptr;
	}

	if(_sprite_jump)
	{
		delete _sprite_jump;
		_sprite_jump = nullptr;
	}
}

void Shanoa::MoveLeft()
{
	if(_jumping)
		return;

	_moving = true;
	_direction = -1;
	_motion.SetFriction(1.25);
	_motion.Impulse({static_cast<double>(_direction), 0.0}, 1.0);
}

void Shanoa::MoveRight()
{
	if(_jumping)
		return;

	_moving = true;
	_direction = 1;
	_motion.SetFriction(1.25);
	_motion.Impulse({static_cast<double>(_direction), 0.0}, 1.0);
}

void Shanoa::Jump()
{
	if(_jumping)
		return;

	_jumping = true;
	_jump_start_y = _motion.Position().y;

	_motion.SetFriction(1.0);
	
	const int jump_force = 15;

	if(_moving)
		_motion.Impulse({_direction * 1.0, -2.0}, jump_force + jump_force / 2);
	else
		_motion.Impulse({0.0, -1.0}, jump_force);
}

void Shanoa::Stand()
{
	_moving = false;
}

void Shanoa::Update()
{
	if(_jumping)
	{
		_motion.Impulse({0.0, 1}, 1);
		_motion.Update();

		if(_motion.Position().y >= _jump_start_y)
		{
			_motion.SetPosition({_motion.Position().x, _jump_start_y});
			_motion.SetVelocity({});
			_jumping = false;
		}
	}
	else
		_motion.Update();
}

void Shanoa::Render(const Renderer* renderer) const
{
	Sprite* active = _jumping ? _sprite_jump : _moving ? _sprite_run : _sprite_stand;
	active->SetFlip(_direction == -1, false);
	active->Draw(_motion.Position().ToPoint(), renderer);
}

Point Shanoa::Position() const
{
	return _motion.Position().ToPoint();
}

Rectangle Shanoa::Rect() const
{
	return {Position(), {64, 128}};
}
