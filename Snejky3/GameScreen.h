#pragma once

#include <vector>
#include <algorithm>
#include "GameObject.h"
#include "Renderer.h"

using namespace std;

#ifndef GAMESCREEN_H
#define GAMESCREEN_H

class GameScreen
{
private:
	vector<GameObject*> objects;

public:

	GameScreen();
	void update();
	void draw(Renderer* renderer);

	void addGameObject(GameObject* object);
	void removeGameObject(GameObject* object);
};

#endif

