#include "specialMove.h"
#include "moves.h"
#include <iostream>

specialMove::specialMove()
{
	moveName;
	moveType;
	moveDamage;
	specialAbility;
}
void specialMove::stun() 
{
	std::cout << "Confused";
}
void specialMove::setConfuseRay()
{
	moveName = "Confuse Ray";
	moveType = "Psychic";
	moveDamage = 0;
	specialAbility = "Confusion";
}

specialMove::~specialMove()
{
}
