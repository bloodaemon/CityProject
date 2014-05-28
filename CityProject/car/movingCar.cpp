#include "movingCar.h"
#include "math.h"
#define PI 3.1415926



int vertexCounter = 0;
int dataSize = 12*300; // one curve takes 300 slots we need 12 of them
unsigned int m_vertexbuffer;
bool turning = false;
float CarAngle1 = 90;
float CarAngle2 = 0;
float CarAngle3 = 180;
float CarAngle4 = 0;
float CarAngle5 = 270;


float *data= new float[dataSize]; 
MovingCar::MovingCar() {}

MovingCar::~MovingCar() {}

void MovingCar::init()
{
	// Calculate points in the bezier curve
	curve(90, 90, 90, 90, 90, 5, 90, 5 );
	curve(90, 5, 90, 5, -70, 5, -70, 5);
	curve(-70, 5, -70, 5, -70, 240, -70, 240);
	curve(-70, 240, -70, 240, 225, 240, 225, 240);
    curve(225, 240, 225, 240, 225, 85, 225, 85);
    curve(225, 85, 225, 85, -235, 85, -235, 85); 
    curve(-235, 85, -235, 85, -235, 165, -235, 165);
    curve(-235, 165, -235, 165, -55, 165, -55, 165);
    curve(-55, 165, -55, 165, -55, 5, -55, 5); 
    curve(-55, 5, -55, 5, -235, 5, -235, 5);
    curve(-235, 5, -235, 5, -235, 90, -235, 90);  
    curve(-235, 90, -235, 90, 90, 90, 90, 90);        
     
	//**** 
    car.init();  

}

void MovingCar::draw(int i){

    glColor3f(1.0f, 0.0f, 0.0f);

	//drawPic();                // draws the silhouette of the animal

	glEnable(GL_BLEND);                                 //enable alpha blending
    glBlendFunc(GL_SRC_COLOR,GL_ONE_MINUS_SRC_ALPHA);   //specifies blending function for textures with alpha
    
    // Calculate the change in x and the change in y

    if((i%100) > 81){CarAngle1 +=.5;}
    glTranslatef(data[((i%1200)*3)], 0, data[((i%1200)*3)+2]);
    car.draw(CarAngle1);
    glTranslatef(-data[((i%1200)*3)], 0, -data[((i%1200)*3)+2]);

    if(((i+310)%100) > 81){ CarAngle2 +=.5; }
    glTranslatef(data[(((i+310)%1200)*3)], 0, data[(((i+310)%1200)*3)+2]);
    car.draw(CarAngle2);
    glTranslatef(-data[(((i+310)%1200)*3)], 0, -data[(((i+310)%1200)*3)+2]);

    if(((i+550)%100) > 81){ CarAngle3 +=.5; }
    glTranslatef(data[(((i+550)%1200)*3)], 0, data[(((i+550)%1200)*3)+2]);
    car.draw(CarAngle3);
    glTranslatef(-data[(((i+550)%1200)*3)], 0, -data[(((i+550)%1200)*3)+2]);

    if(((i+770)%100) > 81){ CarAngle4 +=.5; }
    glTranslatef(data[(((i+770)%1200)*3)], 0, data[(((i+770)%1200)*3)+2]);
    car.draw(CarAngle4);
    glTranslatef(-data[(((i+770)%1200)*3)], 0, -data[(((i+770)%1200)*3)+2]);

    if(((i+1070)%100) > 81){ CarAngle5 +=.5; }
    glTranslatef(data[(((i+1070)%1200)*3)], 0, data[(((i+1070)%1200)*3)+2]);
    car.draw(CarAngle5);
    glTranslatef(-data[(((i+1070)%1200)*3)], 0, -data[(((i+1070)%1200)*3)+2]);

    glTranslatef(200,0, 110);
    car.draw(0);
    glTranslatef(-200,0, -110);
    glTranslatef(200,0, 120);
    car.draw(0);
    glTranslatef(-200,0, -120);

    glTranslatef(0,0, 80);
    car.draw(180);
    glTranslatef(0,0, -80);
    
    glTranslatef(40,0, 80);
    car.draw(180);
    glTranslatef(-40,0, -80);
    
    glTranslatef(65,0, 60);
    car.draw(270);
    glTranslatef(-65,0, -60);
    
    glTranslatef(-110,0, 80);
    car.draw(180);
    glTranslatef(110,0, -80);
    
    glTranslatef(-130,0, 80);
    car.draw(180);
    glTranslatef(130,0, -80);

    glTranslatef(65,0, 110);
    car.draw(270);
    glTranslatef(-65,0, -110);

    glDisable(GL_BLEND);   


}

float MovingCar::getX(int index){
    return data[((index%1200)*3)];
}
float MovingCar::getZ(int index){
    return data[((index%1200)*3)+2];
}



void MovingCar::drawPic()
{
    /*
        transfer vertex data to the GPU
     */
    glGenBuffers(1, &m_vertexbuffer);               //generate a vertex buffer object
    glBindBuffer(GL_ARRAY_BUFFER, m_vertexbuffer);  //bind buffer to be active
    glBufferData(GL_ARRAY_BUFFER, (dataSize)*sizeof(float), data, GL_STATIC_DRAW); //set buffer data
      
    glEnableClientState(GL_VERTEX_ARRAY);        //tell OpenGL that we want to specify vertex data in the buffer
    glVertexPointer(3, GL_FLOAT, 0, (void*)0);   //tell OpenGL where the vertex data lies in the buffer

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexbuffer);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glDrawArrays(GL_LINE_STRIP, 0, (dataSize/3));      //draw cruve (tell OpenGL that buffer keeps line strip with [sections+1] lines)
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glBindBuffer(GL_ARRAY_BUFFER, 0); 
       
}

/*
    calculates points for the bezier curve
*/
double MovingCar::bezier(double A, double B, double C, double D, double t){
    double s = 1 - t;
    double AB = A*s + B*t;
    double BC = B*s + C*t;
    double CD = C*s + D*t;
    double ABC = AB*s + BC*t;
    double BCD = BC*s + CD*t;
    return ABC*s + BCD*t;
}

/*
    fill the array with all the points we need to draw the silhouette of the animal
*/
void MovingCar::curve(float firstX, float firstY, float secondX, float secondY,
                float thirdX, float thirdY, float fourthX, float fourthY)
{
 
    
    // every curve have 100 points     
   for(int index = 0; index < 100; ++index, ++vertexCounter)
    {
        // Calculate (x,y)
        double x = bezier(firstX, secondX, thirdX, fourthX, ((double)index/100));
        double z = bezier(firstY, secondY, thirdY, fourthY, ((double)index/100));

        // save (x,y) in data. Also set z = 0
        data[3*vertexCounter] = x;
        data[(3*vertexCounter)+1] = 0;
        data[(3*vertexCounter)+2] = z;
       
    }
    
}