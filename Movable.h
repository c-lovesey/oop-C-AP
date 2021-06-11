#pragma once
#include <vector>
#include <string>
using namespace std;
class Movable
{
public:

	Movable();	 //default constructor
	~Movable();	//deconstructor

	virtual void move(int newX, int newY);			 //Creates move and scale to be inherited by other headers
	virtual void scale(float scaleX, float scaleY);

	int x, y;
private:


};




