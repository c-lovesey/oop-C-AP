
#pragma once
class Point
{
private:
	int x, y;

public:
	Point();
	Point(int newX, int newY);


	~Point();


	int getx() {	   //returns x and y when this is  called
		return x;
	}
	int gety() {
		return y;
	}



	void setx(int newX) {	  //gets in a new value of x and y and sets it to the current value
		x = newX;
	}
	void sety(int newY) {
		y = newY;
	}


};



