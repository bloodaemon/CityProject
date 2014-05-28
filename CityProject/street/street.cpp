#include "street.h"
#include <iostream>
#include <string>
using namespace std;

#include "bitmap/bitmap.h" //Bitmap loader by Benjamin Kalytta http://www.kalytta.com/bitmap.h


unsigned int Street::m_texture;
unsigned int Street::m_frame;


Street::Street() {}

Street::~Street() {}

void Street::init()
{

	CBitmap image("street/ground.bmp");    

    glGenTextures(1,&m_texture);                //allocate 1 texture
    glBindTexture(GL_TEXTURE_2D, m_texture);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image.GetWidth(),image.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment



}

void Street::draw()
{

	glBindTexture(GL_TEXTURE_2D, m_texture);
	glEnable(GL_TEXTURE_2D);    //enable texturing

    glPushMatrix();             //push current modelview matrix onto stack
    drawMap();
    glPopMatrix(); //restore modelview matrix before scaling
           //restore modelview matrix before scaling
  
}

void Street::drawMap(){

  //using obsolete gBegin/glEnd calls (see Demo4 for vertex buffer objects (VBO))
  glColor3f(1.0f, 5.0f, 5.0f);

  //right side
  glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(-250,0, 0);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(250,0, 0);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(250, 0, 250);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(-250, 0, 250);   //second vertex

    glEnd();




}
