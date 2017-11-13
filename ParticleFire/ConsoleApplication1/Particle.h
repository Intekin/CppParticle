#pragma once

//particle class, location and movement
namespace firefly {
	class Particle
	{
	public:
		float m_x;
		float m_y;

		float m_speed;
		float m_direction;

	public:
		Particle();
		~Particle();
		void Update(int interval);
	};
}

