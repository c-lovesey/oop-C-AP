

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string userCommand;				 //Creates a string to hold the user's input
	vector <Shape*> shapes;    	  //Initialises two vectors which hold the shapes generated and the paramaters inputted
	vector <string> parameters; 


	while (userCommand.compare("exit") != 0)
	{
		cout << "Enter the command: ";

		getline(cin, userCommand);	   //gets the line using cin and puts it into the string userCommand

		if (userCommand == "")
		{
			continue;
		}

		
		char* cstr = new char[userCommand.length() + 1];		  //Creates a character pointer

		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());
		char* token, * nexttoken;									//creates a new character token 
		token = strtok_s(cstr, " ", &nexttoken);
		while (token != NULL) {									   //while there is a value in token, token is added to paramaters, and token is set to the next value 
			parameters.push_back(token);
			token = strtok_s(NULL, " ", &nexttoken);
			
		}



		string command = parameters[0];

		//Checks the user input for the command used
		//This if statement checks if the command used is for rectangles 
		if (command.compare("addR") == 0) {				  

			if (parameters.size() == 5)	//verifies that the command has 4 variables so the code runs
			{	
				int x = stoi(parameters[1].c_str());	//sets the x value to the 1st input
				int y = stoi(parameters[2].c_str()); //sets the y value to the 2nd input
				int h = stoi(parameters[3].c_str());  //sets the h value to the 3rd input
				int w = stoi(parameters[4].c_str());  //sets the w value to the 4th input
				Rectangle* r = new Rectangle(x, y, h, w);	 // creates a new Rectangle called r with x,y,h,w as its paramaters
				cout << r->toString();	 //calls the toString(); function of the object and outputs the string it returns
				shapes.push_back(r);	  //puts the shape into the vector and moves to the next address
			}
			else 	//if there isnt 4 variables then it tells the user to reinput their command in the correct format
			{
				cout << "Please enter your command in the correct format.";
			}

		}
		else if (command.compare("addS") == 0) {	//All the basic validation is very similar just lengths and names are changed 

			if (parameters.size() == 4) {	//verifies that the command has 3 variables so the code runs
				int x = stoi(parameters[1].c_str());  //sets the x value to the 1st input
				int y = stoi(parameters[2].c_str());  //sets the y value to the 2nd input
				int e = stoi(parameters[3].c_str());  //sets the e value to the 3rd input

				Square* s = new Square(x, y, e);	// creates a new Square called r with x,y,e as its paramaters
				cout << s->toString();	//calls the toString(); function of the object and outputs the string it returns
				shapes.push_back(s);	 //puts the shape into the vector and moves to the next address
				
			}
			else 
			{
				cout << "Please enter your command in the correct format.";
			}

		}

		if (command.compare("addC") == 0) {	 //compares the user input to addC and if the output is 0 the if statement is activated

			if (parameters.size() == 4) {	   //verifies that the command has 3 variables so the code runs
				int x = stoi(parameters[1].c_str());	 //sets the x value to the 1st input
				int y = stoi(parameters[2].c_str());	 //sets the y value to the 2nd input
				int r = stoi(parameters[3].c_str());	 //sets the r value to the 3rd input

				Circle* c = new Circle(x, y, r);	  // creates a new Circle called c with x,y,r as its paramaters
				cout << c->toString(); //calls the toString(); function of the object and outputs the string it returns
				shapes.push_back(c);	 //puts the shape into the vector and moves to the next address
			}
			else
			{
				cout << "Please enter your command in the correct format.";
			}
		}


		
		else if (command.compare("scale") == 0) {		   //compares the user input to Scale and if the output is 0 the if statement is activated

			if (parameters.size() == 4) {	//verifies that the command has 3 variables so the code runs
				
				int shapeNo = stoi(parameters[1].c_str());	  //sets the shapeNo value to the 1st input

				if ((shapeNo-1 < shapes.size()) && (shapeNo > 0)) {	 //validation for the shape number to check that theres actually shapes in the position we are trying to change
					int x = stoi(parameters[2].c_str());		  //sets the x value to the 2nd input
					int y = stoi(parameters[3].c_str());		   //sets the y value to the 3rd input

					Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);		// creates a new Movable pointer called m with x,y as its paramaters with the shape object

					m->scale(x, y);		//calls scale
					cout << shapes[shapeNo - 1]->toString();	  //outputs the new m
				}
				else
				{
					cout << "Please enter your command in the correct format.";
				}
			}
			else
			{
				cout << "Please enter your command in the correct format.";
			}
		}
		else if (command.compare("move") == 0) {		  //compares the user input to Scale and if the output is 0 the if statement is activated
			if (parameters.size() == 4) {				  //verifies that the command has 3 variables so the code runs
				int shapeNo = stoi(parameters[1].c_str());	 //sets the shapeNo value to the 1st input
				
				if ((shapeNo - 1 < shapes.size()) && (shapeNo > 0)) {	    //validation for the shape number to check that theres actually shapes in the position we are trying to change
					int x = stoi(parameters[2].c_str());		  //sets the x value to the 2nd input
					int y = stoi(parameters[3].c_str());		  //sets the y value to the 3rd input

					Movable* m = dynamic_cast<Movable*>(shapes[shapeNo - 1]);	 // creates a new Movable pointer called m with x,y as its paramaters with the shape object
					m->move(x, y);										   //changes the points
					cout << shapes[shapeNo - 1]->toString();			 // outputs the new m
				}
				else
				{
					cout << "Please enter your command in the correct format.";
				}
			}
			else
			{
				cout << "Please enter your command in the correct format.";
			}
		}
		else if (command.compare("display") == 0) {					//Command to display all the shapes in the vector
			if (shapes.size() == 0)				 //checks theres shapes
			{
				cout << "Please input shapes and try again";	  
			}
			for (int i = 0; i < shapes.size(); i++)	  //outputs all the shapes in the vector
			{
				cout << shapes[i]->toString();
			}
		}

		parameters.clear();
		cout << "\n";

	}

	cout << "Press any key to continue...";

}
