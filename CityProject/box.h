#ifndef BOX_H
#define BOX_H

#include "plane.h"

class Box
{
public:
	Box();
	~Box();

	void init(float startX, float startY, float startZ, int stepSize, int tempWidth, int tempLength, int height);
	void draw();

private:
	Plane front, back, top, bottom, left, right;
	int width, height, length;
};

#endif