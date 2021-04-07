#pragma once

#include <vector>
#include "Face.h"
#include "Renderer.h"

using namespace std;

#ifndef MESH_H
#define MESH_H

class Mesh
{
private:
	void updateVertices(Camera* camera);
	u32 calculateColor(Vector3* normal, Vertex* vertex, u32 color, Vector3* light);

public:
	vector<Vertex*> vertices;
	vector<Face*> faces;

	Vector3* position;

	Mesh(Vector3* pPosition);

	void update(Vector3* pPosition);
	void draw(Renderer* renderer, Camera* camera);
};

#endif
