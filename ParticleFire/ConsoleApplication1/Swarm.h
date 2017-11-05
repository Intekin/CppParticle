#pragma once

#include "Particle.h"
namespace firefly {

	class Swarm
	{
	private:
		Particle *m_particles;
	public:
		const static int NPARTICLES = 10000;
		Swarm();
		virtual ~Swarm();
		void update();

		const Particle * const getParticles() { return m_particles; };

	};

}