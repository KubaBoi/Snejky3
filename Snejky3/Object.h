#pragma once
#include "Renderer.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:

	Object();

	virtual void update();
	virtual void draw(Renderer* renderer);
	virtual void input(UINT* uMsg);
};

#endif

