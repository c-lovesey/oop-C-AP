#pragma once
#include "Shape.h"
#include "Movable.h"

class Rectangle :public Shape, public Movable	   //includes shape and movable
					  //Circle inherits from shape and movable


{
public:

	Rectangle();							//Creates functions
	Rectangle(int x, int y, int h, int w);
	int calculateArea();
	int calculatePerimeter();
	void calculatePoint();
	string toString();

	void move(int x, int y);
	void scale(float scaleX, float scaleY);

	~Rectangle();







private:
	int height, width;

	Point rightTop;			    //declares the points needed for the shape
	Point rightBottom;
	Point leftBottom;
};