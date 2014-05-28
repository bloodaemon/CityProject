#include "plane.h"

Plane::Plane() : success(false), errOnce(false)
{}

Plane::~Plane() {}

void Plane::init(float startX, float startY, float startZ, int stepSize, int tempWidth, int tempLength, char direction)
{	
	width = tempWidth;
	length = tempLength;

	Point hold;

	switch(direction)
	{
	case 'f':
			for (int i = 0; i < width; i++) {
				vector<Point> test;

				for (int j = 0; j < length; j++) {
					hold.x = startX - (i * stepSize);
					hold.y = startY;
					hold.z = startZ + (j * stepSize);
					test.push_back(hold);
				}
				pointArray.push_back(test);
			}
			success = true;
			break;
	case 's':
			for (int i = 0; i < width; i++) {
				vector<Point> test;

				for (int j = 0; j < length; j++) {
					hold.x = startX;
					hold.y = startY + (i * stepSize);
					hold.z = startZ + (j * stepSize);
					test.push_back(hold);
				}
				pointArray.push_back(test);
			}
			success = true;
			break;
	case 'u':
			for (int i = 0; i < width; i++) {
				vector<Point> test;

				for (int j = 0; j < length; j++) {
					hold.x = startX - (i * stepSize);
					hold.y = startY + (j * stepSize);
					hold.z = startZ;
					test.push_back(hold);
				}
				pointArray.push_back(test);
			}
			success = true;
			break;

	default: cout << "Error on creating plane: '" << direction << "' not recognized as a valid input." << endl;
		success = false;
		break;
	}
}

void Plane::draw()
{
	if (success == true)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glColor3f(1.0f, 0.0f, 0.0f);

		for (int i = 0; i < width - 1; i ++) {
			for (int j = 0; j < length; j++) {
				glVertex3f(pointArray[i][j].x, pointArray[i][j].y, pointArray[i][j].z);
				glVertex3f(pointArray[i + 1][j].x, pointArray[i + 1][j].y, pointArray[i + 1][j].z);
			}
			i += 1;
			if ( i == width - 1 )
			{
			} else {
				for (int j = length - 1; j >= 0; j--) {
				glVertex3f(pointArray[i + 1][j].x, pointArray[i + 1][j].y, pointArray[i + 1][j].z);
				glVertex3f(pointArray[i][j].x, pointArray[i][j].y, pointArray[i][j].z);
				}
			}
		}

		glEnd();
	} else if (errOnce == false) {
		cout << "Failed attempt to draw plane." << endl;
		errOnce = true;
	}
}