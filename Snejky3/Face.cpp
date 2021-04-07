#include "Face.h"

Face::Face(Vertex* vert1, Vertex* vert2, Vertex* vert3) {
	vertex1 = vert1;
	vertex2 = vert2;
	vertex3 = vert3;
}

Color* Face::getColor() {
	return color;
}

void Face::setColor(Color* pColor) {
	color = pColor;
}

void Face::setNormal() {
	Vector3* v = vertex1->getPosition()->newVector(vertex2->getPosition());
	Vector3* u = vertex1->getPosition()->newVector(vertex3->getPosition());

	normal->x = u->y * v->z - v->y * u->z;
	normal->y = u->z * v->x - v->z * u->x;
	normal->z = u->x * v->y - v->x * u->y;
}