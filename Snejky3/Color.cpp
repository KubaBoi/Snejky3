#include "Color.h"

Color::Color(int pR, int pG, int pB) {
	r = pR;
	g = pG;
	b = pB;
}

void Color::repairColor() {
	if (r > 255) r = 255;
	if (r < 0) r = 0;

	if (g > 255) g = 255;
	if (g < 0) g = 0;

	if (b > 255) b = 255;
	if (b < 0) b = 0;
}