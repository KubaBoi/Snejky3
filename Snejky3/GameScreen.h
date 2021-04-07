#pragma once

#include <vector>
#include <algorithm>
#include "Object.h"
#include "Renderer.h"

using namespace std;

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

class GameScreen
{
private:
	vector<Object*> objects;

public:

	GameScreen();
	void update();
	void input(UINT* uMsg);
	void draw(Renderer* renderer);

	void addGameObject(Object* object);
	void removeGameObject(Object* object);
};

#endif

