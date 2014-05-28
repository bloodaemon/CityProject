/*
 
 ECS 175: Computer Graphics
 UC Davis, Spring 2013
 
 Project 4
 
 */
#ifndef _WINDOWTEXTURE_H_
#define _WINDOWTEXTURE_H_

#define numTex 5 //number of textures excluding the one used for mailbox


/*
 WindowTexture class (singleton)
 */
class WindowTexture
{
protected:
    unsigned int m_nTextureId[numTex+1];
    bool textureBounded;
    void rebindTexture(int selection);
public:
	WindowTexture();
	~WindowTexture();
	void generateWindowTexture();
};




#endif

