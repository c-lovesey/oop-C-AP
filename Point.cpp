#include <iostream>
#include <cmath>
#include "Point.h"


using namespace std;


Point::Point()		//default constructor
{

}

Point::Point(int newX, int newY)		//overloads the constructor and allows the child classes to access this
{
	x = newX;  //gets the new point and sets x equal to it
	y = newY;

}

Point::~Point()	   //destructor
{


}
