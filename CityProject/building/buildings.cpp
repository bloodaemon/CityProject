/*
 
 ECS 175: Computer Graphics
 UC Davis, Spring 2013
 
 Project 4
 
*/

#ifdef __APPLE__
#include <GL/glew.h>
#include <OpenGL/gl.h> 
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

#else
 
#ifdef _WIN32
#include <Windows.h>
#endif

#include <GL/glew.h>
#include <GL/gl.h> 
#include <GL/glu.h>
#include <GL/glut.h>
#endif

#include "buildings.h"
#include "cube.h"
#include "pyramid.h"
#include "cylinder.h"
#include "windowTexture.h"
#include "buildingsEnum.h"
#include "directionsEnum.h" 
#include <iostream> 
#include <cmath>
#include <cstdlib>

#define numTex 5 //number of textures excluding the one used for mailbox

using namespace std;
using namespace Directions;
using namespace Building_types; 

Buildings::Buildings()
{
    int i;
    //top right corner
    //small
    for(i = 0; i < 10; i++)
    {
        buildingMap[i] = rand()%4;
        buildingDirection[i] = rand()%4;
    }

    //middle right side
    //medium
    for (i = 10; i < 18; i++)
    {
        buildingMap[i] = (rand()%4)+4;
        buildingDirection[i] = rand()%4;
    }

    //bottom right corner
    //small
    for(i = 18; i < 26; i++)
    {
        buildingMap[i] = rand()%4;
        buildingDirection[i] = rand()%4;
    }

    //top middle
    //medium
    for(i = 26; i < 36; i++)
    {
        buildingMap[i] = (rand()%4)+4;
        buildingDirection[i] = rand()%4;
    }

    //middle middle
    //large
    for(i = 36; i < 44; i++)
    {
        buildingMap[i] = (rand()%6)+8;
        buildingDirection[i] = rand()%4;
    }

    //bottom middle
    //medium
    for(i = 44; i < 52; i++)
    {
        buildingMap[i] = (rand()%4)+4;
        buildingDirection[i] = rand()%4;
    }

    //top left corner
    //small
    for(i = 52; i < 62; i++)
    {
        buildingMap[i] = rand()%4;
        buildingDirection[i] = rand()%4;
    }

    //middle left side
    //medium
    for(i = 62; i < 70; i++)
    {
        buildingMap[i] = (rand()%4)+4;
        buildingDirection[i] = rand()%4;
    }

    //bottom left corner
    //small
    for(i = 70; i < 78; i++)
    {
        buildingMap[i] = rand()%4;
        buildingDirection[i] = rand()%4;
    }

    //set which texture to use for each building
    for(i = 0; i < 78; i++)
    {
        buildingTex[i] = rand()%numTex;
    }

    
}

Buildings::~Buildings(){}

void Buildings::drawBuilding(const float x, const float y, const float z, int style, int direction)
{
   int height;
    if(style == ROUND_CAKE)
    {
        //symmetrical, so don't need to do anything with direction
        glPushMatrix();
        glTranslated(x+10,y,z+10);
        drawCylinder(20,20,20);
        drawCylinder(15,15,60);
        drawCylinder(10,10,100);
        glPopMatrix();
    }
    else if(style == SQUARE_CAKE)
    {
        //symmetrical, so don't need to do anything with direction
        glPushMatrix();
        glTranslated(x,y,z);
        drawCube(20,20,20);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x+2.5,y,z+2.5);
        drawCube(15,15,60);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x+5,y,z+5);
        drawCube(10,10,100);
        glPopMatrix();
    }
    /*else if(style == PYRAMID_CAKE)
    {
        //symmedtric, so don't need to do anything with direction
        glPushMatrix();
        glTranslated(x,y,z);
        drawPyramid(20,20,20);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x+2.5,y,z+2.5);
        drawPyramid(15,15,60);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x+5,y,z+5);
        drawPyramid(10,10,100);
        glPopMatrix();
    }*/
    else if(style == CUBE_CORP_SMALL || style == CUBE_CORP_MEDIUM || style == CUBE_CORP_LARGE)
    {
        if(style == CUBE_CORP_SMALL)
        {
            height = 20;
        }
        else if(style == CUBE_CORP_MEDIUM)
        {
            height = 60;
        }
        else //CUBE_CORP_LARGE
        {
            height = 100;
        }
        //symmetrical, so don't need to do anything with direction
        glPushMatrix();
        glTranslated(x,y,z);
        drawCube(20,20,height);
        glPopMatrix();
    }
    else if(style == CYLINDER_CORP_SMALL || style == CYLINDER_CORP_MEDIUM || style == CYLINDER_CORP_LARGE)
    {
        if(style == CYLINDER_CORP_SMALL)
        {
            height = 20;
        }
        else if(style == CYLINDER_CORP_MEDIUM)
        {
            height = 60;
        }
        else //CYLINDER_CORP_LARGE
        {
            height = 100;
        }
        //symmetrical, so don't need to do anything with direction
        glPushMatrix();
        glTranslated(x+10,y,z+10);
        drawCylinder(20,20,height);
        glPopMatrix();
    }
    /*else if(style == PYRAMID_CORP_SMALL || style == PYRAMID_CORP_MEDIUM || style == PYRAMID_CORP_LARGE)
    {
        if(style == PYRAMID_CORP_SMALL)
        {
            height = 20;
        }
        else if(style == PYRAMID_CORP_MEDIUM)
        {
            height = 60;
        }
        else //PYRAMID_CORP_LARGE
        {
            height = 100;
        }
        //symmetrical, so don't need to do anything with direction
        glPushMatrix();
        glTranslated(x,y,z);
        drawPyramid(20,20,height);
        glPopMatrix();
    }*/
    else if(style == ELLIPSE_CORP_SMALL || style == ELLIPSE_CORP_MEDIUM || style == ELLIPSE_CORP_LARGE)
    {
        if(style == ELLIPSE_CORP_SMALL)
        {
            height = 20;
        }
        else if(style == ELLIPSE_CORP_MEDIUM)
        {
            height = 60;
        }
        else //ELLIPSE_CORP_LARGE
        {
            height = 100;
        }

        glPushMatrix();
        glTranslated(x+10,y,z+10);

        if(direction == NORTH || direction == SOUTH)
        {
            drawCylinder(20,10,height);
        }
        else if(direction == EAST || direction == WEST)
        {
            drawCylinder(10,20,height);
        }
        else
        {
            cout << "ERROR: Invalid direction" << endl;
        }

        glPopMatrix();
    }
    else if(style == PYRAMID_CUBE_SMALL || style == PYRAMID_CUBE_MEDIUM || style == PYRAMID_CUBE_LARGE)
    {
        if(style == PYRAMID_CUBE_SMALL)
        {
            height = 20;
        }
        else if(style == PYRAMID_CUBE_MEDIUM)
        {
            height = 60;
        }
        else //PYRAMID_CUBE_LARGE
        {
            height = 100;
        }

        glPushMatrix();
        glTranslated(x,y,z);
        drawCube(20,20,height*0.75);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x,y+(height*0.75),z);
        drawPyramid(20,20,height*0.25);
        glPopMatrix();


    }
    else if(style == SONY_JAPAN_SMALL || style == SONY_JAPAN_MEDIUM || style == SONY_JAPAN_LARGE)
    {
        if(style == SONY_JAPAN_SMALL)
        {
            height = 20;
        }
        else if(style == SONY_JAPAN_MEDIUM)
        {
            height = 60;
        }
        else //style == SONY_JAPAN_LARGE
        {
            height = 100;
        }

        glPushMatrix();
        glTranslated(x+10,y,z+10);
        drawCylinder(20,20,height);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x+10,y,z+5);
        drawCube(30,10,height*0.75);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x+5,y,z+10);
        drawCube(10,30,height*0.75);
        glPopMatrix();
    }
    else if(style == CROSS_SMALL || style == CROSS_MEDIUM || style == CROSS_LARGE)
    {
        if(style == CROSS_SMALL)
        {
            height = 20;
        }
        else if(style == CROSS_MEDIUM)
        {
            height = 60;
        }
        else //CROSS_LARGE
        {
            height = 100;
        }

        //symmetrical, so don't need to do anything with direction
        glPushMatrix();
        glTranslated(x,y,z+10);
        drawCube(40,20,height);
        glPopMatrix();

        glPushMatrix();
        glTranslated(x+10,y,z);
        drawCube(20,40,height);
        glPopMatrix();
    }
    else if(style == MAILBOX)
    {   
        glPushMatrix();
        glTranslated(x,y,z);

        glBegin(GL_QUADS);
            glTexCoord2f(0,0); //texture coordinate of first vertex
            glVertex3f(0,0,0);   //first vertex
            
            glTexCoord2f(1.0,0); //texture coordinate of second vertex
            glVertex3f(5,0,0);   //second vertex
            
            glTexCoord2f(1.0,1.0);  //texture coordinate of third vertex
            glVertex3f(5,5,0);    //third vertex

            glTexCoord2f(0,1.0);  //texture coordinate of fourth vertex
            glVertex3f(0,5,0);    //fourth vertex
        glEnd();

        glBegin(GL_QUADS);
            glTexCoord2f(0,0); //texture coordinate of first vertex
            glVertex3f(2.5,0,-2.5);   //first vertex
            
            glTexCoord2f(1.0,0); //texture coordinate of second vertex
            glVertex3f(2.5,0,2.5);   //second vertex
            
            glTexCoord2f(1.0,1.0);  //texture coordinate of third vertex
            glVertex3f(2.5,5,2.5);    //third vertex

            glTexCoord2f(0,1.0);  //texture coordinate of fourth vertex
            glVertex3f(2.5,5,-2.5);    //fourth vertex
        glEnd();

        glPopMatrix();  
    }
    else
    {
        cout << "ERROR: Invalid style" << endl;
    }
}

void Buildings::draw()
{
    int x;
    int i;
    int j = 0;

    //top right corner
    x = -200;
    for(i = 0; i < 3; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,26, buildingMap[i], buildingDirection[i]);
    }

    //SONY_JAPAN_SMALL
    rebindTexture(buildingTex[j++]);
    drawBuilding(x,0,26, SONY_JAPAN_SMALL, buildingDirection[i]);

    x = -200;
    for(i = 5; i < 8; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,46, buildingMap[i], buildingDirection[i]);
    }

    //middle right side
    x = -32;
    for(i = 10; i < 12; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,26, buildingMap[i], buildingDirection[i]);
    }

    //CROSS_MEDIUM
    rebindTexture(1);
    j++;
    drawBuilding(x,0,26, CROSS_MEDIUM, buildingDirection[i]);

    x = -32;
    for(i = 14; i < 16; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,46, buildingMap[i], buildingDirection[i]);
    }

    //bottom right corner
    x = 112;
    for(i = 18; i < 22; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,26, buildingMap[i], buildingDirection[i]);
    }

    x = 112;
    for(i = 22; i < 26; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,46, buildingMap[i], buildingDirection[i]);
    }

    //top middle
    x = -200;
    for(i = 26; i < 31; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,104, buildingMap[i], buildingDirection[i]);
    }

    x = -200;
    for(i = 31; i < 36; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,124, buildingMap[i], buildingDirection[i]);
    }

    //middle middle
    x = -32;
    for(i = 36; i < 39; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,104, buildingMap[i], buildingDirection[i]);
    }

    rebindTexture(buildingTex[j++]);
    drawBuilding(28,0,104, PYRAMID_CUBE_LARGE, NORTH);

    x = -32;
    for(i = 40; i < 44; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,124, buildingMap[i], buildingDirection[i]);
    }

    //bottom middle
    x = 112;
    for(i = 44; i < 48; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,104, buildingMap[i], buildingDirection[i]);
    }

    x = 112;
    for(i = 48; i < 52; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,124, buildingMap[i], buildingDirection[i]);
    }

    //top left corner
    x = -200;
    for(i = 52; i < 57; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,182, buildingMap[i], buildingDirection[i]);
    }

    x = -200;
    for(i = 57; i < 62; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,202, buildingMap[i], buildingDirection[i]);
    }

    //middle left side
    x = -32;
    for(i = 62; i < 64; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,182, buildingMap[i], buildingDirection[i]);
    }

    //SONY_JAPAN_MEDIUM
    rebindTexture(buildingTex[j++]);
    drawBuilding(x,0,182, SONY_JAPAN_MEDIUM, buildingDirection[i]);

    x = -32;
    for(i = 66; i < 68; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,202, buildingMap[i], buildingDirection[i]);
    }

    //bottom left corner
    x = 112;
    for(i = 70; i < 74; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,182, buildingMap[i], buildingDirection[i]);
    }

    x = 112;
    for(i = 74; i < 78; ++i, x += 20)
    {
        rebindTexture(buildingTex[j++]);
        drawBuilding(x,0,202, buildingMap[i], buildingDirection[i]);
    } 

    //mailboxes
    rebindTexture(numTex);

    drawBuilding(-90,0,26, MAILBOX, NORTH);

    drawBuilding(58,0,26, MAILBOX, NORTH);

    drawBuilding(202,0,26, MAILBOX, NORTH);

    drawBuilding(-90,0,104, MAILBOX, NORTH);

    drawBuilding(58,0,104, MAILBOX, NORTH);

    drawBuilding(202,0,104, MAILBOX, NORTH);

    drawBuilding(-90,0,182, MAILBOX, NORTH);

    drawBuilding(58,0,182, MAILBOX, NORTH);

    drawBuilding(202,0,182, MAILBOX, NORTH);
} 