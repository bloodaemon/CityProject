#include "billboard.h"
#include <iostream>
#include <string>
using namespace std;

#include "bitmap/bitmap.h" //Bitmap loader by Benjamin Kalytta http://www.kalytta.com/bitmap.h


unsigned int Billboards::m_texture;
unsigned int Billboards::m_texture1;
unsigned int Billboards::m_texture2;
unsigned int Billboards::m_frame;


Billboards::Billboards() {}

Billboards::~Billboards() {}

void Billboards::init()
{

	CBitmap image("billboard/poster1.bmp");    

    glGenTextures(1,&m_texture);                //allocate 1 texture
    glBindTexture(GL_TEXTURE_2D, m_texture);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image.GetWidth(),image.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

  CBitmap image1("billboard/poster2.bmp");    

    glGenTextures(1,&m_texture1);                //allocate 1 texture
    glBindTexture(GL_TEXTURE_2D, m_texture1);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image1.GetWidth(),image1.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image1.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

}

void Billboards::draw()
{

	glEnable(GL_TEXTURE_2D);    //enable texturing

    glPushMatrix();             //push current modelview matrix onto stack
    drawBoards();
    glPopMatrix(); //restore modelview matrix before scaling
           //restore modelview matrix before scaling
  
}

void Billboards::drawBoards(){

  //using obsolete gBegin/glEnd calls (see Demo4 for vertex buffer objects (VBO))
  glColor3f(1.0f, 5.0f, 5.0f);

  //right side
  glBindTexture(GL_TEXTURE_2D, m_texture);

  glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(50,20, 35);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(50,20, 55);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(50, 50, 55);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(50, 50, 35);   //second vertex

    glEnd();

  glBindTexture(GL_TEXTURE_2D, m_texture1);

  glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0,0); //texture coordinate of first vertex
        glVertex3i(50,20, 110);   //first vertex
        
        glTexCoord2f(1,0);  //texture coordinate of third vertex
        glVertex3i(50,20, 130);    //third vertex

        glTexCoord2f(1,1); //texture coordinate of fourth vertex
        glVertex3f(50, 50, 130);    //fourth vertex

        glTexCoord2f(0,1); //texture coordinate of second vertex
        glVertex3f(50, 50, 110);   //second vertex

    glEnd();


}
