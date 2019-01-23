/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "MineState.h"
#include <iostream>

using namespace std;

MineState::MineState()
{}

void MineState::handle(Player* player)
{
	//formatting
	cout << "CURRENT AREA: MINE \n" << "---------------------------------\n" << " press 0 to go to Crafting \n press 1 to go to Forest \n press 2 to go to Arena \n press 3 to go to your Inventory \n press 4 to mine Stone \n press 5 to mine Steel." << endl;
	cout << "---------------------------------" << endl;
	int option;
	cin >> option;
	switch (option)
	{
	case 0:
		//crafting area
		//clear screen
		system("CLS");
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	case 1:
		//forest area
		//clear screen
		system("CLS");
		player->setCurrentState(player->getForestState());
		player->getCurrentState()->handle(player);
		break;
	case 2:
		//arena area
		//clear screen
		system("CLS");
		player->setCurrentState(player->getArenaState());
		player->getCurrentState()->handle(player);
		break;
	case 3:
		//inventory
		//clear screen
		system("CLS");
		player->setCurrentState(player->getInventoryState());
		player->getCurrentState()->handle(player);
		break;
	case 4: {
		//clear the screen
		system("CLS");
		//mining stone
		//initialise new stone material
		Material* stone = player->getInventory()->getMaterial("stone");
		if (stone != nullptr)
		{
			//check if stone isn't null and then add stone to inventory based on tool equipped
			stone->setValue(0 + player->getInventory()->getCurrPickValue());
		}
		else {
			//else add material from factory to inventory and then add stone to inventory based on tool equipped
			player->getInventory()->addMaterial(factory.CreateMaterial("stone"));
			stone = player->getInventory()->getMaterial("stone");
			stone->setValue(0 + player->getInventory()->getCurrPickValue());
		}
		cout << "You have " << stone->getValue() << " stone inside your inventory\n" << endl;
		//keep state as mine state
		player->setCurrentState(player->getMineState());
		player->getCurrentState()->handle(player);
		break;}
	case 5: {
		system("CLS");
		//mining steel
		//initialise new steel material
		Material* steel = player->getInventory()->getMaterial("steel");
		if (steel != nullptr)
		{
			//check if steel isn't null and then add stone to inventory based on tool equipped
			steel->setValue(0 + player->getInventory()->getCurrPickValue());
		}
		else {
			//else add material from factory to inventory and then add steel to inventory based on tool equipped
			player->getInventory()->addMaterial(factory.CreateMaterial("steel"));
			steel = player->getInventory()->getMaterial("steel");
			steel->setValue(0 + player->getInventory()->getCurrPickValue());
		}
		cout << "You have " << steel->getValue() << " steel inside your inventory\n" << endl;
		player->setCurrentState(player->getMineState());
		player->getCurrentState()->handle(player);
		break;}
	default:
		//clear screen
		system("CLS");
		cout << "please try again\n" << endl;
		player->getCurrentState()->handle(player);
	}
	
}