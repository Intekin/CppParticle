#pragma once

#include "Particle.h"
namespace firefly {

	class Swarm
	{
	private:
		Particle *m_particles;
	public:
		const static int NPARTICLES = 100; //sets the amount of particles created
		Swarm();
		virtual ~Swarm();
		void Update();

		const Particle * const getParticles() { return m_particles; };

	};

}