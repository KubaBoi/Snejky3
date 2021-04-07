#pragma once

#include <math.h>

#ifndef VECTOR2_H
#define VECTOR2_H

class Vector2
{
public:
	double x, y;

	Vector2(double pX, double pY);

	double selfLength(); //velikost vektoru
	double distance(Vector2* point); //vzdalenost mezi body
	Vector2* newVector(Vector2* point); //vrati vektor od selfBodu do parBodu

	void moveVector(Vector2* vector); //posune bod (soucet vektoru)
	Vector2* addVector(Vector2* vector); //vrati posunuty bod (soucet vektoru)
	double scalar(Vector2* vector); //vrati skalarni soucin vektoru
	double angle(Vector2* vector); //vrati uhel mezi vektory
	bool parallelVector(Vector2* vector); //vrati true pokud jsou vektory rovnobezne
	bool equals(Vector2* vector); //vrati true pokud jsou vektory stejne (velikost i smer)

	Vector2* reverseVector(); //vrati obraceny vektor
	Vector2* setVectorLength(double distance); //vrati vektor se stejnym smerem, ale distance velikosti
	Vector2* multipleVector(double m); //vrati vynasobeny vektor
	Vector2* normalized(); //vrati normalizovany vektor
};

#endif


