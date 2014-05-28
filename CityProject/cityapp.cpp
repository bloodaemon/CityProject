#include "cityapp.h"

Street CityApp::ground;
Billboards CityApp::bb;
MovingCar CityApp::movingCars;
Sky CityApp::sky;
Buildings *CityApp::buildings; //changed pointer to real object

float eyeX = -114.800087;
float eyeY = -50.997894;
float eyeZ = -69.500092;
float lookX = 100.0f;
float lookY = 2.7f;
float lookZ = 10.0f;


int frame = 0;
int follow = 0;



CityApp::CityApp(int argc, char **argv)
{
    glutInit(&argc,argv);
	glutInitWindowSize(width, height);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB); // Init depth buffer, double buffer, and RGB color scheme.
    glutCreateWindow("City Program");
    gluLookAt(lookX,lookY,lookZ,0,0,0,0,1,0);          //set up camera position and orientation


	glutKeyboardFunc(keyDown);		//Key down callback
    glutKeyboardUpFunc(keyUp);		//Key up callback
	glutMotionFunc(mouseMove);		//mouse callback
    glutDisplayFunc(render);		//Redraw callback
    glutIdleFunc(update);			//No input callback

    initOpenGL();
}

CityApp::~CityApp() {
	delete buildings;
}

void CityApp::run()
{
	glutMainLoop();
}

void CityApp::update()
{
	glutPostRedisplay();
	frame++;
}

void CityApp::cameraUpdate(){

	int xCamera = movingCars.getX((frame)/10);
	int zCamera = movingCars.getZ((frame)/10);
	int xbuff;
	int zbuff;

	switch(follow)
	{
	case 1:
		if(xCamera < 0){xbuff +=50;} else{xbuff -=50;}
		if(zCamera > 0){zbuff +=50;} else{zbuff -=50;}

		gluLookAt(xCamera,10,zCamera,
		movingCars.getX((frame-xbuff)/10), 10, movingCars.getZ((frame-zbuff)/10),
		0,1,0);          //set up camera position and orientation
		//printf("%f %f\n", movingCars.getX(frame/10), movingCars.getZ(frame/10));

		break;
	case 2: 

		if(xCamera < 0){xbuff +=50; xCamera+=5;} else{xbuff -=50; xCamera-=5;}
		if(zCamera > 0){zbuff +=50;} else{zbuff -=50;}

		gluLookAt(xCamera,10,zCamera,
		movingCars.getX((frame+xbuff)/10), 0, movingCars.getZ((frame+zbuff)/10),
		0,1,0);          //set up camera position and orientation
		//printf("%f %f\n", movingCars.getX(frame/10), movingCars.getZ(frame/10));
		
		break;
	case 3:
		if(xCamera < 0){xCamera+=10;} else{xCamera-=10;}
		if(zCamera < 0){zCamera+=10;} else{zCamera-=10;}

		gluLookAt(xCamera,1,zCamera,
		movingCars.getX(frame/10), 1, movingCars.getZ(frame/10),
		0,1,0);          //set up camera position and orientation
		//printf("%f %f\n", movingCars.getX(frame/10), movingCars.getZ(frame/10));
		break;
	case 4:
		if(xCamera > 0){xCamera+=10;} else{xCamera-=10;}
		if(zCamera > 0){zCamera+=10;} else{zCamera-=10;}

		gluLookAt(xCamera,20,zCamera,
		movingCars.getX(frame/10), 10, movingCars.getZ(frame/10),
		0,1,0);          //set up camera position and orientation
		//printf("%f %f\n", movingCars.getX(frame/10), movingCars.getZ(frame/10));
		break;
	case 5:
		if(xCamera < 0){xCamera+=10;} else{xCamera-=10;}
		if(zCamera < 0){zCamera+=10;} else{zCamera-=10;}

		gluLookAt(xCamera,10,zCamera,
		movingCars.getX(frame/10), 15, movingCars.getZ(frame/10),
		0,1,0);          //set up camera position and orientation
		//printf("%f %f\n", movingCars.getX(frame/10), movingCars.getZ(frame/10));
		break;

	default:
		gluLookAt(lookX,lookY,lookZ,0,0,0,0,1,0);          //set up camera position and orientation
		//printf("%f %f %f\n", lookX, lookY, lookZ );
		glTranslatef(eyeX, eyeY, eyeZ);
		//printf("%f %f %f\n", eyeX, eyeY, eyeZ);

		break;
	}
	
}

void CityApp::initOpenGL()
{
	glShadeModel(GL_SMOOTH);  
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set color for glClear()
	glClearDepth(1.0f);                         // Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);                        // Enables Depth Testing
	glDepthFunc(GL_LEQUAL);  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
	glEnable(GL_TEXTURE_2D);
	initWorld();

	// lighting set up
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1); 
    glEnable(GL_LIGHT2); 
    glEnable(GL_LIGHT3);   

    //Set lighting intensity and color
    GLfloat qaAmbientLight[] = {.2, .2, .2, 1.0};
    GLfloat qaDiffuseLight[] = {.7, .7, .7, 1.0};
    GLfloat qaSpecularLight[] = {1, 1, 1, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);
    glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight);
    glLightfv(GL_LIGHT2, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT2, GL_SPECULAR, qaSpecularLight);
    glLightfv(GL_LIGHT3, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT3, GL_SPECULAR, qaSpecularLight);
    glLightfv(GL_LIGHT4, GL_AMBIENT, qaAmbientLight);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, qaDiffuseLight);
    glLightfv(GL_LIGHT4, GL_SPECULAR, qaSpecularLight);

    //Set the light position
    GLfloat q1LightPosition[] = {90.0, 90.0, 5.0, 1.0};
   	GLfloat q2LightPosition[] = {-90.0, 90.0, 140.0, 1.0};
   	GLfloat q3LightPosition[] = {90.0, 90.0, 5.0, 1.0};
    GLfloat q4LightPosition[] = {-90.0, 90.0, 140.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, q1LightPosition);
    glLightfv(GL_LIGHT1, GL_POSITION, q2LightPosition);
    glLightfv(GL_LIGHT3, GL_POSITION, q3LightPosition);
    glLightfv(GL_LIGHT4, GL_POSITION, q4LightPosition);

}



void CityApp::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Clear color values in framebuffer
	glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);       
    glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,10000.0f);//Initializes projection matrix.
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();						//Initializes modelview matrix.
 
	cameraUpdate();
	
	drawObjects();
	glFlush();

    glutSwapBuffers();	
}

void CityApp::keyDown(unsigned char key, int, int)
{
	switch(key)
	{
	case 'a': eyeX += 5;
		break;
	case 'd': eyeX -= 5;
		break;
	case 'w': eyeZ += 5;
		break;
	case 's': eyeZ -= 5;
		break;
	case 't': eyeY += 5;
		break;
	case 'g': eyeY -= 5;
		break;
	case 'l': lookY -= 5;
		break;
	case 'o': lookY += 5;
		break;
	case 'p': lookX += 5;
		break;
	case 'i': lookX -= 5;
		break;
	case 'u': lookZ += 5;
		break;
	case 'k': lookZ -= 5;
		break;

	case '8':
		follow = (follow+1)%6;

		break;

	case 'q': exit(0);
		break;
	case 27: exit(0);
		break;
	default:
		break;
	}
}

void CityApp::keyUp(unsigned char key, int, int)
{}

void CityApp::mouseMove(int x, int y)
{
	//camera.mouseMovement(x, y);
}

void CityApp::initWorld()
{
	sky.init();
	movingCars.init();
	ground.init();
	bb.init();
	buildings = new Buildings();
	buildings->generateWindowTexture(); //changed method of binding texture
}

void CityApp::drawObjects()
{
	sky.draw();
	buildings->draw(); //changed method of drawing buildings
	ground.draw();
	bb.draw();
	movingCars.draw(frame/10);


}