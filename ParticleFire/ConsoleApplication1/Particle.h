#pragma once

//particle class, location and movement
namespace firefly {
	class Particle
	{
	public:
		double m_x;
		double m_y;

		double xspeed;
		double yspeed;

	public:
		Particle();
		~Particle();
		void update();
	};
}

