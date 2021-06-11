#pragma once
#include <iostream>
#include "Rectangle.h"
#include "Shape.h"
#include "Movable.h"
#include <cmath>
#include <vector>

using namespace std;

Rectangle::Rectangle() {	  //default constructor

}
Rectangle::~Rectangle() {}	 //destructor


Rectangle::Rectangle(int x, int y, int h, int w) {		//overloads the constructor
	height = h;			 //sets height to h
	width = w;			   //sets width to w

	leftTop.setx(x);		//sets x and y
	leftTop.sety(y);

	area = calculateArea();			//calculates the area, perimeters and points
	perimeter = calculatePerimeter();
	calculatePoint();

}




string Rectangle::toString() {

	string result = "\nRectangle[h=" + to_string(height) + ",w=" + to_string(width) + "]\nPoints[(" +
		to_string(leftTop.getx()) + "," + to_string(leftTop.gety()) + ")(" +
		to_string(rightTop.getx()) + "," + to_string(rightTop.gety()) + ")(" +
		to_string(rightBottom.getx()) + "," + to_string(rightBottom.gety()) + ")(" +
		to_string(leftBottom.getx()) + "," + to_string(leftBottom.gety()) + ")]\nArea=" +
		to_string(area) + " Perimeter=" + to_string(perimeter) + "\n"
		;

	//concatanates the variables into a string called result and returns it
	return result;
}



int Rectangle::calculateArea()
{
	int area = height * width;			  //calculates area by multiplying height and width
	return area;
};

int Rectangle::calculatePerimeter()
{
	double perimeter = height * 2 + width * 2;	 //calculates perimeter by adding 2* height and 2 * width
	return perimeter;
};

void Rectangle::calculatePoint()
{
	points.clear();				//clears the vector points
	int newX, newY;
	newX = leftTop.getx();	   //gets x
	newY = leftTop.gety();		 //gets y

	rightTop = Point(newX + width, newY);	   //sets the points using the newX and newY
	rightBottom = Point(newX + width, newY + height);
	leftBottom = Point(newX, newY + height);

	points.push_back(leftTop);
	points.push_back(rightTop);
	points.push_back(rightBottom);
	points.push_back(leftBottom);

};


void Rectangle::move(int newX, int newY) {

	leftTop.setx(newX);			   //sets x and y to the new x and new y
	leftTop.sety(newY);

	area = calculateArea();					  //calls these functions, only calculate point is changing values
	perimeter = calculatePerimeter();
	calculatePoint();

};

void Rectangle::scale(float scaleX, float scaleY) {

	height = height * scaleY;	  //calculates the new height and width using scale
	width = width * scaleX;

	area = calculateArea();		  //calls these functions to calculate the new shape dimentions
	perimeter = calculatePerimeter();
	calculatePoint();

};