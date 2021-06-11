#include "Circle.h"
#pragma once
#include <iostream>
#include "Shape.h"
#include "Movable.h"
#include <cmath>
using namespace std;

Circle::Circle(int x, int y, int r) {
	radius = r;	  //sets radius to the new r

	leftTop.setx(x);   //sets x and y
	leftTop.sety(y);

	area = calculateArea();	  //calculates area
	perimeter = calculatePerimeter(); //calculates perimeter
	calculatePoint();						  //calculates the points

}


int Circle::calculateArea()

{
	area = pi * (radius * radius);	//area for a circle is calculated by using pi * r^2
	return area;						   //returns the area
};

int Circle::calculatePerimeter()
{
	perimeter = 2 * radius * pi;	 //perimeter for a circle is calculated by using 2* pi * r
	return perimeter;					// returns the perimeter
}


void Circle::calculatePoint()
{
	points.clear();	  //clears the points from memory
	int newX, newY;
	newX = leftTop.getx();	 //gets the x value
	newY = leftTop.gety();	 //	gets the y value


	rightBottom = Point(newX + (2 * radius), newY + (2 * radius));	  //calculates the bottom right point using 

	points.push_back(leftTop);			//puts LeftTop and rightBottom int points
	points.push_back(rightBottom);
};

string Circle::toString() {
	string result = "\nCircle[r=" + to_string(radius) + "]\nPoints[(" +
		to_string(leftTop.getx()) + "," + to_string(leftTop.gety()) + ")(" +
		to_string(rightBottom.getx()) + "," + to_string(rightBottom.gety()) +
		")]\nArea=" + to_string(area) + " Perimeter=" + to_string(perimeter) + "\n"
		;
	   //concatanates the variables into a string called result and returns it

	return result;
}

void Circle::move(int newX, int newY) {

	leftTop.setx(newX);		   //sets the x and y in point to the new x and y from move
	leftTop.sety(newY);

	area = calculateArea();		 //doesnt calculate a new area but calls it so the output is correct
	perimeter = calculatePerimeter();
	calculatePoint();				  //calculates the new points

};

void Circle::scale(float scaleX, float scaleY) {

	radius = radius * scaleX;		//scales the radius up linearly by the ammount in scaleX

	area = calculateArea();		  //calculates a new area
	perimeter = calculatePerimeter();  //calculates a new perimeter
	calculatePoint();		   //calculates the new points

};



Circle::~Circle() {};