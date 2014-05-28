#ifndef CAR_H
#define CAR_H

#if defined __APPLE__		// Check if Mac OS
#include <OpenGL/gl.h> 
#else
#if defined _WIN32			// Check if Win OS
#include <Windows.h>
#endif
#include <GL/gl.h>			// Include for Win or Linux
#endif


class Car
{
public:

	Car();
	~Car();

	void init();
	void draw(float angle);
	void drawCar();
	void makeShaders();

private:
	static unsigned int m_texture;
    static unsigned int m_frame;

	int width, height, length;
};

#endif