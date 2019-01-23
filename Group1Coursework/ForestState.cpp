/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "ForestState.h"
#include <iostream>

using namespace std;

ForestState::ForestState()
{}

void ForestState::handle(Player* player)
{
	//formatting
	cout << "CURRENT AREA: FOREST \n" << "---------------------------------\n" << " press 0 to go to Crafting \n press 1 to go to Mine \n press 2 to go to Arena \n press 3 to go to your Inventory \n press 4 to mine Wood" << endl;
	cout << "---------------------------------" << endl;
	int option;
	cin >> option;
	switch (option)
	{
	case 0:
		//clear screen
		system("CLS");
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	case 1:
		//clear screen
		system("CLS");
		player->setCurrentState(player->getMineState());
		player->getCurrentState()->handle(player);
		break;
	case 2:
		//clear screen
		system("CLS");
		player->setCurrentState(player->getArenaState());
		player->getCurrentState()->handle(player);
		break;
	case 3:
		//clear screen
		system("CLS");
		player->setCurrentState(player->getInventoryState());
		player->getCurrentState()->handle(player);
		break;
	case 4: {
		//clears screen
		system("CLS");
		//initialises wood material
		Material* wood = player->getInventory()->getMaterial("wood");
		if (wood != nullptr)
		{
			//check if wood isn't null and add wood material to inventory
			wood->setValue(1 + player->getInventory()->getCurrAxeValue());
		}
		else {
			//else add material from factory to inventory and then add wood to inventory based on tool equipped
			player->getInventory()->addMaterial(factory.CreateMaterial("wood"));
			wood = player->getInventory()->getMaterial("wood");
			wood->setValue(1 + player->getInventory()->getCurrAxeValue());
		}
		cout << "You have " << wood->getValue() <<  " wood inside your inventory\n" << endl;
		player->setCurrentState(player->getForestState());
		player->getCurrentState()->handle(player);
		break;}
	default:
		//clear screen
		system("CLS");
		cout << "please try again\n" << endl;
		player->getCurrentState()->handle(player);
	}
}