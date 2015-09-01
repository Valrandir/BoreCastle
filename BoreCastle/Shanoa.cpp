#include "Shanoa.hpp"

Shanoa::Shanoa(const Point& position, const ImageLoader* image_loader)
{
	_moving = false;
	_direction = 0;
	_motion.SetPosition(position.ToVector());
	_motion.SetFriction(1.25);

	_sprite_stand = new Sprite(10, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_stand.png"), 10);
	_sprite_run = new Sprite(6, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_run.png"), 10);
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
}

void Shanoa::MoveLeft()
{
	_moving = true;
	_direction = -1;
	_motion.Impulse({static_cast<double>(_direction), 0.0}, 1.0);
}

void Shanoa::MoveRight()
{
	_moving = true;
	_direction = 1;
	_motion.Impulse({static_cast<double>(_direction), 0.0}, 1.0);
}

void Shanoa::Stand()
{
	_moving = false;
}

void Shanoa::Update()
{
	_motion.Update();
}

void Shanoa::Render(const Renderer* renderer) const
{
	Sprite* active = _moving ? _sprite_run : _sprite_stand;
	active->SetFlip(_direction == -1, false);
	active->Draw(_motion.Position().ToPoint(), renderer);
}

const Point& Shanoa::Position() const
{
	return _motion.Position().ToPoint();
}
