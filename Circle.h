#pragma once
#include "Shape.h"
#include "Movable.h"
class Circle :
	public Shape, public Movable	//includes shape and movable
					  //Circle inherits from shape and movable
{
public:
	Circle(int x, int y, int r);	  //Creates functions
	int calculateArea();
	int calculatePerimeter();
	void calculatePoint();
	string toString();

	void move(int newX, int newY);
	void scale(float scaleX, float scaleY);

	bool Circular = true;	 //declared Circular as true even though its never used
	~Circle();		  //destructor


private:
	int radius;
	float pi = 3.1415;

	Point rightBottom;	   //declares the points needed for the shape

};
