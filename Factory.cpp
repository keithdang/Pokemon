#include "Factory.h"
#include "PokemonObject.h"
#include "moves.h"
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <map>
#include "specialMove.h"
#include <iostream>
#include "Util.h"
Factory::Factory()
{
}
int Factory::ChoiceNumToPokeNum(int choice)
{
	choice = pokemonNumber[choice-1];
	return choice;
}
int Factory::RandNumToPokeNum(int choice)
{
	choice = pokemonNumber[choice-1];
	return choice;
}
void Factory::checkPokeStatisticsOrCont()
{
	std::string msg = "Check stats or skip and pick: c/s\n";
	std::vector<std::string>letters = { "c","s" };
	std::string answer;
	Util::GetInstance().EnterCorrectKey(msg, letters, answer);
	if (answer == "c")
	{
		std::string choice = "Which pokemon do you want to check out? (From numbers up above)\n";
		std::vector<std::string> choiceSelection = Util::GetInstance().numberList(pokemonNumber.size());
		std::string ans;
		Util::GetInstance().EnterCorrectKey(choice, choiceSelection, ans);
		int pokeSelect = atoi(ans.c_str());
		pokeSelect = ChoiceNumToPokeNum(pokeSelect);
		pokemonObject pokeObj = CreatePokemon(pokeSelect);
		Util::GetInstance().PrintStatsOfPokemon(pokeObj);
		checkPokeStatisticsOrCont();
	}
}
void Factory::printPokemonList()
{
	std::cout << "1 : Bulbsaur\n2 : Venasaur\n3 : Charmander\n4 : Onyx\n5 : Electabuzz\n6 : Garydos\n7 : Croconaw\n8 : Ursaring\n";
}
pokemonObject Factory::CreatePokemon(int choose) 
{
	//specialMove confuseRay;
	//confuseRay.setConfuseRay;
	moves razonLeaf, firespin, flamethrower, bubblebeam, quickAttack, hyperbeam, thunderpunch, scratch, hydropump, thunder,
		rockThrow, stoneEdge, solarBeam, vineWhip;
	rockThrow.setRockThrow();
	solarBeam.setSolarBeam();
	vineWhip.setVineWhip();
	stoneEdge.setStoneEdge();
	razonLeaf.setRazorLeaf();
	firespin.setFireSpin();
	flamethrower.setFlamethrower();
	bubblebeam.setBubbleBeam();
	quickAttack.setQuickAttack();
	hyperbeam.setHyperBeam();
	thunderpunch.setThunderPunch();
	scratch.setScratch();
	hydropump.setHydropump();
	thunder.setThunder();
	switch (choose)
	{
		case 1:
		{
			pokemonObject bulbasaur("Bulbasaur", 1, "Grass",5,20,razonLeaf,quickAttack,vineWhip);
			return bulbasaur;
		}
		case 3:
		{
			pokemonObject venasaur("Venasaur", 3, "Grass", 5, 20, razonLeaf, solarBeam, hyperbeam);
			return venasaur;
		}
		case 4:
		{
			pokemonObject charmander("Charmander", 4,"Fire", 5, 20, flamethrower, firespin, scratch);
			return charmander;
		}
		case 95:
		{
			pokemonObject onyx("Onyx", 95, "Rock", 5, 20, rockThrow, stoneEdge, hyperbeam);
			return onyx;
		}
		case 125:
		{
			pokemonObject electabuzz("Electabuzz", 125,"Electric", 5, 20, thunderpunch, hyperbeam, thunder);
			return electabuzz;
		}
		case 130:
		{
			pokemonObject gyarados("Gyarados",130,"Water", 5, 20, hydropump, bubblebeam, hyperbeam);
			return gyarados;
		}
		case 159:
		{
			pokemonObject croconaw("Croconaw",159,"Water", 5, 20, bubblebeam, hydropump, quickAttack);
			return croconaw;
		}
		case 217:
		{
			pokemonObject ursaring("Ursaring", 217,"Normal", 5, 20, quickAttack, hyperbeam, scratch);
			return ursaring;
		}
	}
	pokemonObject pokemon("Pikachu", 25,"Electric", 5, 10, thunder, thunderpunch, scratch);
	return pokemon;
}

Factory::~Factory()
{
}
