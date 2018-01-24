#pragma once
#include "PokemonObject.h"
#include <vector>
class Factory
{
public:
	static Factory& GetInstance()
	{
		static Factory instance;
		return instance;
	}
	Factory();
	int ChoiceNumToPokeNum(int choice);
	int RandNumToPokeNum(int choice);
	pokemonObject CreatePokemon(int choose);
	void checkPokeStatisticsOrCont();
	void printPokemonList();
	std::vector<int> pokemonNumber = {1,3,4,95,125,130,159,217};
	~Factory();
};

