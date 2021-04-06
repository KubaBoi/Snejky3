#pragma once

#include "Vector.h"
#include "Renderer.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
private:
	Vector* position;

public:

	GameObject(Vector* pPosition);

	void update();
	void draw(Renderer* renderer);
};

#endif
