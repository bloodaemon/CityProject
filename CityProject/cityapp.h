/*
	Written by: Kevin Baker
*/
#ifndef CITYAPP_H
#define CITYAPP_H

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

#include "plane.h"
#include "car/movingCar.h"
#include "street/street.h"
#include "sky/sky.h"
#include "billboard/billboard.h"
#include "building/buildings.h"
#include "building/windowTexture.h"
#include "building/buildingsEnum.h"
#include "building/directionsEnum.h"
using namespace Directions;
using namespace Building_types;


class CityApp
{
public:
	CityApp(int argc, char **argv);
	~CityApp();
	void run();

private:
	static void initOpenGL(); 
	static void initWorld();
	static void render();		
	static void update();	

	static void drawObjects();

	static void mouseMove(int x, int y); // Callback for mouse
	static void keyUp(unsigned char, int, int); // Callback for key press
	static void keyDown(unsigned char, int, int);
	static void cameraUpdate();

	const static int width = 1024;	// Window height.
	const static int height = 800;  // Window width.

	static Buildings *buildings; //changed pointer to real object
	static Billboards bb;
	static Street ground;
	static Sky sky;

	static MovingCar movingCars;
};

#endif