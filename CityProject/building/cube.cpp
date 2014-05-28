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

#include "cube.h"
#include <iostream>

Cube::Cube()
{
}

Cube::~Cube()
{
}


void Cube::drawCube(const float length, const float width, const float height)
{
    //max dimensions(length x width x height): 64 x 64 x 64
    
    //front
    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glNormal3f(0,0,1);
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3f(0,0,width);   //first vertex
        
        glTexCoord2f(length/100.0,0); //texture coordinate of second vertex
        glVertex3f(length,0,width);   //second vertex
        
        glTexCoord2f(length/100.0,height/100.0);  //texture coordinate of third vertex
        glVertex3f(length,height,width);    //third vertex

        glTexCoord2f(0,height/100.0); //texture coordinate of fourth vertex
        glVertex3f(0,height,width);    //fourth vertex
    glEnd();

    
    //back
    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glNormal3f(0,0,-1);
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3f(0,0,0);   //first vertex
        
        glTexCoord2f(0,height/100.0); //texture coordinate of second vertex
        glVertex3f(0,height,0);   //second vertex
        
        glTexCoord2f(length/100.0,height/100.0);  //texture coordinate of third vertex
        glVertex3f(length,height,0);    //third vertex

        glTexCoord2f(length/100.0,0); //texture coordinate of fourth vertex
        glVertex3f(length,0,0);    //fourth vertex
    glEnd();

    //top
    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glNormal3f(0,1,0);
        glColor3f(0.2,0.2,0.2);
        glVertex3f(0,height,0);   //first vertex

        glVertex3f(0,height,width);   //second vertex
        
        glVertex3f(length,height,width);    //third vertex

        glVertex3f(length,height,0);    //fourth vertex
    glEnd();

    //bottom
    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glNormal3f(0,-1,0);
        glColor3f(0.2,0.2,0.2);
        glVertex3f(0,0,0);   //first vertex
        
        glVertex3f(length,0,0);   //second vertex
        
        glVertex3f(length,0,width);    //third vertex

        glVertex3f(0,0,width);    //fourth vertex

    glEnd();

    //right
    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glNormal3f(1,0,0);

        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3f(length,0,0);   //first vertex
        
        glTexCoord2f(0,height/100.0); //texture coordinate of second vertex
        glVertex3f(length,height,0);   //second vertex
        
        glTexCoord2f(width/100.0,height/100.0);  //texture coordinate of third vertex
        glVertex3f(length,height,width);    //third vertex

        glTexCoord2f(width/100.0,0); //texture coordinate of fourth vertex
        glVertex3f(length,0,width);    //fourth vertex

    glEnd();

    //left
    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glNormal3f(-1,0,0);

        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3f(0,0,0);   //first vertex
        
        glTexCoord2f(width/100.0,0); //texture coordinate of second vertex
        glVertex3f(0,0,width);   //second vertex
        
        glTexCoord2f(width/100.0,height/100.0);  //texture coordinate of third vertex
        glVertex3f(0,height,width);    //third vertex

        glTexCoord2f(0,height/100.0); //texture coordinate of fourth vertex
        glVertex3f(0,height,0);    //fourth vertex

    glEnd();
}