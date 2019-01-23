/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "ArenaState.h"
#include "Player.h"
#include <iostream>

using namespace std;

ArenaState::ArenaState()
{}

void ArenaState::handle(Player* player)
{
	//formatting
	cout << "CURRENT AREA: ARENA \n" << "---------------------------------\n" << " press 0 to go to Crafting \n press 1 to go to Mine \n press 2 to go to Forest \n press 3 to go to your Inventory." << endl;
	cout << "\n press 4 to fight" << endl;
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
		//mining area
		//clear screen
		system("CLS");
		player->setCurrentState(player->getMineState());
		player->getCurrentState()->handle(player);
		break;
	case 2:
		//forest area
		//clear screen
		system("CLS");
		player->setCurrentState(player->getForestState());
		player->getCurrentState()->handle(player);
		break;
	case 3:
		//inventory
		//clear screen
		system("CLS");
		player->setCurrentState(player->getInventoryState());
		player->getCurrentState()->handle(player);
		break;
	case 4: 
	{

		system("CLS");
		string playerWeapon = "";
		int playerDMG = 0;
		//assigning oppoent damage
		int opponentDMG = rand() % 50;
		int option;

		cout << "CHOSE YOUR WEAPON:" << endl;
		cout << "\nPress 1 for " << player->getInventory()->getCurrSwordName() << " \nPress 2 for " << player->getInventory()->getCurrSpearName() << endl;
		cin >> option;

		//player chosing weapon of choice
			switch (option)
			{
				case 1:
				{
					system("CLS");

					//getting weapons attack damage
					playerDMG = player->getInventory()->getCurrSwordDmg();

					//finding weapon name
					playerWeapon = player->getInventory()->getCurrSwordName();
					break;
				}
				case 2:
				{
					system("CLS");

					//getting weapons attack damage
					playerDMG = player->getInventory()->getCurrSpearDmg();
					
					//finding weapon name
					playerWeapon = player->getInventory()->getCurrSpearName();
					break;
				}
				default:
					system("CLS");
					cout << "please chose a valid option \n" << endl;
			}

		if (option <= 2 && option > 0)
		{
			//displaying weapon details
			cout << "player has chosen " << playerWeapon << ": " << playerDMG << endl;

			//displaying the Opponent's attack damage
			cout << "Opponent sword does " << opponentDMG << endl;

			//finding out battle winner
			if (playerDMG >= opponentDMG) {
				cout << "CONGRATULATIONS YOU WIN!!!" << endl;
				cout << "\n Press 0 to quit" << endl;
				cout << "\n Press 1 to go back to the Arena" << endl;

				//checking if player quits game
				cin >> option;
				if (option == 0)
					exit(0);
				if (option == 1)
					system("CLS");
			}
			else { cout << "you have been beaten... return with a better weapon and try again \n" << endl; }
		}

		//player->setCurrentState(player->getArenaState());
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