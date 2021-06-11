#pragma once
#include "Square.h"
#include <iostream>
#include "Shape.h"
#include "Movable.h"
using namespace std;
#include <cmath>



Square::Square(int x, int y, int e) {	  //overloads the constructor
	edge = e;									  //sets edge to e

	leftTop.setx(x);	   //sets x and y to the new values
	leftTop.sety(y);

	area = calculateArea();				//calculates the area, perimeter and points
	perimeter = calculatePerimeter();
	calculatePoint();
}
Square::~Square() {}



int Square::calculateArea()	   //calculates the area using edge
{
	area = edge * edge;
	return area;
};
int Square::calculatePerimeter()		  //calculates the perimeter using perimeter
{
	perimeter = 4 * edge;
	return perimeter;
};
void Square::calculatePoint()
{
	points.clear();
	int newX, newY;
	newX = leftTop.getx();	  //gets x and y
	newY = leftTop.gety();

	rightTop = Point(newX + edge, newY);		 //sets the points using edge and the x and y
	rightBottom = Point(newX + edge, newY + edge);
	leftBottom = Point(newX, newY + edge);

	points.push_back(leftTop);
	points.push_back(rightTop);
	points.push_back(rightBottom);
	points.push_back(leftBottom);
};


string Square::toString() {

	string result = "\nSquare[e=" + to_string(edge) + "]\nPoints[(" +
		to_string(leftTop.getx()) + "," + to_string(leftTop.gety()) + ")(" +
		to_string(rightTop.getx()) + "," + to_string(rightTop.gety()) + ")(" +
		to_string(rightBottom.getx()) + "," + to_string(rightBottom.gety()) + ")(" +
		to_string(leftBottom.getx()) + "," + to_string(leftBottom.gety()) + ")]\nArea=" +
		to_string(area) + " Perimeter=" + to_string(perimeter) + "\n"
		;

	//concatanates the variables into a string called result and returns it
	return result;

}

void Square::move(int newX, int newY) {

	leftTop.setx(newX);			   //sets x and y to the new values
	leftTop.sety(newY);

	area = calculateArea();
	perimeter = calculatePerimeter();
	calculatePoint();			   //calculates the new points

};

void Square::scale(float scaleX, float scaleY) {

	edge = edge * scaleX;

	area = calculateArea();		//calculates the new shape using the new edge
	perimeter = calculatePerimeter();
	calculatePoint();

};
