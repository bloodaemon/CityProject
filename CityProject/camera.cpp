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
#include "camera.h"

//int objectAngle;

Camera::Camera(){} /*: eyeX(-104.800087), eyeY(-462.997894), eyeZ(-89.500092), deltaMousX(0),
	deltaMousY(0), mousePrevX(0), mousePrevY(0), r(1.0f), lookX(1.0f),
	lookY(2.7f), lookZ(0.0f), theta(0.0f), phi(0.0f)
{}
*/
Camera::~Camera() {}
/*
void Camera::keyMovement(unsigned char key)
{

}

void Camera::mouseMovement(int x, int y)
{
	deltaMousX += x - mousePrevX;
	deltaMousY += y - mousePrevY;

	mousePrevX = x;
	mousePrevY = y;
}

void Camera::update()
{
	gluLookAt(lookX,lookY,lookZ,0,0,0,0,1,0);          //set up camera position and orientation
	//printf("%f %f %f\n", lookX, lookY, lookZ );

	glTranslatef(eyeX, eyeY, eyeZ);
	//printf("%f %f %f\n", eyeX, eyeY, eyeZ );

} */