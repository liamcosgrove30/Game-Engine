/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "Inventory.h"
#include <algorithm>

Inventory::Inventory()
{
	//initliase states
	currAxeName = getCurrAxeName();
	currAxeValue = getCurrAxeValue();
	currPickName = getCurrPickName();
	currPickValue = getCurrPickValue();
	currSwordName = getCurrSwordName();
	currSwordDmg = getCurrSwordDmg();
	currSpearName = getCurrSpearName();
	currSpearDmg = getCurrSpearDmg();
	listMaterials = new list<Material*>();
}

Inventory::~Inventory()
{
	delete listMaterials;
}

void Inventory::addMaterial(Material* mat)
{
	listMaterials->push_back(mat);
}

void Inventory::removeMaterial(Material* mat)
{
	list<Material*>::iterator it = find(listMaterials->begin(), listMaterials->end(), mat);
	if (it != listMaterials->end())
	{
		delete *it;
		listMaterials->erase(it);
	}
}

Material* Inventory::getMaterial(string type)
{
	for (list<Material*>::iterator it = listMaterials->begin(); it != listMaterials->end(); ++it)
	{
		if (!((*it)->getID().compare(type)))
			return (*it);
	}
	return nullptr;
}

list<Material*> Inventory::getMaterials()
{
	return *listMaterials;
}

string Inventory::getID()
{
	return id;
}

void Inventory::getComponent(string name)
{
}

void Inventory::addComponent()
{
}

int Inventory::getValue()
{
	return value;
}

void Inventory::setValue(int num)
{
	value += num;
}

string Inventory::getCurrAxeName()
{
	return currAxeName;
}

void Inventory::setCurrAxeName(string name)
{
	currAxeName = name;
}

int Inventory::getCurrAxeValue()
{
	return currAxeValue;
}

void Inventory::setCurrAxeValue(int value)
{
	currAxeValue = value;
}

string Inventory::getCurrPickName()
{
	return currPickName;
}

void Inventory::setCurrPickName(string name)
{
	currPickName = name;
}

int Inventory::getCurrPickValue()
{
	return currPickValue;
}

void Inventory::setCurrPickValue(int value)
{
	currPickValue = value;
}

string Inventory::getCurrSwordName()
{
	return currSwordName;
}

void Inventory::setCurrSwordName(string name)
{
	currSwordName = name;
}

int Inventory::getCurrSwordDmg()
{
	return currSwordDmg;
}

void Inventory::setCurrSwordDmg(int value) 
{
	currSwordDmg = value;
}

string Inventory::getCurrSpearName()
{
	return currSpearName;
}

void Inventory::setCurrSpearName(string name)
{
	currSpearName = name;
}

int Inventory::getCurrSpearDmg()
{
	return currSpearDmg;
}

void Inventory::setCurrSpearDmg(int value)
{
	currSpearDmg = value;
}