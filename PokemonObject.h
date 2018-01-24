#pragma once
#ifndef POKEMONOBJECT_H
#define POKEMONOBJECT_H
#include <string>
#include "moves.h"
#include <vector>
class pokemonObject : public moves
{
private:

public:
	pokemonObject(std::string pokename,int pokeNUm,std::string ptype, int lvl, int hp, moves mov1, moves mov2,moves mov3);
	int healthPoints;
	int defaultHealth;
	int pokemonNumber;
	double level;
	std::string pokeName;
	std::string pokeType;
	moves move1;
	moves move2;
	moves move3;
	std::string move1name;
	std::string move1type;
	int move1damage;
	std::string move2name;
	std::string move2type;
	int move2damage;
	std::string move3name;
	std::string move3type;
	int move3damage;

	void print();
	void printHP();
	int getHP();
	void setHP(int hp);
	int getDHP();
	void setDHP(int dhp);
	std::string getType();
	void setLevel(int lvl);
	int getLevel();
	int getPokemonNumber();
	
	moves getMove1();
	int getMove1Damage();
	void setMove1Damage (int d);
	std::string getMove1Name();
	void useMove1();
	moves getMove2();
	int getMove2Damage();
	void setMove2Damage(int d);
	std::string getMove2Name();
	moves getMove3();
	int getMove3Damage();
	void setMove3Damage(int d);
	std::string getMove3Name();

	void setAttributesWithLevel(int lvl);
	void setOriginalStats(int currentHp,int lvl);
	int originalHP;
	int originalAtt1;
	int originalAtt2;
	int originalAtt3;
};

#endif // POKEMONOBJECT_H