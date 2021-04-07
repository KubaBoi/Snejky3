#pragma once

#include "Vertex.h"
#include "utils.cpp"
#include "Color.h"

#ifndef FACE_H
#define FACE_H

class Face
{
private:
	Color* color = new Color(255, 0, 255);

public:
	Vertex* vertex1;
	Vertex* vertex2;
	Vertex* vertex3;

	Vector3* normal = new Vector3(0, 0, 0);

	Face(Vertex* vert1, Vertex* vert2, Vertex* vert3);

	Color* getColor();

	void setColor(Color* pColor);
	void setNormal();
};

#endif