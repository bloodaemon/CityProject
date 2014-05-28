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

#include "pyramid.h"
#include <iostream>
#include <cmath>

Pyramid::Pyramid()
{
}

Pyramid::~Pyramid()
{
}

void Pyramid::drawPyramid(const float length, const float width, const float height)
{
    float v1x,v1y,v1z,v2x,v2y,v2z,nx,ny,nz,lengthV;

    //bottom
    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glNormal3f(0,-1,0);
        glColor3f(0.2,0.2,0.2);
        glVertex3f(0,0,0);   //first vertex
        
        glVertex3f(length,0,0);   //second vertex
        
        glVertex3f(length,0,width);    //third vertex

        glVertex3f(0,0,width);    //fourth vertex
    glEnd();

    //front
    glBegin(GL_TRIANGLES);      //tell OpenGL that the following vertices form a QUAD
        // first vector
        v1x = length;
        v1y = 0;
        v1z = 0;

        // second vector
        v2x = length/2.0;
        v2y = height;
        v2z = (width/2.0) - width;

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
        glColor3f(0.2,0.2,0.2);
        //glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3f(0,0,width);   //first vertex
        
        //glTexCoord2f(length/100.0,0); //texture coordinate of second vertex
        glVertex3f(length,0,width);   //second vertex
        
        //glTexCoord2f(length/200.0,height/100.0);  //texture coordinate of third vertex
        glVertex3f(length/2.0,height,width/2.0);    //third vertex
    glEnd();
   
    //back
    glBegin(GL_TRIANGLES);      //tell OpenGL that the following vertices form a QUAD
        // first vector
        v1x = length/2.0;
        v1y = height;
        v1z = width/2.0;

        // second vector
        v2x = length;
        v2y = 0;
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
        glColor3f(0.2,0.2,0.2);
        //glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3f(0,0,0);   //first vertex
        
        //glTexCoord2f(length/200.0,height/100.0); //texture coordinate of second vertex
        glVertex3f(length/2.0,height,width/2.0);   //second vertex
        
        //glTexCoord2f(length/100.0,0);  //texture coordinate of third vertex
        glVertex3f(length,0,0);    //third vertex
    glEnd();

    //left
    glBegin(GL_TRIANGLES);      //tell OpenGL that the following vertices form a QUAD
        // first vector
        v1x = 0;
        v1y = 0;
        v1z = width;

        // second vector
        v2x = length/2.0;
        v2y = height;
        v2z = width/2.0;

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
        glColor3f(0.2,0.2,0.2);
        //glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3f(0,0,0);   //first vertex
        
        //glTexCoord2f(width/100.0,0); //texture coordinate of second vertex
        glVertex3f(0,0,width);   //second vertex
        
        //glTexCoord2f(width/200.0,height/100.0);  //texture coordinate of third vertex
        glVertex3f(length/2.0,height,width/2.0);    //third vertex
    glEnd();

    //right
    glBegin(GL_TRIANGLES);      //tell OpenGL that the following vertices form a QUAD
        // first vector
        v1x = (length/2.0) - length;
        v1y = height;
        v1z = width/2.0;

        // second vector
        v2x = 0;
        v2y = 0;
        v2z = width;

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
        glColor3f(0.2,0.2,0.2);
        //glTexCoord2f(width/100.0,0); //texture coordinate of first vertex
        glVertex3f(length,0,0);   //first vertex
        
        //glTexCoord2f(width/200.0,height/100.0); //texture coordinate of second vertex
        glVertex3f(length/2.0,height,width/2.0);   //second vertex
        
        //glTexCoord2f(0,0);  //texture coordinate of third vertex
        glVertex3f(length,0,width);    //third vertex
    glEnd();
}