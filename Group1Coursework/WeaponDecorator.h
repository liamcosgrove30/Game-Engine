/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include <string>
#include <iostream>
#include "AbstractWeapon.h"
using namespace std;

class WeaponDecorator :public AbstractWeapon {
private:
	AbstractWeapon * weapon;
public:
	~WeaponDecorator() { delete weapon; };
	WeaponDecorator(AbstractWeapon* weapon) :weapon(weapon) {};

	//get name of weapon to be decorated
	string getID() { return weapon->getID(); }

	//get value
	int getDmgValue() { return weapon->getDmgValue(); }
};