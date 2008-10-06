
#ifndef CAR_H
#define CAR_H

#include<osg/MatrixTransform>

/* Car is drawn as sphere for time being. */
class Car {

	public:
		double dx, dz; 	// current velocity direction
		double x, z; 	// current position
		osg::MatrixTransform * mt;

		Car();
		void move();
};

#endif
