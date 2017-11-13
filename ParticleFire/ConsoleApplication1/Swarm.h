#pragma once

#include "Particle.h"
namespace firefly {

	class Swarm
	{
	private:
		Particle *m_particles;
		int lastTime; //used for frametrate management. 
	public:
		const static int NPARTICLES = 5000; //Sets the amount of particles, if over 500 it crashes for some unknown reason.
		Swarm();
		virtual ~Swarm();
		void Update(int elapsed);

		const Particle * const getParticles() { return m_particles; };

	};

}