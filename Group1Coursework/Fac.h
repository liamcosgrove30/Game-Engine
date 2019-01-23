/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include <iostream>
using namespace std;

#include "MaterialFac.h"
#include "Wood.h"
#include "Stone.h"
#include "Steel.h"

class Fac :public MaterialFac
{
public: 
	Fac(){}

	//used for creating materials
	Material* CreateMaterial(char *theType);
};