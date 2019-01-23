/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "CraftingState.h"
#include "Player.h"
#include <iostream>
#include "AbstractTool.h"
#include "Axe.h"
#include "WoodenQuality.h"

using namespace std;
CraftingState::CraftingState()
{}

void CraftingState::handle(Player* player)
{
	//formatting
	cout << "CURRENT AREA: CRAFTING AREA \n" << "---------------------------------\n" << " press 0 to go to Forest \n press 1 to go to Mine \n press 2 to go to Arena \n press 3 to go to your Inventory \n";
	cout << "\n press 4 to craft a Wooden Axe ---- Costs 10 Wood \n press 5 to craft a Stone Axe ---- Costs 5 Wood and 15 Stone \n press 6 to craft a Steel Axe ---- Costs 10 Wood and 30 Steel \n press 7 to craft a Wooden Pickaxe ---- Costs 10 Wood \n press 8 to craft a Stone Pickaxe ---- Costs 5 Wood and 15 Stone \n press 9 to craft a Steel Pickaxe ---- Costs 10 Wood and 30 Steel." << endl;
	cout << "\n press 10 to craft a Rusty Sword ---- Costs 20 Steel \n press 11 to repair your Sword ---- Costs 50 Steel \n press 12 to sharpen your Sword ---- Costs 100 Steel." << endl;
	cout << "\n press 13 to craft a Rusty Spear ---- Costs 20 Steel \n press 14 to repair your Spear ---- Costs 50 Steel \n press 15 to sharpen your Spear ---- Costs 100 Steel." << endl;
	cout << "---------------------------------" << endl;
	
	int option;
	cin >> option;
	switch (option)
	{
	case 0:
	{
		//clear screen
		system("CLS");
		player->setCurrentState(player->getForestState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 1:
	{
		//clear screen
		system("CLS");
		player->setCurrentState(player->getMineState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 2:
	{
		//clear screen
		system("CLS");
		player->setCurrentState(player->getArenaState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 3:
	{
		//clear screen
		system("CLS");
		player->setCurrentState(player->getInventoryState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 4:
	{
		system("CLS");
		//checks if player already has crafted wood axe
		//if not
		if (!hasWoodAxe)
		{
			//if wood has been collected
			if (player->getInventory()->getMaterial("wood")!= nullptr)
			{
				//check there is more than ten, take away required amount and if there is create a wooden axe and add to inventory
				if (player->getInventory()->getMaterial("wood")->getValue() >= 10) {
					AbstractTool* woodenAxe = new WoodenQuality(new Axe("wood axe", 2));
					player->getInventory()->getMaterial("wood")->setValue(-10);
					player->getInventory()->setCurrAxeName("wood axe");
					player->getInventory()->setCurrAxeValue(woodenAxe->getToolValue());
					cout << "name: " << woodenAxe->getID(); cout << endl;
					cout << "value: " << woodenAxe->getToolValue(); cout << endl;
					hasWoodAxe = true;
				}
				else { cout << "do not have enough wood \n" << endl; }
			}			
			else { cout << "do not have enough wood \n" << endl; }
		}
		else if(hasWoodAxe){ cout << "already have a wood axe\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 5:
	{
		system("CLS");
		//check if wooden axe has been crafted and stone axe hasn't
		if (hasWoodAxe)
		{
			if (!hasStoneAxe)
			{
				//check wood and stone have been collected
				if (player->getInventory()->getMaterial("wood") != nullptr && player->getInventory()->getMaterial("stone") != nullptr)
				{
					//check if there are enough materials and craft a stone axe
					if (player->getInventory()->getMaterial("wood")->getValue() >= 5 && player->getInventory()->getMaterial("stone")->getValue() >= 15)
					{
						AbstractTool* stoneAxe = new StoneQuality(new Axe("stone axe", 2));
						//remove materials used for crafting
						player->getInventory()->getMaterial("wood")->setValue(-5);
						player->getInventory()->getMaterial("stone")->setValue(-15);
						//set current axe to stone axe
						player->getInventory()->setCurrAxeName("stone axe");
						player->getInventory()->setCurrAxeValue(stoneAxe->getToolValue());
						cout << "name: " << stoneAxe->getID(); cout << endl;
						cout << "value: " << stoneAxe->getToolValue(); cout << endl;
						hasStoneAxe = true;
					}
					else { cout << "do not have enough stone\n" << endl; }
				}
				else { cout << "do not have enough stone\n" << endl; }
			}
			else { cout << "already have a stone axe\n" << endl; }
		}
		else { cout << "You must craft a Wooden Axe First\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 6:
	{
		system("CLS");
		//check stone axe has been made and steel axe hasn't
		if (hasStoneAxe)
		{
			if (!hasSteelAxe)
			{
				//check wood and steel been collected
				if (player->getInventory()->getMaterial("wood") != nullptr && player->getInventory()->getMaterial("steel") != nullptr)
				{
					//check if required materials are in inventory and if they are then craft steel axe
					if (player->getInventory()->getMaterial("wood")->getValue() >= 10 && player->getInventory()->getMaterial("steel")->getValue() >= 30)
					{
						AbstractTool* steelAxe = new SteelQuality(new Axe("steel axe", 2));
						//remove materials used for crafting
						player->getInventory()->getMaterial("wood")->setValue(-10);
						player->getInventory()->getMaterial("steel")->setValue(-30);
						player->getInventory()->setCurrAxeName("steel axe");
						player->getInventory()->setCurrAxeValue(steelAxe->getToolValue());
						cout << "name: " << steelAxe->getID(); cout << endl;
						cout << "value: " << steelAxe->getToolValue(); cout << endl;
						hasSteelAxe = true;
					}
					else { cout << "do not have enough steel\n" << endl; }
				}
				else { cout << "do not have enough steel\n" << endl; }
			}
			else { cout << "already have a steel axe\n" << endl; }
		}
		else { cout << "You must craft a Stone Axe first\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 7: 
	{
		system("CLS");
		//check if wooden pickaxe been crafted
		if (!hasWoodPickaxe)
		{
			//check if wood has been crafted
			if (player->getInventory()->getMaterial("wood") != nullptr)
			{
				//check there is more than ten, take away required amount and if there is create a wooden pickaxe and add to inventory
				if (player->getInventory()->getMaterial("wood")->getValue() >= 10) {
					AbstractTool* woodenPickaxe = new WoodenQuality(new Pickaxe("wood pickaxe", 1));
					player->getInventory()->getMaterial("wood")->setValue(-10);
					player->getInventory()->setCurrPickName("wood pickaxe");
					player->getInventory()->setCurrPickValue(woodenPickaxe->getToolValue());
					cout << "name: " << woodenPickaxe->getID(); cout << endl;
					cout << "value: " << woodenPickaxe->getToolValue(); cout << endl;
					hasWoodPickaxe = true;
				}
				else { cout << "do not have enough wood\n" << endl; }
			}
			else { cout << "do not have enough wood\n" << endl; }
		}
		else if (hasWoodPickaxe) { cout << "already have a wood pickaxe\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 8:
	{
		system("CLS");
		//check if wooden pickaxe has been crafted and stone pickaxe hasn't
		if (hasWoodPickaxe)
		{
			if (!hasStonePickaxe)
			{
				//check wood and stone have been collected
				if (player->getInventory()->getMaterial("wood") != nullptr && player->getInventory()->getMaterial("stone") != nullptr)
				{
					//check if there are enough materials and craft a stone pickaxe
					if (player->getInventory()->getMaterial("wood")->getValue() >= 5 && player->getInventory()->getMaterial("stone")->getValue() >= 15)
					{
						AbstractTool* stonePickaxe = new StoneQuality(new Pickaxe("stone pickaxe", 2));
						player->getInventory()->getMaterial("wood")->setValue(-5);
						player->getInventory()->getMaterial("stone")->setValue(-15);
						player->getInventory()->setCurrPickName("stone pickaxe");
						player->getInventory()->setCurrPickValue(stonePickaxe->getToolValue());
						cout << "name: " << stonePickaxe->getID(); cout << endl;
						cout << "value: " << stonePickaxe->getToolValue(); cout << endl;
						hasStonePickaxe = true;
					}
					else { cout << "do not have enough stone\n" << endl; }
				}
				else { cout << "do not have enough stone\n" << endl; }
			}
			else { cout << "already have a stone pickaxe\n" << endl; }
		}
		else { cout << "You must craft a Wooden Pickaxe First\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 9:
	{
		system("CLS");
		//check stone pickaxe has been made and steel pickaxe hasn't
		if (hasStonePickaxe)
		{
			if (!hasSteelPickaxe)
			{
				//check wood and steel been collected
				if (player->getInventory()->getMaterial("wood") != nullptr && player->getInventory()->getMaterial("steel") != nullptr)
				{
					//check if required materials are in inventory and if they are then craft steel pickaxe
					if (player->getInventory()->getMaterial("wood")->getValue() >= 10 && player->getInventory()->getMaterial("steel")->getValue() >= 30)
					{
						AbstractTool* steelPickaxe = new SteelQuality(new Pickaxe("steel pickaxe", 2));
						player->getInventory()->getMaterial("wood")->setValue(-10);
						player->getInventory()->getMaterial("steel")->setValue(-30);
						player->getInventory()->setCurrAxeName("steel pickaxe");
						player->getInventory()->setCurrAxeValue(steelPickaxe->getToolValue());
						cout << "name: " << steelPickaxe->getID(); cout << endl;
						cout << "value: " << steelPickaxe->getToolValue(); cout << endl;
						hasSteelPickaxe = true;
					}
					else { cout << "do not have enough steel\n" << endl; }
				}
				else { cout << "do not have enough steel\n" << endl; }
			}
			else { cout << "already have a steel pickaxe\n" << endl; }
		}
		else { cout << "You must craft a Stone Pickaxe first\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 10:
	{
		system("CLS");
		//check if rusty sword has not been crafted
		if (!isRustySword)
		{
			//check that steel has been gathered
			if (player->getInventory()->getMaterial("steel") != nullptr)
			{
				//check there is enough steel and if there is then craft weapon
				if (player->getInventory()->getMaterial("steel")->getValue() >= 20) {
					AbstractWeapon* rustySword = new Rusty(new Sword("rusty sword", 0));
					player->getInventory()->getMaterial("steel")->setValue(-20);
					player->getInventory()->setCurrSwordName("rusty sword");
					player->getInventory()->setCurrSwordDmg(rustySword->getDmgValue());
					cout << "name: " << rustySword->getID(); cout << endl;
					cout << "value: " << rustySword->getDmgValue(); cout << endl;
					isRustySword = true;
				}
				else { cout << "do not have enough steel\n" << endl; }
				
			}
			else { cout << "do not have enough steel\n" << endl; }
		}
		else if (isRustySword) { cout << "already have a Rusty Sword\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 11:
	{
		system("CLS");
		//cehck if rusty sword been crafted and blunt sword has not
		if (isRustySword)
		{
			if (!isBluntSword)
			{
				//check that steel has been gathered
				if (player->getInventory()->getMaterial("steel") != nullptr)
				{
					//check there is enough steel and if there is then craft weapon
					if (player->getInventory()->getMaterial("steel")->getValue() >= 50)
					{
						AbstractWeapon* bluntSword = new Blunt(new Sword("blunt Sword", 0));
						player->getInventory()->getMaterial("steel")->setValue(-50);
						player->getInventory()->setCurrSwordName("blunt sword");
						player->getInventory()->setCurrSwordDmg(bluntSword->getDmgValue());
						cout << "name: " << bluntSword->getID(); cout << endl;
						cout << "value: " << bluntSword->getDmgValue(); cout << endl;
						isBluntSword = true;
					}
					else { cout << "do not have enough steel\n" << endl; }
				}
				else { cout << "do not have enough steel\n" << endl; }
			}
			else { cout << "already have a Blunt Sword\n" << endl; }
		}
		else { cout << "You must craft a Rusty Sword First\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 12:
	{
		system("CLS");
		//check if blunt sword has been crafted and sharp sword has not
		if (isBluntSword)
		{
			if (!isSharpSword)
			{
				//check that steel has been gathered
				if (player->getInventory()->getMaterial("steel") != nullptr)
				{
					//check there is enough steel and if there is then craft weapon
					if (player->getInventory()->getMaterial("steel")->getValue() >= 100)
					{
						AbstractWeapon* sharpSword = new Sharp(new Sword("sharp sword", 0));
						player->getInventory()->getMaterial("steel")->setValue(-100);
						player->getInventory()->setCurrSwordName("sharp sword");
						player->getInventory()->setCurrSwordDmg(sharpSword->getDmgValue());
						cout << "name: " << sharpSword->getID(); cout << endl;
						cout << "value: " << sharpSword->getDmgValue(); cout << endl;
						isSharpSword = true;
					}
					else { cout << "do not have enough steel\n" << endl; }
				}
				else { cout << "do not have enough steel\n" << endl; }
			}
			else { cout << "already have a sharp sword\n" << endl; }
		}
		else { cout << "You must have a Blunt Sword first\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 13:
	{
		system("CLS");
		//check if rusty spear hasn't been crafted
		if (!isRustySpear)
		{
			//check that steel has been gathered
			if (player->getInventory()->getMaterial("steel") != nullptr)
			{
				//check there is enough steel and if there is then craft weapon
				if (player->getInventory()->getMaterial("steel")->getValue() >= 20) {
					AbstractWeapon* rustySpear = new Rusty(new Spear("rusty spear", 0));
					player->getInventory()->getMaterial("steel")->setValue(-20);
					player->getInventory()->setCurrSpearName("rusty spear");
					player->getInventory()->setCurrSpearDmg(rustySpear->getDmgValue());
					cout << "name: " << rustySpear->getID(); cout << endl;
					cout << "value: " << rustySpear->getDmgValue(); cout << endl;
					isRustySpear = true;
				}
				else { cout << "do not have enough steel\n" << endl; }

			}
			else { cout << "do not have enough steel\n" << endl; }
		}
		else if (isRustySword) { cout << "already have a Rusty Spear\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 14:
	{
		system("CLS");
		//check if rusty spear has been crafted and blunt spear has not
		if (isRustySpear)
		{
			if (!isBluntSpear)
			{
				//check that steel has been gathered
				if (player->getInventory()->getMaterial("steel") != nullptr)
				{
					//check there is enough steel and if there is then craft weapon
					if (player->getInventory()->getMaterial("steel")->getValue() >= 50)
					{
						AbstractWeapon* bluntSpear = new Blunt(new Spear("blunt spear", 0));
						player->getInventory()->getMaterial("steel")->setValue(-50);
						player->getInventory()->setCurrSpearName("blunt spear");
						player->getInventory()->setCurrSpearDmg(bluntSpear->getDmgValue());
						cout << "name: " << bluntSpear->getID(); cout << endl;
						cout << "value: " << bluntSpear->getDmgValue(); cout << endl;
						isBluntSpear = true;
					}
					else { cout << "do not have enough steel\n" << endl; }
				}
				else { cout << "do not have enough steel\n" << endl; }
			}
			else { cout << "already have a Blunt Spear\n" << endl; }
		}
		else { cout << "You must craft a Rusty Spear First\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	case 15:
	{
		system("CLS");
		//check if blunt spear has been crafted and sharp spear has not
		if (isBluntSpear)
		{
			if (!isSharpSpear)
			{
				//check that steel has been gathered
				if (player->getInventory()->getMaterial("steel") != nullptr)
				{
					//check there is enough steel and if there is then craft weapon
					if (player->getInventory()->getMaterial("steel")->getValue() >= 100)
					{
						AbstractWeapon* sharpSpear = new Sharp(new Spear("sharp spear", 0));
						player->getInventory()->getMaterial("steel")->setValue(-100);
						player->getInventory()->setCurrSpearName("sharp spear");
						player->getInventory()->setCurrSpearDmg(sharpSpear->getDmgValue());
						cout << "name: " << sharpSpear->getID(); cout << endl;
						cout << "value: " << sharpSpear->getDmgValue(); cout << endl;
						isSharpSpear = true;
					}
					else { cout << "do not have enough steel\n" << endl; }
				}
				else { cout << "do not have enough steel\n" << endl; }
			}
			else { cout << "already have a Sharp Spear\n" << endl; }
		}
		else { cout << "You must have a Blunt Spear first\n" << endl; }
		player->setCurrentState(player->getCraftingState());
		player->getCurrentState()->handle(player);
		break;
	}
	default:
		//clear screen
		system("CLS");
		cout << "please try again\n" << endl;
		player->getCurrentState()->handle(player);
		
	}
}