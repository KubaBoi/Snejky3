#pragma once

#define _USE_MATH_DEFINES

#include <cmath>
#include "Vector3.h"
#include "Vector2.h"
#include "Camera.h"

#ifndef VERTEX_H
#define VERTEX_H

class Vertex
{
private:
	Vector3* position;
	Vector2* projection = new Vector2(0, 0);
	bool isInFrontOfCamera = true;

	Vector3* findG(Camera* camera); //vrati bod, ve kterem se protina primka pohledu s rovinou promitani

public:
	Vertex(Vector3* pPosition);

	//return
	Vector3* getPosition();
	Vector2* getProjection();
	bool getIsInFromOfCamera();

	void findProjection(Camera* camera); //nalezne obraz vertexu do 2d souradnic
	void setIsInFrontOfCamera(Camera* camera); //vypocete jestli je vertex za kamerou
	Vector2* fromBack(double side, double bigger, double lower); //vrati upravene souradnice vertexu ktery je za kamerou

	void update(Camera* camera);
};

#endif

