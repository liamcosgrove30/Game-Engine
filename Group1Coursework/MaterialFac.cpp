/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "MaterialFac.h"

void MaterialFac::NewMaterial(char * theType)
{
	//debug
	//cout << "MaterialFac: NewMaterial()" << endl;
	_materials = CreateMaterial( theType);
	_materials->Start();
}

void MaterialFac::ReportMaterial()
{
	cout << "MaterialFac:ReportMaterials()" << endl;
}