#include "stdafx.h"
#include "Swarm.h"

// populate particles and various functions related to it.
namespace firefly {

	Swarm::Swarm(): lastTime(0)
	{
		m_particles = new Particle[NPARTICLES];
	}


	Swarm::~Swarm()
	{
	}

	void Swarm::Update(int elapsed) {

		int interval = elapsed - lastTime;

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_particles[i].Update(interval);
		}

		lastTime = elapsed;
	}
}