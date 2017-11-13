

#include "stdafx.h"
#include "Particle.h"
#include <SDL.h>
#include <stdlib.h>

namespace firefly {

	Particle::Particle(): m_x(0), m_y(0){
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		m_speed = 0.0001f * rand() / RAND_MAX;
	}


	Particle::~Particle()
	{
	}


	void Particle::Update(int interval) {
		float xspeed = m_speed * cos(m_direction);
		float yspeed = m_speed * sin(m_direction);

		m_x += xspeed * interval;
		m_y += yspeed * interval;
	}
}