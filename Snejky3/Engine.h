#pragma once

#include <windows.h>
#include "Renderer.h"
#include "GameScreen.h"
#include "GameObject.h"

#ifndef ENGINE_H
#define ENGINE_H

class Engine
{
private:
	Renderer* renderer;
	GameScreen* gameScreen;

public:
	bool running;

	Engine(HWND *win);

	LRESULT input(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	void update();
	void draw();

	void addGameObject(Object* object);
	void removeGameObject(Object* object);
};

#endif

