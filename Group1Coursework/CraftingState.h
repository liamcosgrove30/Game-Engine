/*
Name:
Student ID: B00317267
I declare that the following code was produced by Craig McCorrisken & Liam Cosgrove as a group assignment for the GED module and that this is our own work.
I am aware of the penalties incurred by submitting in full or in part work that is not our own and that was developed by third parties that are not appropriately acknowledged.
*/

#pragma once
#include "Player.h"
#include "PlayerState.h"
#include "Axe.h"
#include "Pickaxe.h"
#include "WoodenQuality.h"
#include "StoneQuality.h"
#include "SteelQuality.h"
#include "Sword.h"
#include "Spear.h"
#include "Rusty.h"
#include "Blunt.h"
#include "Sharp.h"

class CraftingState :public PlayerState
{
private:
	//check for item being made already
	bool hasWoodAxe = false;
	bool hasStoneAxe = false;
	bool hasSteelAxe = false;
	bool hasWoodPickaxe = false;
	bool hasStonePickaxe = false;
	bool hasSteelPickaxe = false;
	bool isRustySword = false;
	bool isBluntSword = false;
	bool isSharpSword = false;
	bool isRustySpear = false;
	bool isBluntSpear = false;
	bool isSharpSpear = false;

public:
	CraftingState();
	virtual ~CraftingState() {}

	//handler for player
	void handle(Player* player);
};