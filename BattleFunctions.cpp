#include "BattleFunctions.h"         
#include "moves.h"
#include "pokemonObject.h"
#include <iostream>
#include <iomanip>
#include <string>
BattleFunctions::BattleFunctions() 
{
}
void BattleFunctions::setChoiceMove(int i,pokemonObject pObj)
{
	int bleh= pObj.getMove1Damage();
	switch (i)
	{
	case 1:
		choiceMove = pObj.getMove1();
		choiceMove.moveDamage = pObj.getMove1Damage();
		cout << pObj.pokeName << " uses " << choiceMove.moveName << "\n";
		break;

	case 2:
		choiceMove = pObj.getMove2();
		choiceMove.moveDamage = pObj.getMove2Damage();
		cout << pObj.pokeName << " uses " << choiceMove.moveName << "\n";
		break;
	case 3:
		choiceMove = pObj.getMove3();
		choiceMove.moveDamage = pObj.getMove3Damage();
		cout << pObj.pokeName << " uses " << choiceMove.moveName << "\n";
		break;

	}
}
int BattleFunctions::OpponentSmartAttack(pokemonObject oObj, pokemonObject pObj)
{
	moves osa1 = oObj.getMove1();
	moves osa2 = oObj.getMove2();
	moves osa3 = oObj.getMove3();
	moves osaArray[] = { osa1,osa2,osa3 };
	int osa1dam = typeAdjustment(osa1.moveType, pObj.getType(), oObj.getMove1Damage());
	int osa2dam = typeAdjustment(osa2.moveType, pObj.getType(), oObj.getMove2Damage());
	int osa3dam = typeAdjustment(osa3.moveType, pObj.getType(), oObj.getMove3Damage());
	int osaDamagebeforeAdjustment[] = { oObj.getMove1Damage(),oObj.getMove2Damage(),oObj.getMove3Damage() };
	int osaDamage[] = { osa1dam,osa2dam,osa3dam };
	int total = 0;
	int beforeTotal = 0;
	std::string name;
	for (int i = 0; i< sizeof(osaArray)/sizeof(osaArray[0]); i++) {
		if (total<osaDamage[i]) {
			total = osaDamage[i];
			beforeTotal = osaDamagebeforeAdjustment[i];
			name = osaArray[i].moveName;
		}
	}
	cout << oObj.pokeName << " uses " << name<<"\n";
	effectivenessMessage(beforeTotal, total);
	return total;
}
std::string BattleFunctions::getChoiceName()
{
	return choiceMove.moveName;
}
std::string BattleFunctions::getChoiceType()
{
	return choiceMove.moveType;
}
int BattleFunctions::getChoiceDamage()
{
	return choiceMove.moveDamage;
}
int BattleFunctions::typeAdjustment(string typeMove, string typeVictim, int num) {
	int result;
	if (typeMove == "Water" && (typeVictim == "Rock" || typeVictim == "Fire")) {
		result= num * 2;
	}
	else if (typeMove == "Electric" && (typeVictim == "Water" || typeVictim == "Flying"))
	{
		result = num * 2;
	}
	//Rock based moves super effective
	else if (typeMove == "Rock" && (typeVictim == "Fire" || typeVictim == "Flying")) {
		result = num * 2;
	}
	//Fire based moves super effective
	else if (typeMove == "Fire" && (typeVictim == "Grass" || typeVictim == "Ice")) {
		result = num * 2;
	}
	//Grass based moves super effective
	else if (typeMove == "Grass" && (typeVictim == "Water" || typeVictim == "Rock")) {
		result = num * 2;
	}
	//Flying based moves super effective
	else if (typeMove == "Flying" && typeVictim == "Grass") {
		result = num * 2;
	}
	//Ice absed moved super effective
	else if (typeMove == "Ice" && (typeVictim == "Grass"&&typeVictim == "Flying")) {
		result = num * 2;
	}
	//Weak against Fire pokemon
	else if (typeMove == "Grass" && typeVictim == "Fire") {
		result = num / 2;
	}
	//Weak against Water pokemon
	else if ((typeMove == "Rock" || typeMove == "Fire") && typeVictim == "Water") {
		result = num / 2;
	}
	//Weak against Grass pokemon
	else if ((typeMove == "Rock" || typeMove == "Water") && typeVictim == "Grass") {
		result = num / 2;
	}
	//Weak against Rock pokemon
	else if ((typeMove == "Fire" || typeMove == "Flying") && typeVictim == "Rock") {
		result = num / 2;
	}
	//Weak against Flying pokemon
	else if (typeMove == "Grass"&&typeVictim == "Flying") {
		result = num / 2;
	}
	else if (typeMove == "Grass"&&typeVictim == "Ice") {
		result = num / 2;
	}
	else {
		result = num;
	}
	/*if (result > num)
	{
		std::cout << "It's super effective!\n";
	}
	else if (result < num)
	{
		std::cout << "It's not very effective...\n";
	}*/
	return result;
}
void BattleFunctions::effectivenessMessage(int before, int after)
{
	if (after>before)
	{
	std::cout << "It's super effective!\n";
	}
	else if (after<before)
	{
	std::cout << "It's not very effective...\n";
	}
}