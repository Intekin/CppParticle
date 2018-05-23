#include <iostream>
#include <SDL.h>

using namespace std;

int main() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	SDL_Quit();

	return 0;
}
