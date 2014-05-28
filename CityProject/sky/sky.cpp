#include "sky.h"
#include <iostream>
#include <string>
using namespace std;

#include "bitmap/bitmap.h" //Bitmap loader by Benjamin Kalytta http://www.kalytta.com/bitmap.h


unsigned int Sky::m_texture;
unsigned int Sky::m_texture2;
unsigned int Sky::m_frame;


Sky::Sky() {}

Sky::~Sky() {}

void Sky::init()
{

	CBitmap image("sky/sky.bmp");    

    glGenTextures(1,&m_texture);                //allocate 1 texture
    glBindTexture(GL_TEXTURE_2D, m_texture);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image.GetWidth(),image.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

  CBitmap image2("sky/sidebuildings.bmp");    

    glGenTextures(1,&m_texture2);                //allocate 1 texture
    glBindTexture(GL_TEXTURE_2D, m_texture2);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image2.GetWidth(),image2.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image2.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment



}

void Sky::draw()
{

	glEnable(GL_TEXTURE_2D);    //enable texturing

    glPushMatrix();             //push current modelview matrix onto stack
    drawMap();
    glPopMatrix(); //restore modelview matrix before scaling
           //restore modelview matrix before scaling
  
}

void Sky::drawMap(){

  //using obsolete gBegin/glEnd calls (see Demo4 for vertex buffer objects (VBO))
  glColor3f(1.0f, 5.0f, 5.0f);

  //right side
  glBindTexture(GL_TEXTURE_2D, m_texture);

  glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(-350,200, 0);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(350,200, 0);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(350, 200, 350);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(-350, 200, 350);   //second vertex

    glEnd();



     glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(-250,75, -30);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(250,75, 0);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(250, 200,0);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(-250, 200,-30);   //second vertex

    glEnd();

        glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(-250,75, 280);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(250,75, 280);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(250, 200,250);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(-250, 200,250);   //second vertex

    glEnd();


    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(-310,75, 0);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(-250,75, 250);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(-250, 200,250);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(-310, 200,0);   //second vertex

    glEnd();

        glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(250,75, 0);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(250,75, 250);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(250, 200,250);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(250, 200,0);   //second vertex

    glEnd();




    glBindTexture(GL_TEXTURE_2D, m_texture2);

    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(-250,0, -30);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(250,0, 0);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(250, 75,0);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(-250, 75,-30);   //second vertex

    glEnd();

        glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(-250,0, 280);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(250,0, 280);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(250, 75,250);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(-250, 75,250);   //second vertex

    glEnd();


    glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(-310,0, 0);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(-250,0, 250);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(-250, 75,250);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(-310, 75,0);   //second vertex

    glEnd();

        glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(250,0, 0);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(250,0, 250);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(250, 75,250);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(250, 75,0);   //second vertex

    glEnd();




}
