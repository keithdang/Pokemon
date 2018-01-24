#pragma once
#include <vector>
#include <string.h>
#include "PokemonObject.h"
class Util
{
public:
	static Util& GetInstance()
	{
		static Util instance;
		return instance;
	}
	Util();
	std::vector<std::string> numberList(int number);
	void EnterCorrectKey(std::string message, std::vector<std::string> values,std::string& output);
	void PrintStatsOfPokemon(pokemonObject pokeObj);
	~Util();
};

