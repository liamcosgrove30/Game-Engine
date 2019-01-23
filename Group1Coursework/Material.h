/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include <iostream>
#include "Component.h"
using namespace std;

//base class for all materials

class Material: public Component{
public:
	Material(char *theType)
	{
		//type of material
		string temp(theType);

		//naming each material
		id = temp;
	}

	virtual void Start() = 0;
	virtual void Stop() = 0;

	//get name
	string getID();

	//get quantity material
	int getValue();

	void setValue(int num);
	void addComponent();

	//getting each component
	void getComponent(string name);

private:
	string id;

	//initialising value
	int materialValue = 0;
};