#include "Vector3.h"

Vector3::Vector3(double pX, double pY, double pZ) {
	x = pX;
	y = pY;
	z = pZ;
}

double Vector3::selfLength() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double Vector3::distance(unique_ptr<Vector3> point) {
	return sqrt(
		pow(x - point->x, 2) +
		pow(y - point->y, 2) +
		pow(z - point->z, 2)
	);
}

unique_ptr<Vector3> Vector3::newVector(unique_ptr<Vector3> point) {
	return std::make_unique<Vector3>(
		point->x - x,
		point->y - y,
		point->z - z
	);
}

void Vector3::moveVector(Vector3* vector) {
	x += vector->x;
	y += vector->y;
	z += vector->z;
}

unique_ptr<Vector3> Vector3::addVector(unique_ptr<Vector3> vector) {
	return std::make_unique<Vector3>(
		x + vector->x,
		y + vector->y,
		z + vector->z
	);
}

double Vector3::scalar(Vector3* vector) {
	return (x * vector->x) +
		(y * vector->y) +
		(z * vector->z);
}

double Vector3::angle(Vector3* vector) {
	if (selfLength() * vector->selfLength() == 0) {
		return 0;
	}

	double ang = scalar(vector) / (selfLength() * vector->selfLength());
	if (-1 >= ang <= 1) {
		return acos(ang);
	}
	return 0;
}

bool Vector3::parallelVector(unique_ptr<Vector3> vector) {
	return (fabs(normalized()->x) == fabs(vector->normalized()->x) &&
		fabs(normalized()->y) == fabs(vector->normalized()->y) &&
		fabs(normalized()->z) == fabs(vector->normalized()->z));
}

bool Vector3::equals(Vector3* vector) {
	double d = 10000;
	return (int(x * d) == int(vector->x * d) &&
		int(y * d) == int(vector->y * d) &&
		int(z * d) == int(vector->z * d));
}

unique_ptr<Vector3> Vector3::reverseVector() {
	return std::make_unique<Vector3>(x * -1, y * -1, z * -1);
}

unique_ptr<Vector3> Vector3::setVectorLength(double distance) {
	unique_ptr<Vector3> norm = normalized();
	return std::make_unique<Vector3>(norm->x * distance,
		norm->y * distance,
		norm->z * distance
	);
}

unique_ptr<Vector3> Vector3::multipleVector(double m) {
	return std::make_unique<Vector3>(x * m, y * m, z * m);
}

unique_ptr<Vector3> Vector3::normalized() {
	if (selfLength() != 0) {
		return std::make_unique<Vector3>(
			x / selfLength(),
			y / selfLength(),
			z / selfLength()
		);
	}
	return std::make_unique<Vector3>(0, 0, 0);
}