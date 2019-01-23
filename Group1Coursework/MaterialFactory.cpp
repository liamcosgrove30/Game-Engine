#include "MaterialFactory.h"

void MaterialFactory::addMaterial(char * name, char * theType)
{
	cout << "MaterialFactory:addMaterial()" << endl;
	_material = CreateMaterial(name, theType);
	_material->Start();
}