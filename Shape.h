#pragma once
#include <string>
#include "Point.h"
#include <vector>
using namespace std;
class Shape
{
protected:

	Point leftTop;			     //declares the points needed for the shape
	vector<Point> points;
	int area, perimeter;

public:
	bool Circular = false;

	virtual int calculateArea();
	virtual int calculatePerimeter();
	virtual void calculatePoint();
	virtual string toString();

	Shape();

	virtual ~Shape();

private:
};





