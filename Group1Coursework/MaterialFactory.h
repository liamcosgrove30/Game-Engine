#pragma once
#include <iostream>
using namespace std;
#include "Materials.h"

class MaterialFactory
{
public:
	MaterialFactory() {}

	void addMaterial(char *name, char *theType);
	virtual Materials *CreateMaterial(char*, char*) = 0;
private:
	Materials *_material;
};