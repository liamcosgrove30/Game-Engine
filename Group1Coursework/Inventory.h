/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include <iostream>
#include <list>
using namespace std;
#include "Material.h"
#include "Container.h"


class Inventory
{
public: 
	Inventory();
	~Inventory();

	void addMaterial(Material* mat);
	void removeMaterial(Material* mat);
	Material *getMaterial(string type);
	list<Material*> getMaterials();

	//axe in inventory
	string getCurrAxeName();
	int getCurrAxeValue();
	void setCurrAxeName(string name);
	void setCurrAxeValue(int value);

	//pickaxe in inventory
	string getCurrPickName();
	int getCurrPickValue();
	void setCurrPickName(string name);
	void setCurrPickValue(int value);

	//sword in inventory
	string getCurrSwordName();
	int getCurrSwordDmg();
	void setCurrSwordName(string name);
	void setCurrSwordDmg(int value);

	//spear in inventory
	string getCurrSpearName();
	int getCurrSpearDmg();
	void setCurrSpearName(string name);
	void setCurrSpearDmg(int value);

	//inherited from container
	string getID();
	void getComponent(string name);
	void addComponent();
	int getValue();
	void setValue(int num);

private:
	list<Material*>* listMaterials;
	string currAxeName;
	int currAxeValue = 0;
	string currPickName;
	int currPickValue = 0;
	string currSwordName;
	int currSwordDmg = 0;
	string currSpearName;
	int currSpearDmg = 0;
	string id;
	int value;
};