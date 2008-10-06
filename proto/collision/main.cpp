/* Description: Learning collision detection.
 *
 * Compile and Execute: 
 * $ g++  -L/usr/local/lib -losg -losgDB -losgViewer shape.cpp -o collision
 * $ ./collision
 *
 * */

#include<osgViewer/Viewer>
#include<osg/ShapeDrawable>

#include <osg/Node>
#include <osg/NodeCallback>
#include <osg/Timer>
#include <string>
#include <vector>
#include <iostream>
#include "car.h"

#define CARCOUNT 10
#define RAD 40.0

double W = 800.0;
double H = 800.0;

using namespace std;

/* Declarations. */
osg::ref_ptr<osg::MatrixTransform> draw_sphere(Car * pcar);

/*-----------------------------------------------------------------
Entry point. Create and populate scene graph.
-----------------------------------------------------------------*/
int main()
{
	osgViewer::Viewer viewer;
	osg::ref_ptr<osg::Group> root_group = new osg::Group;
	vector<Car*> carlist;

	viewer.setUpViewInWindow(0, 0, W, H);

	for(int i = 0; i < CARCOUNT; i++) {
		Car * pcar = new Car();
		carlist.push_back(pcar);
		root_group->addChild(draw_sphere(pcar).get());
	}

	viewer.setSceneData(root_group.get());

	osg::Vec3d eye(0.0, -W/2, 0.0);
	osg::Vec3d target(0.0, 0.0, 0.0);
	osg::Vec3d up(0.0, 0.0, 1.0);

	viewer.getCamera()->setViewport(0, 0, W, H);
	
	//viewer.getCamera()->setProjectionMatrixAsPerspective(80., 1., 1., 140. );
	viewer.getCamera()->setProjectionMatrixAsOrtho(-W/2, W/2, -H/2, H/2, -W/2, W/2);
	viewer.getCamera()->setViewMatrixAsLookAt(eye, target, up);
	osg::Timer_t start_tick = osg::Timer::instance()->tick();
	
	while(viewer.done() == 0)
	{
		//viewer.getCamera()->setClearColor(osg::Vec4(1.0, 1.0, 1.0, 1.0));

		osg::Timer_t end_tick = osg::Timer::instance()->tick();
		double delta_m = osg::Timer::instance()->delta_m(start_tick, end_tick);
	
		if(delta_m > 10.0)  {
			
			/* Check for intersection of one object with every other. */ 
			for(int i = 0; i < (int)carlist.size(); i++) {
				for(int j = i+1; j < (int)carlist.size(); j++) {

					/* Use pointer to MatrixTransform to *create* bound objects. */
					osg::Vec3d c1(carlist[i]->x, 0.0, carlist[i]->z);
					osg::BoundingSphere bs1(c1, RAD);

					osg::Vec3d c2(carlist[j]->x, 0.0, carlist[j]->z);
					osg::BoundingSphere bs2(c2, RAD);

					if(bs1.intersects(bs2)) {
						/* Collision detection. Simply reverse direction. */
						carlist[i]->dx =  -carlist[i]->dx;
						carlist[i]->dz =  -carlist[i]->dz;
						carlist[j]->dx =  -carlist[j]->dx;
						carlist[j]->dz =  -carlist[j]->dz;
						break;
					}
				}
			}

			for(int i = 0; i < (int)carlist.size(); i++)
				carlist[i]->move();

			start_tick = osg::Timer::instance()->tick();
		}
		viewer.frame();
	}

	return 0;
}

/*-----------------------------------------------------------------
Car is drawn as sphere (rad = 20) for time being.
-----------------------------------------------------------------*/
osg::ref_ptr<osg::MatrixTransform> draw_sphere(Car * pcar)
{
	/* Geode containing a shape. */
	osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	osg::ref_ptr<osg::ShapeDrawable> sd;

	osg::ref_ptr<osg::Sphere> sphere = new osg::Sphere(osg::Vec3f(), RAD);
	sd = new osg::ShapeDrawable(sphere.get());
	geode->addDrawable(sd.get());

	/* Place the object at desired position from origin. */
	osg::ref_ptr<osg::MatrixTransform> mt = new osg::MatrixTransform;
	mt->setDataVariance(osg::Object::STATIC);

	osg::Matrix m;
	m.makeTranslate(pcar->x, 0.0, pcar->z);
	mt->setMatrix(m);

	mt->addChild(geode.get());

	/* Save pointer to MatrixTransform object for later use. */
	pcar->mt = mt.get();

	return mt.get();
}

