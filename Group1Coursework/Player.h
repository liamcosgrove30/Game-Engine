/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include "PlayerState.h"
#include "ForestState.h"
#include "Wood.h"
#include "Stone.h"
#include "Steel.h"
#include "Inventory.h"
#include "Component.h"

class Player
{
private:
	//states
	PlayerState* current;
	PlayerState* craftingState;
	PlayerState* forestState;
	PlayerState* mineState;
	PlayerState* arenaState;
	PlayerState* inventoryState;
	Inventory* inventory;
public: 
	Player();
	
	//destructor
	virtual ~Player()
	{
		delete craftingState;
		delete forestState;
		delete mineState;
		delete arenaState;
		delete inventoryState;
		delete inventory;
	}

	//getting states
	void setCurrentState(PlayerState* state);
	PlayerState* getCurrentState();
	PlayerState* getCraftingState();
	PlayerState* getForestState();
	PlayerState* getMineState();
	PlayerState* getArenaState();
	PlayerState* getInventoryState();
	Inventory* getInventory();

};