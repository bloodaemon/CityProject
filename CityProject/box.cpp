#include "box.h"

Box::Box() {}

Box::~Box() {}

void Box::init(float startX, float startY, float startZ, int stepSize, int tempWidth, int tempLength, int tempHeight)
{
	width = tempWidth;
	height = tempHeight;
	length = tempLength;

	front.init(startX, startY, startZ, stepSize, tempWidth, tempHeight, 'u');
	back.init(startX, startY, startZ + (length - 1) * stepSize, stepSize, tempWidth, tempHeight, 'u');
	top.init(startX, startY + (height - 1) * stepSize, startZ, stepSize, tempWidth, tempLength, 'f');
	bottom.init(startX, startY, startZ, stepSize, tempWidth, tempLength, 'f');
	left.init(startX, startY, startZ, stepSize, tempHeight, tempLength, 's');
	right.init(startX - (width - 1) * stepSize, startY, startZ, stepSize, tempHeight, tempLength, 's');
}

void Box::draw()
{
	front.draw();
	back.draw();
	top.draw();
	bottom.draw();
	left.draw();
	right.draw();
}