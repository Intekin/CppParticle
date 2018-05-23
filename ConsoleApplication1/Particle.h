#pragma once

//particle class, location and movement
namespace firefly {
	class Particle
	{
	public:
		double m_Speed;
		double m_Direction;
	
		double m_x;
		double m_y;
	public:
		Particle();
		~Particle();
		void update(int interval);
	};
}

