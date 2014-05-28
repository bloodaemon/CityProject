#ifndef MOVINGCAR_H
#define MOVINGCAR_H

#if defined __APPLE__		// Check if Mac OS
#include <OpenGL/gl.h> 
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#else
#if defined _WIN32			// Check if Win OS
#include <Windows.h>
#endif
#include <GL/glew.h>
#include <GL/gl.h>			// Include for Win or Linux
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include "car.h"

class MovingCar
{
public:
	MovingCar();
	~MovingCar();

	void init();
	void draw( int i);
	float getX(int index);
	float getZ(int index);


private:
	void curve(float firstX, float firstY, float secondX, float secondY,
                float thirdX, float thirdY, float fourthX, float fourthY);
	void drawPic();
	double bezier(double A, double B, double C, double D, double t);
	Car car;
	int width, height, length;
};

#endif