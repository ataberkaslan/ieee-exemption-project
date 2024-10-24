#pragma once

#include "Library.h"

class Circle {
public:
	Circle(Color color, float radius, float angularVelocity = 0.f, float rodLength = 0.f, float angle = 0.f) : color(color), radius(radius), angularVelocity(angularVelocity), rodLength(rodLength), angle(angle){};
	void update(float dt);

	Color color;
	float radius;
	float angularVelocity;
	float rodLength;
	float angle = 0;

};