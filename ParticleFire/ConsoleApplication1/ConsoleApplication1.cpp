// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Screen.h"
#include "Swarm.h"
#include <iostream>
#include <SDL.h>
#include <time.h>

#undef main

using namespace std;
using namespace firefly;

int main()
{
	srand(time(NULL));

	Screen screen;

	if (!screen.Init())
		cout << "SDL fucked up";

	Swarm swarm;

	while (true) {
		//Update Particles
		//Draw Particles
		int elapsed = SDL_GetTicks();

		//Particle location update
		swarm.update();

		//draw particles
		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::WINDOW_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::WINDOW_HEIGHT / 2;

			screen.SetPixel(x, y, 128, 128, 128); //default coloring for testing

		}

		//Draw the screen
		screen.Update();

		//Event Checker
		if (screen.ProcessEvent() == false)
			break;	
	}

	screen.Close();

    return 0;
}

