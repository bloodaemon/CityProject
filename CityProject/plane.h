#ifndef PLANE_H
#define PLANE_H

#if defined __APPLE__		// Check if Mac OS
#include <OpenGL/gl.h> 
#else
#if defined _WIN32			// Check if Win OS
#include <Windows.h>
#endif
#include <GL/gl.h>			// Include for Win or Linux
#endif

#include <iostream>
#include <vector>

using namespace std;

struct Point{
	float x, y, z;
};

class Plane
{
public:
	Plane();
	~Plane();

	void init(float startX, float startY, float startZ, int stepSize, int tempWidth, int tempLength, char direction);
	void draw();

private:
	vector<vector<Point> > pointArray;
	int width, length;
	bool success, errOnce;
};

#endif