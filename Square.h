#pragma once
#include "Shape.h"
#include "Movable.h"
class Square :public Shape, public Movable	  //includes shape and movable
					  //Circle inherits from shape and movable


{

public:
	Square(int x, int y, int e);		  //Declares functions
	~Square();

	void move(int newX, int newY);

	void scale(float scaleX, float scaleY);

	int calculateArea();
	int calculatePerimeter();
	void calculatePoint();
	string toString();
private:
	int edge;


	Point rightTop;					   //declares the points needed for the shape
	Point rightBottom;
	Point leftBottom;

};