/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include <string>
#include <iostream>
using namespace std;

class AbstractWeapon
{
public:
	virtual ~AbstractWeapon() {};

	//get name
	virtual string getID() = 0;

	//get damage value
	virtual int getDmgValue() = 0;
};