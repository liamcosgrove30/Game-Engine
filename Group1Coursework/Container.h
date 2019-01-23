/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include <vector>
#include <string>
#include "Component.h"
using namespace std;

class Container {
private:
	vector<Component*> comp;
public:
	virtual string getID() = 0;
	virtual void getComponent(string name) = 0;
	virtual void addComponent() = 0;
	virtual int getValue() = 0;
	virtual void setValue(int num) = 0;
};