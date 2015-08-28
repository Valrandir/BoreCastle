#pragma once
#include "Vector.hpp"

namespace Engine
{
	namespace Geometry
	{
		class Motion
		{
			static const double FRICTION;
			Vector _position;
			Vector _velocity;
			double _mass;

			public:
			Motion();
			Motion(const Vector& position, const Vector& velocity, double mass = 1.0);

			Motion(const Motion& src);
			Motion& operator=(const Motion& src);

			Motion& Impulse(Vector direction, double force);
			void Update();

			Vector Position() const;
			Vector Velocity() const;
			double Mass() const;

			Motion& SetPosition(const Vector& position);
			Motion& SetVelocity(const Vector& velocity);
			Motion& SetMass(double mass);
		};
	}
}
