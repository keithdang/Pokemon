#include "moves.h"
#include <iostream>
#include <string>

moves::moves()
{
	moveName;
	moveType;
	moveDamage;
}
void moves::setFireSpin()
{
	moveName = "Fire Spin";
	moveType = "Fire";
	moveDamage = 4;
}

void moves::setFlamethrower()
{
	moveName = "Flamethrower";
	moveType = "Fire";
	moveDamage = 10;
}

void moves::setBubbleBeam()
{
	moveName = "Bubble Beam";
	moveType = "Water";
	moveDamage = 6;
}

void moves::setQuickAttack()
{
	moveName = "Quick Attack";
	moveType = "Normal";
	moveDamage = 6;
}
void moves::setHyperBeam()
{
	moveName = "Hyper Beam";
	moveType = "Normal";
	moveDamage = 15;
}
void moves::setThunderPunch()
{
	moveName = "Thunder Punch";
	moveType = "Electric";
	moveDamage = 6;
}
void moves::setRazorLeaf()
{
	moveName = "Razor Leaf";
	moveType = "Grass";
	moveDamage = 8;
}
void moves::setScratch()
{
	moveName = "Scratch";
	moveType = "Normal";
	moveDamage = 6;
}
void moves::setVineWhip()
{
	moveName = "Vine Whip";
	moveType = "Grass";
	moveDamage = 6;
}
void moves::setSolarBeam()
{
	moveName = "Solar Beam";
	moveType = "Grass";
	moveDamage = 15;
}
void moves::setRockThrow()
{
	moveName = "Rock Throw";
	moveType = "Rock";
	moveDamage = 8;
}
void moves::setStoneEdge()
{
	moveName = "Stone Edge";
	moveType = "Rock";
	moveDamage = 15;
}
void moves::setThunder()
{
	moveName = "Thunder";
	moveType = "Electric";
	moveDamage = 15;
}
void moves::setHydropump()
{
	moveName = "HydroPump";
	moveType = "Water";
	moveDamage = 15;
}