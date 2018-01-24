#include "pokemonObject.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "moves.h"
pokemonObject::pokemonObject(std::string name,  int pokeNum, std::string ptype, int lvl, int hp, moves mov1, moves mov2, moves mov3)
{

	pokeName = name;
	level = lvl;
	healthPoints = hp;
	defaultHealth = hp;
	pokemonNumber = pokeNum;
	pokeType = ptype;

	move1 = mov1;
	move2 = mov2;
	move3 = mov3;
	move1name = mov1.moveName;
	move1type = mov1.moveType;
	move1damage = mov1.moveDamage;
	move2name = mov2.moveName;
	move2type = mov2.moveType;
	move2damage = mov2.moveDamage;
	move3name = mov3.moveName;
	move3type = mov3.moveType;
	move3damage = mov3.moveDamage;

	originalHP = hp;
	originalAtt1 = mov1.moveDamage;
	originalAtt2 = mov2.moveDamage;
	originalAtt3 = mov3.moveDamage;
}
void pokemonObject::print()
{
	std::cout << pokeName << " appeared!\n";
}

void pokemonObject::printHP()
{
	std::cout << pokeName << "'s hp: " << getHP() << "/" << getDHP() << "\n";
}
int pokemonObject::getPokemonNumber()
{
	return pokemonNumber;
}
std::string pokemonObject::getType()
{
	return pokeType;
}
int pokemonObject::getLevel()
{
	return level;
}
void pokemonObject::setLevel(int lvl)
{
	level = lvl;
}
int pokemonObject::getHP()
{
	return healthPoints;
}
void pokemonObject::setHP(int hp)
{
	healthPoints = hp;
}
int pokemonObject::getDHP()
{
	return defaultHealth;
}
void pokemonObject::setDHP(int hp)
{
	defaultHealth = hp;
}
void pokemonObject::useMove1()
{
	std::cout << pokeName << " used " << move1name << "\n";
}
moves pokemonObject::getMove1()
{
	return move1;
}
int pokemonObject::getMove1Damage()
{
	return move1damage;
}
void pokemonObject::setMove1Damage(int d)
{
	move1damage = d;
}
std::string pokemonObject::getMove1Name()
{
	return move1name;
}
moves pokemonObject::getMove2()
{
	return move2;
}
int pokemonObject::getMove2Damage()
{
	return move2damage;
}
void pokemonObject::setMove2Damage(int d)
{
	move2damage = d;
}
std::string pokemonObject::getMove2Name()
{
	return move2name;
}
moves pokemonObject::getMove3()
{
	return move3;
}
int pokemonObject::getMove3Damage()
{
	return move3damage;
}
void pokemonObject::setMove3Damage(int d)
{
	move3damage = d;
}
std::string pokemonObject::getMove3Name()
{
	return move3name;
}
void pokemonObject::setAttributesWithLevel(int lvl)
{
	double adjust = sqrt(double(lvl));
	setHP(getHP()*adjust);
	setDHP(getDHP()*adjust);
	setMove1Damage(getMove1Damage()*adjust);
	setMove2Damage(getMove2Damage()*adjust);
	setMove3Damage(getMove3Damage()*adjust);
}
void pokemonObject::setOriginalStats(int currentHp,int lvl)
{
	int newHp = currentHp/((int)(sqrt(double(lvl))));
    setHP(newHp);
	setDHP(originalHP);
	setMove1Damage(originalAtt1);
	setMove2Damage(originalAtt2);
	setMove3Damage(originalAtt3);
}
