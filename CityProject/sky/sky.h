#ifndef SKY_H
#define SKY_H

#if defined __APPLE__		// Check if Mac OS
#include <OpenGL/gl.h> 
#else
#if defined _WIN32			// Check if Win OS
#include <Windows.h>
#endif
#include <GL/gl.h>			// Include for Win or Linux
#endif

class Sky
{
public:

	Sky();
	~Sky();

	void init();
	void draw();
	void drawMap();
	void makeShaders();

private:
	static unsigned int m_texture, m_texture2;
    static unsigned int m_frame;
	int width, height, length;
};

#endif