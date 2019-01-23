/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include <string>
#include <iostream>
#include "WeaponDecorator.h"
using namespace std;

class Sharp :public WeaponDecorator {
private:

	//damage modifier
	int dmgMod = 35;
public:
	virtual ~Sharp() {};
	Sharp(AbstractWeapon * weapon) :WeaponDecorator(weapon) {}

	//applying modifier
	inline int getDmgValue() { return WeaponDecorator::getDmgValue() + dmgMod; }
};