
#include <iostream>
#include <cstdlib>
#include <osg/MatrixTransform>
#include "car.h"

using namespace std;

#define MAX_SPEED 5

extern double W, H;

/*-------------------------------------------------------------------
-------------------------------------------------------------------*/
Car::Car()
{
	x = -W/2 + rand() % (int)W;
	z = -H/2 + rand() % (int)H;
	dx = (rand() % (MAX_SPEED * 2)) - MAX_SPEED;
	dz = (rand() % (MAX_SPEED * 2)) - MAX_SPEED;
	mt = NULL;
}

/*-------------------------------------------------------------------
-------------------------------------------------------------------*/
void Car::move()
{
	x = x + dx;
	z = z + dz;
	osg::Matrix m;
	m.makeTranslate(x, 0, z);
	this->mt->setMatrix(m);

	if (x < -W/2.0 || x > W/2.0)
		dx = -dx;
	if (z < -H/2.0 || z > H/2.0)
		dz = -dz;
}
