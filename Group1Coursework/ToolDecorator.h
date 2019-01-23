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

class ToolDecorator :public AbstractTool {
private:
	AbstractTool * tool;
public:
	~ToolDecorator() { delete tool; };
	ToolDecorator(AbstractTool* tool) :tool(tool) {};
	
	//get name for decoration
	string getID() { return tool->getID(); }
	
	//get value of tool being decorated
	int getToolValue() { return tool->getToolValue(); }
};