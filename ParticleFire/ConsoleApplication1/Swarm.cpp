#include "stdafx.h"
#include "Swarm.h"

// populate particles and various functions related to it.
namespace firefly {

	Swarm::Swarm()
	{
		m_particles = new Particle[NPARTICLES];
	}


	Swarm::~Swarm()
	{
	}

	void Swarm::Update() {
		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			m_particles[i].update();
		}
	}
}