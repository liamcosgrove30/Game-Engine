/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include <iostream>
using namespace std;
#include "Material.h"

class MaterialFac {
public:
	MaterialFac(){}

	//initialise new material
	void NewMaterial(char *theType);

	//debugging
	void StartMaterial() {}
	void ReportMaterial();

	//used for creating materials
	virtual Material *CreateMaterial(char*) = 0;
private:
	Material *_materials;
};