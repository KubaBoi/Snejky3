#include "Vector2.h"

Vector2::Vector2(double pX, double pY) {
	x = pX;
	y = pY;
}

double Vector2::selfLength() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

double Vector2::distance(Vector2* point) {
	return sqrt(
		pow(x - point->x, 2) +
		pow(y - point->y, 2)
	);
}

Vector2* Vector2::newVector(Vector2* point) {
	return new Vector2(
		point->x - x,
		point->y - y
	);
}

void Vector2::moveVector(Vector2* vector) {
	x += vector->x;
	y += vector->y;
}

Vector2* Vector2::addVector(Vector2* vector) {
	return new Vector2(
		x + vector->x,
		y + vector->y
	);
}

double Vector2::scalar(Vector2* vector) {
	return (x * vector->x) +
		(y * vector->y);
}

double Vector2::angle(Vector2* vector) {
	if (selfLength() * vector->selfLength() == 0) {
		return 0;
	}

	float ang = scalar(vector) / (selfLength() * vector->selfLength());
	if (-1 >= ang <= 1) {
		return acos(ang);
	}
	return 0;
}

bool Vector2::parallelVector(Vector2* vector) {
	return (fabs(normalized()->x) == fabs(vector->normalized()->x) &&
		fabs(normalized()->y) == fabs(vector->normalized()->y));
}

bool Vector2::equals(Vector2* vector) {
	float d = 10000;
	return (int(x * d) == int(vector->x * d) &&
		int(y * d) == int(vector->y * d));
}

Vector2* Vector2::reverseVector() {
	return new Vector2(x * -1, y * -1);
}

Vector2* Vector2::setVectorLength(double distance) {
	Vector2* norm = normalized();
	return new Vector2(norm->x * distance,
		norm->y * distance
	);
}

Vector2* Vector2::multipleVector(double m) {
	return new Vector2(x * m, y * m);
}

Vector2* Vector2::normalized() {
	if (selfLength() != 0) {
		return new Vector2(
			x / selfLength(),
			y / selfLength()
		);
	}
	return new Vector2(0, 0);
}