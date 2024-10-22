#pragma once

#include "Library.h"

class Circle {
public:
	Circle(Color color, float radius, int centerX, int centerY, float angularVelocity = 0.f, float rodLength = 0.f) : color(color), radius(radius), angularVelocity(angularVelocity), rodLength(rodLength), centerX(centerX), centerY(centerY){};

	Color color;
	float radius;
	float angularVelocity;
	float rodLength;
	int centerX, centerY;

};