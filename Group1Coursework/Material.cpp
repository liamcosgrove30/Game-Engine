/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/
 
#include "Material.h"

string Material::getID()
{
	return id;
}

int Material::getValue()
{
	return materialValue;
}

void Material::setValue(int num)
{
	materialValue += num;
}
void Material::getComponent(string name)
{}

void Material::addComponent()
{}
