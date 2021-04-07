#include "Mesh.h"

Mesh::Mesh(Vector3* pPosition) {
	position = pPosition;
}

void Mesh::update(Vector3* pPosition) {
	Vector3* transformVector = position->newVector(pPosition);
	position = pPosition;

	for (int i = 0; i < vertices.size(); i++) {
		Vertex* vert = vertices[i];
		vert->getPosition()->moveVector(transformVector); //posune vertex
	}
}

void Mesh::updateVertices(Camera* camera) {
	for (int i = 0; i < vertices.size(); i++) {
		Vertex* vert = vertices[i];
		vert->update(camera); //vypocte obraz do 2d prostoru
	}
}

void Mesh::draw(Renderer* renderer, Camera* camera) {
	updateVertices(camera);

	for (int i = 0; i < faces.size(); i++) {
		Face* face = faces[i];

		//ani jeden z vertexu neni pred kamerou
		if (!face->vertex1->getIsInFromOfCamera() &&
			!face->vertex2->getIsInFromOfCamera() &&
			!face->vertex3->getIsInFromOfCamera()) {
			continue;
		}

		face->setNormal();
		Vector3* cP = face->vertex1->getPosition()->newVector(camera->position);
		//face je zady ke kamere
		if (face->normal->angle(cP) > M_PI_2) {
			continue;
		}


	}
}

u32 Mesh::calculateColor(Vector3* normal, Vertex* vertex, u32 color, Vector3* light) {
	double brightness = 1;

	//vektor mezi vertexem a svetlem
	Vector3* lv = vertex->getPosition()->newVector(light);
	
	double angle = int((lv->angle(normal) * 180 / M_PI) * brightness);

	//int r = 
	return color;
}