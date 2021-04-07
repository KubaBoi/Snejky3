#pragma once

#include "Vector3.h"
#include "Renderer.h"
#include "Object.h"

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject: public Object 
{
private:
	Vector3* position;

public:

	GameObject(Vector3* pPosition);

	virtual void update() override;
	virtual void draw(Renderer* renderer) override;
	virtual void input(UINT* uMsg) override;
};

#endif
