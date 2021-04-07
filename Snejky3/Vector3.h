#pragma once

#include <math.h>
#include <memory>

using namespace std;

#ifndef VECTOR3_H
#define VECTOR3_H

class Vector3 
{
public:
	double x, y, z;

	Vector3(double pX, double pY, double pZ);

	double selfLength(); //velikost vektoru
	double distance(unique_ptr<Vector3> point); //vzdalenost mezi body
	unique_ptr<Vector3> newVector(unique_ptr<Vector3> point); //vrati vektor od selfBodu do parBodu

	void moveVector(Vector3* vector); //posune bod (soucet vektoru)
	unique_ptr<Vector3> addVector(unique_ptr<Vector3> vector); //vrati posunuty bod (soucet vektoru)
	double scalar(Vector3* vector); //vrati skalarni soucin vektoru
	double angle(Vector3* vector); //vrati uhel mezi vektory
	bool parallelVector(unique_ptr<Vector3> vector); //vrati true pokud jsou vektory rovnobezne
	bool equals(Vector3* vector); //vrati true pokud jsou vektory stejne (velikost i smer)

	unique_ptr<Vector3> reverseVector(); //vrati obraceny vektor
	unique_ptr<Vector3> setVectorLength(double distance); //vrati vektor se stejnym smerem, ale distance velikosti
	unique_ptr<Vector3> multipleVector(double m); //vrati vynasobeny vektor
	unique_ptr<Vector3> normalized(); //vrati normalizovany vektor

	//void rotateAround(Vector3* centroid, Vector3* rotation); //presune 
};

#endif

