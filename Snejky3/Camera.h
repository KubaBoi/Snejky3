#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include <windows.h>
#include "Vector3.h"
#include "Vector2.h"

#ifndef CAMERA_H 
#define CAMERA_H

class Camera
{
public:
	Vector2* centerOfScreen;
	Vector3* position;
	double speed = 0.1f;
	double viewAngle = M_PI;
	double maxView = 1000;
	double minView = 1; //vzdalenost plochy zobrazeni

	Vector3* forward = new Vector3(0, 0, minView); //vektor dopredu
	Vector3* up = new Vector3(0, minView, 0); //vektor nahoru
	Vector3* right = new Vector3(minView, 0, 0); //vektor doprava
	Vector3* S = new Vector3(0, 0, minView); //stred plochy zobrazeni (od position->forward)

	double rotX = M_PI;
	double rotY = 0;

	Camera(Vector3* pPosition, Vector2* pCenterOfScreen);

	void update();
	void input(UINT* uMsg);
};

#endif
