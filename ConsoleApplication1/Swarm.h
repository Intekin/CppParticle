#pragma once

#include "Particle.h"
namespace firefly {

	class Swarm
	{
	private:
		Particle *m_pParticles;
		int lastTime;
	public:
		const static int NPARTICLES = 10000;
		Swarm();
		virtual ~Swarm();
		void update(int elapsed);

		const Particle * const getParticles() { return m_pParticles; };

	};

}