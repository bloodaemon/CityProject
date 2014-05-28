/*
 
 ECS 175: Computer Graphics
 UC Davis, Spring 2013
 
 Project 4
 
 */
#ifndef _BUILDINGS_H_
#define _BUILDINGS_H_

#include "cube.h"
#include "pyramid.h"
#include "cylinder.h"
#include "windowTexture.h"
#include "directionsEnum.h"
#include "buildingsEnum.h"

using namespace Building_types;
using namespace Directions;

class Buildings : public Cube, public Pyramid, public Cylinder, public WindowTexture
{
private:
	int buildingMap[100];
	int buildingDirection[100];
	int buildingTex[100];
	void drawBuilding(const float x, const float y, const float z, int style, int direction);
public:
	Buildings();
    ~Buildings();
    void draw();
};




#endif

