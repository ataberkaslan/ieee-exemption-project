#pragma once
#include "Circle.h"

void Circle::update(float dt) {
	angle += angularVelocity / 60;
}