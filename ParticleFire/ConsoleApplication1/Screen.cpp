#include "stdafx.h"
#include "Screen.h"

namespace firefly {

	Screen::Screen() :
		m_renderer(NULL),
		m_texture(NULL),
		m_window(NULL),
		m_buffer(NULL)
	{

	}

	bool Screen::Init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			return false;
		}

		m_window = SDL_CreateWindow("Fire and Brimstone", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WINDOW_WIDTH, WINDOW_HEIGHT);

		if (m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		if (m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_buffer = new Uint32[WINDOW_WIDTH * WINDOW_HEIGHT];

		memset(m_buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));

		return true;
	}

	bool Screen::ProcessEvent() {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}

	void Screen::Clear() {
		memset(m_buffer, 0, WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(Uint32));
	}

	void Screen::SetPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

		if (x < 0 || y < 0 || x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT) {
			return;
		}

		Uint32 color = 0;

		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;

		m_buffer[(y * WINDOW_WIDTH) + x] = color;
	}
	
	void Screen::Update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer, WINDOW_WIDTH * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	void Screen::Close() {
		delete[] m_buffer;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	Screen::~Screen()
	{
	}

}