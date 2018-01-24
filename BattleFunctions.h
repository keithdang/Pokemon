#pragma once
#ifndef BATTLEFUNCTION_H
#define BATTLEFUNCTION_H
#include "moves.h"
#include "PokemonObject.h"
using namespace std;
class BattleFunctions : public moves
{
public:
	
	static BattleFunctions& GetInstance()
	{
		static BattleFunctions instance;
		return instance;
	}
	
	std::string choiceName;
	std::string choiceType;
	int choiceDamage;
	BattleFunctions();
	void setChoiceMove(int i,pokemonObject pObj);
	moves choiceMove;
	int OpponentSmartAttack(pokemonObject oObj,pokemonObject pObj);

	std::string getChoiceName();
	std::string getChoiceType();
	int getChoiceDamage();
	int typeAdjustment(string typeMove, string typeVictim, int num);
	void effectivenessMessage(int before, int after);
};
#endif
