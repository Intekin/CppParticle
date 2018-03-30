#pragma once

#include "Particle.h"
namespace firefly {

	class Swarm
	{
	private:
		Particle *m_particles;
		int lastTime; //used for frametrate management. 
	public:
		const static int NPARTICLES = 5000; //If over 500 it crashes. Changed speed and particle location to use float instead of double. Fixed the problem. Problem: double overflow?
		Swarm();
		virtual ~Swarm();
		void Update(int elapsed);

		const Particle * const getParticles() { return m_particles; };

	};

}