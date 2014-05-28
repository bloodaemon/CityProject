#include "car.h"
#include <iostream>
#include <string>
using namespace std;

#include "bitmap/bitmap.h" //Bitmap loader by Benjamin Kalytta http://www.kalytta.com/bitmap.h

unsigned int Car::m_texture;
unsigned int Car::m_frame;


Car::Car() {}

Car::~Car() {}

void Car::init()
{

	CBitmap image("car/bluecar.bmp");    

    glGenTextures(1,&m_texture);                //allocate 1 texture
    glBindTexture(GL_TEXTURE_2D, m_texture);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image.GetWidth(),image.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment



}

void Car::draw(float angle)
{

	glBindTexture(GL_TEXTURE_2D, m_texture);
	glEnable(GL_TEXTURE_2D);    //enable texturing

    glPushMatrix();             //push current modelview matrix onto stack
        glRotatef(angle, 0, 1, 0);
    drawCar();
    glPopMatrix(); //restore modelview matrix before scaling
           //restore modelview matrix before scaling
  
}

void Car::drawCar(){

  //right side
    glColor3f(1.0f, 1.0f, 1.0f);

  glBegin(GL_QUADS);      //tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0.3,.15); //texture coordinate of first vertex
        glVertex3i(-2,2, 2);   //first vertex
        
        glTexCoord2f(.6,.15);  //texture coordinate of third vertex
        glVertex3i(4,2, 2);    //third vertex

        glTexCoord2f(.585,0.02); //texture coordinate of fourth vertex
        glVertex3f(2, 3.5, 2);    //fourth vertex

        glTexCoord2f(0.35,0.02); //texture coordinate of second vertex
        glVertex3f(-2, 3.5, 2);   //second vertex


        glTexCoord2f(0.1,.25); //texture coordinate of first vertex
        glVertex3i(-6,0, 2);   //first vertex
        
        glTexCoord2f(.7,.25);  //texture coordinate of third vertex
        glVertex3i(6,0, 2);    //third vertex

        glTexCoord2f(.7,0.15); //texture coordinate of fourth vertex
        glVertex3i(6,2, 2);    //fourth vertex

        glTexCoord2f(0.1,0.15); //texture coordinate of second vertex
        glVertex3f(-6,2, 2);   //second vertex

    //left side
        glTexCoord2f(0.3,.15); //texture coordinate of first vertex
        glVertex3i(-2, 2, -2);   //first vertex
        
        glTexCoord2f(.6,.15);  //texture coordinate of third vertex
        glVertex3i(4, 2, -2);    //third vertex

        glTexCoord2f(.585,0.02); //texture coordinate of fourth vertex
        glVertex3f(2,3.5, -2);    //fourth vertex

        glTexCoord2f(0.35,0.02); //texture coordinate of second vertex
        glVertex3f(-2,3.5, -2);   //second vertex
		
		//tell OpenGL that the following vertices form a QUAD
        glTexCoord2f(0.1,.25); //texture coordinate of first vertex
        glVertex3i(-6,0, -2);   //first vertex
        
        glTexCoord2f(.7,.25);  //texture coordinate of third vertex
        glVertex3i(6,0, -2);    //third vertex

        glTexCoord2f(.7,0.15); //texture coordinate of fourth vertex
        glVertex3i(6,2, -2);    //fourth vertex

        glTexCoord2f(0.1,0.15); //texture coordinate of second vertex
        glVertex3f(-6,2, -2);   //second vertex

    //windshield 

        glTexCoord2f(0.1,.8); //texture coordinate of first vertex
        glVertex3i(4, 2, -2);   //first vertex
        
        glTexCoord2f(.4,.8);  //texture coordinate of third vertex
        glVertex3i(4, 2, 2);    //third vertex

        glTexCoord2f(.4,0.68); //texture coordinate of fourth vertex
        glVertex3f(2,3.5, 2);    //fourth vertex

        glTexCoord2f(0.1,0.68); //texture coordinate of second vertex
        glVertex3f(2,3.5, -2);   //second vertex

    //hood

        glTexCoord2f(0.1,.38); //texture coordinate of first vertex
        glVertex3i(6, 2, -2);   //first vertex
        
        glTexCoord2f(.4,.38);  //texture coordinate of third vertex
        glVertex3i(6, 2, 2);    //third vertex

        glTexCoord2f(.4,0.33); //texture coordinate of fourth vertex
        glVertex3i(4, 2, 2);    //fourth vertex

        glTexCoord2f(0.1,0.33); //texture coordinate of second vertex
        glVertex3f(4, 2, -2);   //second vertex

    // front end

        glTexCoord2f(0.1,.570); //texture coordinate of first vertex
        glVertex3i(6, 0, -2);   //first vertex
        
        glTexCoord2f(.4,.570);  //texture coordinate of third vertex
        glVertex3i(6, 0, 2);    //third vertex

        glTexCoord2f(.4,0.38); //texture coordinate of fourth vertex
        glVertex3i(6, 2, 2);    //fourth vertex

        glTexCoord2f(0.1,0.38); //texture coordinate of second vertex
        glVertex3f(6, 2, -2);   //second vertex

    // roof

        glTexCoord2f(0.6,.8); //texture coordinate of first vertex
        glVertex3f(2, 3.5, -2);   //first vertex
        
        glTexCoord2f(.87,.8);  //texture coordinate of third vertex
        glVertex3f(2, 3.5, 2);    //third vertex

        glTexCoord2f(.87,0.68); //texture coordinate of fourth vertex
        glVertex3f(-2, 3.5, 2);    //fourth vertex

        glTexCoord2f(0.6,0.68); //texture coordinate of second vertex
        glVertex3f(-2, 3.5, -2);   //second vertex

    // backwindow

        glTexCoord2f(0.1,.8); //texture coordinate of first vertex
        glVertex3i(-2, 2, -2);   //first vertex
        
        glTexCoord2f(.4,.8);  //texture coordinate of third vertex
        glVertex3i(-2, 2, 2);    //third vertex

        glTexCoord2f(.4,0.68); //texture coordinate of fourth vertex
        glVertex3f(-2,3.5, 2);    //fourth vertex

        glTexCoord2f(0.1,0.68); //texture coordinate of second vertex
        glVertex3f(-2,3.5, -2);   //second vertex

    //trunk

        glTexCoord2f(0.58,.45); //texture coordinate of first vertex
        glVertex3f(-2, 2, -2);   //first vertex
        
        glTexCoord2f(.87,.45);  //texture coordinate of third vertex
        glVertex3f(-2, 2, 2);    //third vertex

        glTexCoord2f(.87,0.315); //texture coordinate of fourth vertex
        glVertex3f(-6, 2, 2);    //fourth vertex

        glTexCoord2f(0.58,0.315); //texture coordinate of second vertex
        glVertex3f(-6, 2, -2);   //second vertex

        glTexCoord2f(0.58,.55); //texture coordinate of first vertex
        glVertex3f(-6, 0, -2);   //first vertex
        
        glTexCoord2f(.87,.55);  //texture coordinate of third vertex
        glVertex3f(-6, 0, 2);    //third vertex

        glTexCoord2f(.87,0.4); //texture coordinate of fourth vertex
        glVertex3f(-6, 2, 2);    //fourth vertex

        glTexCoord2f(0.58,0.4); //texture coordinate of second vertex
        glVertex3f(-6, 2, -2);   //second vertex
    glEnd();




}
