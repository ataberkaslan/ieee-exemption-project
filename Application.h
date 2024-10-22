#pragma once

#include "Library.h"




class Application {
public:
		
	int static Start();
	void static AddCircle(Color color, float radius, int centerX, int centerY, float angularVelocity = 0.f, float rodLength = 0.f);
	static std::vector<std::unique_ptr<Circle>> circles;
private:
	void static Draw();
};