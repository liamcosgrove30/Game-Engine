/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "Fac.h"

Material * Fac::CreateMaterial(char * theType)
{
	//debug - display when creating a material
	//cout << " CreateMaterial: createMaterial()" << endl;
	if (theType == "wood")
		return new Wood(theType);
	else if (theType == "stone")
		return new Stone(theType);
	else if (theType == "steel")
		return new Steel(theType);
}