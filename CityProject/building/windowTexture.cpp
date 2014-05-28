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

#include "windowTexture.h"
#include "bitmap/bitmap.h" //Bitmap loader by Benjamin Kalytta http://www.kalytta.com/bitmap.h
#include <iostream>
#include <cstdlib>

#define numTex 5 //number of textures excluding the one used for mailbox


WindowTexture::WindowTexture()
{
    textureBounded = false;
    glGenTextures(numTex+1, m_nTextureId);                  // Get An Open ID
}

WindowTexture::~WindowTexture()
{
    glBindTexture(GL_TEXTURE_2D, 0);    //unbind current texture
    glDeleteTextures(numTex+1, m_nTextureId);  //delete windows texture data
}

void WindowTexture::generateWindowTexture()  //randomly generate windows texture for buildings
{
    CBitmap image0("building/texture/1.bmp");    

    glBindTexture(GL_TEXTURE_2D, m_nTextureId[0]);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image0.GetWidth(),image0.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image0.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

    glEnable(GL_TEXTURE_2D);

    CBitmap image1("building/texture/2.bmp");    

    glBindTexture(GL_TEXTURE_2D, m_nTextureId[1]);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image1.GetWidth(),image1.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image1.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

    glEnable(GL_TEXTURE_2D);

    CBitmap image2("building/texture/3.bmp");    

    glBindTexture(GL_TEXTURE_2D, m_nTextureId[2]);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image2.GetWidth(),image2.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image2.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

    glEnable(GL_TEXTURE_2D);

    CBitmap image3("building/texture/4.bmp");    

    glBindTexture(GL_TEXTURE_2D, m_nTextureId[3]);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image3.GetWidth(),image3.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image3.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

    glEnable(GL_TEXTURE_2D);

    CBitmap image4("building/texture/5.bmp");    

    glBindTexture(GL_TEXTURE_2D, m_nTextureId[4]);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image4.GetWidth(),image4.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image4.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

    glEnable(GL_TEXTURE_2D);

    CBitmap image100("building/texture/mailbox_asdf.bmp");

    glBindTexture(GL_TEXTURE_2D, m_nTextureId[numTex]);    //bind this texture to be active
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,image100.GetWidth(),image100.GetHeight(),0,GL_RGBA,GL_UNSIGNED_BYTE,image100.GetBits()); //load data into texture
        
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); //specify minificaton filtering
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); //specify magnificaton filtering

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

    glEnable(GL_TEXTURE_2D);

    textureBounded = true;
}

void WindowTexture::rebindTexture(int selection)  //used for switching textures
{
    if(textureBounded)
    {
        if(selection >= 0 && selection < numTex+1)
        {
            glBindTexture(GL_TEXTURE_2D, m_nTextureId[selection]);               // Bind The Texture
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);    //specify texture coordinate treatment
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);    //specify texture coordinate treatment

            glEnable(GL_TEXTURE_2D);
        }
        else
        {
            std::cout << "ERROR: Texture array out of bounds" << std::endl;
            exit(0);
        }
    }
    else
        std::cout << "ERROR: Cannot rebind texture. Windows Texture not already generated." << std::endl;
}