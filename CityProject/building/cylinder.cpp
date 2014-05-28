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

#include "cylinder.h"
#include <iostream>
#include <cmath>

#define PI 3.14159265359

Cylinder::Cylinder()
{
}

Cylinder::~Cylinder()
{
}

void Cylinder::drawCylinder(const float length, const float width, const float height)
{
    double conversion = PI/180.0;
    bool texSwitch = true;
    float texX = 0.75;
    float v1x,v1y,v1z,v2x,v2y,v2z,nx,ny,nz,lengthV;

    //top
    glBegin(GL_TRIANGLE_FAN);    
        glColor3f(0.2,0.2,0.2);
        glNormal3f(0,1,0);
        glVertex3f(0,height,0);   //first vertex

        for(float i = 360.0; i >= 0.0; i -= 22.5)
        {
            glVertex3f((length/2)*cos(i*conversion),height,(width/2)*sin(i*conversion)); 
        }
    glEnd();

    //bottom
    glBegin(GL_TRIANGLE_FAN);     
        glColor3f(0.2,0.2,0.2);
        glNormal3f(0,-1,0); 
        glVertex3f(0,0,0);   //first vertex

        for(float i = 0.0; i <= 360.0; i += 22.5)
        {
            glVertex3f((length/2)*cos(i*conversion),0,(width/2)*sin(i*conversion));
        }
    glEnd();

    //sides
    glBegin(GL_QUAD_STRIP);   
        texSwitch = true;
        texX = 0.0;
        float distance = sqrt(pow((length/2)*cos(0*conversion) - (length/2)*cos(22.5*conversion), 2) + pow((width/2)*sin(0*conversion) - (width/2)*sin(22.5*conversion), 2));
        // first vector
        v1x = (length/2.0)*cos(0) - (length/2.0)*cos(-22.5)*conversion;
        v1y = 0;
        v1z = (width/2.0)*sin(0) - (width/2.0)*sin(22.5)*conversion;

        // second vector
        v2x = 0;
        v2y = height - 0;
        v2z = 0;

        // calculate normal
        nx = v1y*v2z - v1z*v2y;
        ny = v1z*v2x - v1x*v2z;
        nz = v1x*v2y - v1y*v2x;

        lengthV = sqrt(nx*nx + ny*ny + nz*nz);

        nx = nx/lengthV;
        ny = ny/lengthV;
        nz = nz/lengthV;

        // normals for flat shading
        glNormal3f(nx,ny,nz);

        glTexCoord2f(texX,height/100.0); 
        glVertex3f((length/2.0)*cos(0),height,(width/2.0)*sin(0)); 

        glTexCoord2f(texX,0.0); 
        glVertex3f((length/2.0)*cos(0),0,(width/2.0)*sin(0));

        texX += distance/100.0;

        for(float i = 22.5; i <= 360.0; i += 22.5)
        {
            // first vector
            v1x = (length/2.0)*cos(i*conversion) - (length/2.0)*cos((i-22.5)*conversion);
            v1y = 0;
            v1z = (width/2.0)*sin(i*conversion) - (width/2.0)*sin((i-22.5)*conversion);

            // second vector
            v2x = 0;
            v2y = height - 0;
            v2z = 0;

            // calculate normal
            nx = v1y*v2z - v1z*v2y;
            ny = v1z*v2x - v1x*v2z;
            nz = v1x*v2y - v1y*v2x;

            lengthV = sqrt(nx*nx + ny*ny + nz*nz);

            nx = nx/lengthV;
            ny = ny/lengthV;
            nz = nz/lengthV;

            // normals for flat shading
            glNormal3f(nx,ny,nz);
            glTexCoord2f(texX,height/100.0); 
            glVertex3f((length/2.0)*cos(i*conversion),height,(width/2.0)*sin(i*conversion)); 

            glTexCoord2f(texX,0.0); 
            glVertex3f((length/2.0)*cos(i*conversion),0,(width/2.0)*sin(i*conversion)); 

            texX += distance/100.0;
        }
    glEnd();
}