/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include "AbstractTool.h"
#include <string>
#include <iostream>
using namespace std;

class Pickaxe : public AbstractTool {
private:
	
	//tool name
	string id;
protected:

	//tool value
	int toolValue;
public:
	virtual ~Pickaxe() {};
	Pickaxe(string name, int value) :id(name), toolValue(value) {}
	
	//get tool name
	string getID() { return id; }
	
	//get tool collector value
	int getToolValue() { return toolValue; }
};