#pragma once
#include "SDL.h"



class Screen
{
private:
	SDL_Renderer * m_renderer;
	SDL_Texture *m_texture;
	SDL_Window *m_window;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;
	SDL_Event event;

public:
	const static int WINDOW_WIDTH = 800;
	const static int WINDOW_HEIGHT = 600;

public:
	bool Init();
	bool ProcessEvent();
	void SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void Update();
	void Close();
	void BoxBlur();

public:
	Screen();
	~Screen();
};



