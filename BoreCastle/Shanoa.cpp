#include "Shanoa.hpp"

Shanoa::Shanoa(const Point& position, const ImageLoader* image_loader)
{
	_moving = false;
	_jumping = false;
	_attacking = false;
	_direction = 1;
	_motion.SetPosition(position.ToVector());

	_sprite_stand = new Sprite(10, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_stand.png"), 10);
	_sprite_run = new Sprite(6, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_run.png"), 10);
	_sprite_jump = new Sprite(6, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_jump.png"), 10);
	_sprite_attack = new Sprite(5, image_loader->LoadImage("..\\..\\..\\Data\\Shanoa\\shanoa_attack.png"), 10);
	_sprite_BFS = new Sprite(6, image_loader->LoadImage("..\\..\\..\\Data\\BFS.png"), 10);

	_sprite_active = _sprite_stand;
}

Shanoa::~Shanoa()
{
	auto del = [](Sprite*& sprite)
	{
		if(sprite)
		{
			delete sprite;
			sprite = nullptr;
		}
	};

	del(_sprite_stand);
	del(_sprite_run);
	del(_sprite_jump);
	del(_sprite_attack);
	del(_sprite_BFS);

	_sprite_active = nullptr;
}

void Shanoa::MoveLeft()
{
	if(_jumping || _attacking)
		return;

	_sprite_BFS->SetFlip(true, false);

	_moving = true;
	_direction = -1;
	_motion.SetFriction(1.25);
	_motion.Impulse({static_cast<double>(_direction), 0.0}, 1.0);
}

void Shanoa::MoveRight()
{
	if(_jumping || _attacking)
		return;

	_sprite_BFS->SetFlip(false, false);

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

void Shanoa::Attack()
{
	if(_attacking)
		return;

	_attacking = true;
}

void Shanoa::Update()
{
	if(_attacking)
	{
		_sprite_active = _sprite_attack;
		_sprite_active->SetFlip(_direction == 1, false);

		if(_sprite_attack->FrameIndex() == _sprite_attack->FrameCount() - 1)
			_attacking = false;
	}
	else
	{
		_sprite_active = _jumping ? _sprite_jump : _moving ? _sprite_run : _sprite_stand;
		_sprite_active->SetFlip(_direction == -1, false);
	}

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
	_sprite_active->Draw(_motion.Position().ToPoint(), renderer);

	if(_attacking)
		_sprite_BFS->Draw({Position().x + _direction * 16, Position().y - 64}, renderer);
}

Point Shanoa::Position() const
{
	return _motion.Position().ToPoint();
}

Rectangle Shanoa::Rect() const
{
	return {Position(), {64, 128}};
}
