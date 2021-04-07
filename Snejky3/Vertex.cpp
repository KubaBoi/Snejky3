#include "Vertex.h"

Vertex::Vertex(Vector3* pPosition) {
	position = pPosition;
}

void Vertex::update(Camera* camera) {
	setIsInFrontOfCamera(camera);
	findProjection(camera);
}

Vector3* Vertex::getPosition() {
	return position;
}

Vector2* Vertex::getProjection() {
	return projection;
}

bool Vertex::getIsInFromOfCamera() {
	return isInFrontOfCamera;
}

void Vertex::findProjection(Camera* camera) {
	Vector3* G = findG(camera); //prunik primky pohledu a roviny pohledu

	Vector3* g = G->newVector(camera->S); //vektor mezi G a S

	double x = camera->centerOfScreen->x;
	double y = camera->centerOfScreen->y;

	if (g->selfLength() != 0) {
		double alpha = g->angle(camera->up); //uhel mezi g a up

		double beta = M_PI - (M_PI_2 + alpha); //uhel mezi g a kolmici na up

		x = abs(g->selfLength() * sin(alpha)) * camera->maxView;
		y = abs(g->selfLength() * sin(beta)) * camera->maxView;

		double angle1 = g->angle(camera->up);
		double angle2 = g->angle(camera->right);

		if (0 <= angle1 <= M_PI_2 && 0 <= angle2 <= M_PI_2) { //I.kvadrant
			x = camera->centerOfScreen->x + x;
			y = camera->centerOfScreen->y + y;
		}
		else if (0 <= angle1 <= M_PI_2 && angle2 >= M_PI_2) { //II.kvadrant
			x = camera->centerOfScreen->x - x;
			y = camera->centerOfScreen->y + y;
		}
		else if (angle1 >= M_PI_2 && angle2 >= M_PI_2) { //III.kvadrant
			x = camera->centerOfScreen->x - x;
			y = camera->centerOfScreen->y - y;
		}
		else if (angle1 >= M_PI_2 && 0 <= angle2 <= M_PI_2) { //IV.kvadran
			x = camera->centerOfScreen->x + x;
			y = camera->centerOfScreen->y - y;
		}
	}

	projection->x = int(x);
	projection->y = int(y);
}

Vector3* Vertex::findG(Camera* camera) {
	double g1 = position->x;
	double g2 = 0;
	double g3 = position->z;
		
	if (isInFrontOfCamera) {
		g1 = camera->position->x - position->x;
		g2 = camera->position->y - position->y;
		g3 = camera->position->z - position->z;
	}

	double t = 0; //parametr

	double b = (g1 * camera->right->y * camera->up->z -
		g1 * camera->right->z * camera->up->y -
		g2 * camera->right->x * camera->up->z +
		g2 * camera->right->z * camera->up->x +
		g3 * camera->right->x * camera->up->y -
		g3 * camera->right->y * camera->up->x);

	if (b != 0) {
		t = -(position->x * camera->right->y * camera->up->z - position->x * camera->right->z * camera->up->y -
			position->y * camera->right->x * camera->up->z + position->y * camera->right->z * camera->up->x +
			position->z * camera->right->x * camera->up->y - position->z * camera->right->y * camera->up->x +

			camera->right->x * camera->S->y * camera->up->z - camera->right->x * camera->S->z * camera->up->y -
			camera->right->y * camera->S->x * camera->up->z +

			camera->right->y * camera->S->z * camera->up->x - camera->right->z * camera->S->x * camera->up->y -
			camera->right->z * camera->S->y * camera->up->x)
			/ b;
	}

	return new Vector3(
		position->x + t * g1,
		position->y + t * g2,
		position->z + t * g3
	);
}

void Vertex::setIsInFrontOfCamera(Camera* camera) {
	double a = position->distance(camera->S);
	double ac = position->distance(camera->position);

	isInFrontOfCamera = (a <= ac);
}

Vector2* Vertex::fromBack(double side, double bigger, double lower) {
	//zatim nevim co presne dela a jestli je to nutny
	//burger
	return NULL;
}
