#ifndef CAMERA_H
#define CAMERA_H

#if defined __APPLE__		// Check if Mac OS
#include <OpenGL/gl.h> 
#else
#if defined _WIN32			// Check if Win OS
#include <Windows.h>
#endif
#include <GL/gl.h>			// Include for Win or Linux
#include <GL/glu.h>
#endif

#include <iostream>
#include <math.h>

using namespace std;

class Camera
{
public:
	Camera();
	~Camera();

	void keyMovement(unsigned char key);
	void mouseMovement(int, int);
	void update();

private:
	//float eyeX, eyeY, eyeZ, r, lookX, lookY, lookZ, theta, phi;
	//int mousePrevX, mousePrevY, deltaMousX, deltaMousY;

};

#endif 