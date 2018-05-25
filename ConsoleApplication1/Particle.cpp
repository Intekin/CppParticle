#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>
#include <SDL.h>



Particle::Particle() : m_x(0), m_y(0)
{
	m_Direction = (2 * M_PI * rand()) / RAND_MAX;
	m_Speed = (0.0001 * rand()) / RAND_MAX;
}


Particle::~Particle()
{
}


void Particle::update(int interval) {
	double xspeed = m_Speed * cos(m_Direction);
	double yspeed = m_Speed * sin(m_Direction);

	m_x += xspeed * interval;
	m_y += yspeed * interval;
}
