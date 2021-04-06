#pragma once

#include <windows.h>
#include "Renderer.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine
{

public:
	bool running;
	Renderer *renderer;

	Engine(HWND *win);

	LRESULT input(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void update();
	void draw();
};

#endif

