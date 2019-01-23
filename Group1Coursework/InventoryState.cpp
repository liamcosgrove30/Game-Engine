/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "InventoryState.h"
#include "Player.h"
#include <iostream>

using namespace std;

InventoryState::InventoryState()
{

}

//displaying all the materials in the inventory
void InventoryState::displayItems(Player* player)
{
	list<Material*> listMaterials = player->getInventory()->getMaterials();	
	for (list<Material*> ::iterator it = listMaterials.begin(); it != listMaterials.end(); ++it)
	{
		cout << (*it)->getID() << ": " << (*it)->getValue() << endl;
	}
}

void InventoryState::handle(Player* player)
{
	//display instructions to player
	cout << "CURRENT AREA: INVENTORY \n" << "---------------------------------\n" << " press 0 to go to Forest \n press 1 to go to Mine"
		"\n press 2 to go to Arena \n press 3 to go to the Crafting." << endl;
	cout << "---------------------------------" << endl;
	
	//displays current tools
	cout << "\nCurrent Tools: \nAxe - " << player->getInventory()->getCurrAxeName() << ": Mining Value - " <<player->getInventory()->getCurrAxeValue() << endl;
	cout << "Pickaxe - " << player->getInventory()->getCurrPickName() << ": Mining Value - " << player->getInventory()->getCurrPickValue() << "\n" << endl;

	//displays current weapons
	cout << "\nCurrent Weapons: \nSword - " << player->getInventory()->getCurrSwordName() << ": Damage - " << player->getInventory()->getCurrSwordDmg() << endl;
	cout << "Spear - " << player->getInventory()->getCurrSpearName() << ": Damage - " << player->getInventory()->getCurrSpearDmg() << "\n" << endl;


	//display list of items in inventory when player first enters inventory area
	displayItems(player);
	int option;
	cin >> option;
	switch (option)
	{
	case 0: 
		//clear screen
		system("CLS");
		player->setCurrentState(player->getForestState());
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
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	default:
		//clear screen
		system("CLS");
		cout << "please try again\n" << endl;
		player->getCurrentState()->handle(player);
	}

}