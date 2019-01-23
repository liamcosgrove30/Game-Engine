/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#include "Player.h"
#include "CraftingState.h"
#include "ForestState.h"
#include "ArenaState.h"
#include "MineState.h"
#include "InventoryState.h"
#include <iostream>

using namespace std;



Player::Player()
{
	craftingState = new CraftingState();
	forestState = new ForestState();
	mineState = new MineState();
	arenaState = new ArenaState();
	inventoryState = new InventoryState();
	inventory = new Inventory();
	current = craftingState;
	current->handle(this);
}

void Player::setCurrentState(PlayerState * state)
{
	current = state;
}

PlayerState * Player::getArenaState()
{
	return arenaState;
	system("pause");
}

PlayerState * Player::getCraftingState()
{
	return craftingState;
	system("pause");
}

PlayerState * Player::getCurrentState()
{
	return current;
}

PlayerState * Player::getForestState()
{
	return forestState;
	system("pause");
}

PlayerState * Player::getInventoryState()
{
	return inventoryState;
	system("pause");
}

PlayerState * Player::getMineState()
{
	return mineState;
	system("pause");
}

Inventory* Player::getInventory()
{
	return inventory;
}
