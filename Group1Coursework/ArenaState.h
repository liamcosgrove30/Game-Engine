/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include "Player.h"
#include "PlayerState.h"

class ArenaState :public PlayerState
{
public:
	ArenaState();
	virtual ~ArenaState() {}

	//handler for player
	void handle(Player* player);
};