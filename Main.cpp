#include "PokemonObject.h"
#include <string>
#include <stdlib.h>
#include <iostream>
#include "moves.h"
#include "FileProgress.h"
#include <cstdlib>
#include "BattleFunctions.h"
#include "Factory.h"
#include <locale>
#include "Util.h"
using namespace std;
int main()
{
	std::string fileName = "pokemon.txt";
	std::string toPlay;
	FileProgress fileObj;

	pokemonObject* pp1;
	pokemonObject* pp2;
	pokemonObject* op1;
	pokemonObject* op2;
	
	int choosePokemon;
	int choosePokemon2;
	int count = 1;
	srand((unsigned)time(0));
	int num = rand() % 5 + 1;
	int num2 = rand() % 5 + 1;
	pokemonObject facto1 = Factory::GetInstance().CreatePokemon(Factory::GetInstance().RandNumToPokeNum(num));
	op1 = &facto1;
	pokemonObject facto2 = Factory::GetInstance().CreatePokemon(Factory::GetInstance().RandNumToPokeNum(num2));
	op2 = &facto2;
	std::cout << "Opponent has " << op1->pokeName << " and " << op2->pokeName << ".\n";
	std::string p1SavedNumber, p2SavedNumber;
	std::string playFromLastSavedGameMsg = "Play from last saved game? y/n \n";
	std::vector<std::string> yesNoValues = { "y","n" };
	Util::GetInstance().EnterCorrectKey(playFromLastSavedGameMsg, yesNoValues,toPlay);
	std::vector<int> playerTeam = { 0,0 };
	if (toPlay == "y")
	{
		choosePokemon = atoi(fileObj.PrintFileContent(fileName, "#:", "Pokemon 1").c_str());
		choosePokemon2 = atoi(fileObj.PrintFileContent(fileName, "#:", "Pokemon 2").c_str());
	}
	else if(toPlay == "n")
	{
		Factory::GetInstance().printPokemonList();
		Factory::GetInstance().checkPokeStatisticsOrCont();
		std::string pokemonSelection= "Enter Pokemon you want\n";
		std::vector<std::string> choiceSelection= Util::GetInstance().numberList(Factory::GetInstance().pokemonNumber.size());
		std::string strChoosePokemon;
		Util::GetInstance().EnterCorrectKey(pokemonSelection, choiceSelection, strChoosePokemon);
		choosePokemon = atoi(strChoosePokemon.c_str());
		choosePokemon = Factory::GetInstance().ChoiceNumToPokeNum(choosePokemon);
		Util::GetInstance().EnterCorrectKey(pokemonSelection, choiceSelection, strChoosePokemon);
		choosePokemon2 = atoi(strChoosePokemon.c_str());
		choosePokemon2 = Factory::GetInstance().ChoiceNumToPokeNum(choosePokemon2);
	}
	pokemonObject factp1 = Factory::GetInstance().CreatePokemon(choosePokemon);
	pp1 = &factp1;
	pokemonObject factp2 = Factory::GetInstance().CreatePokemon(choosePokemon2);
	pp2 = &factp2;

	if (toPlay == "y")
	{
		int p1LevelFromSaved = atoi(fileObj.PrintFileContent(fileName, "level:", "Pokemon 1").c_str());
		pp1->setLevel(p1LevelFromSaved);
		int p2LevelFromSaved = atoi(fileObj.PrintFileContent(fileName, "level:", "Pokemon 2").c_str());
		pp2->setLevel(p2LevelFromSaved);
	}

	pp1->setAttributesWithLevel(pp1->getLevel());
	pp2->setAttributesWithLevel(pp2->getLevel());
	op1->setAttributesWithLevel(op1->getLevel());
	op2->setAttributesWithLevel(op2->getLevel());

	std::cout << "You're team:\t" << pp1->pokeName << " lvl: " << pp1->getLevel() << "\t" << pp2->pokeName << " lvl: " << pp2->getLevel() << "\n";

	pokemonObject* playerPokemon;
	pokemonObject* opponentPokemon;
	playerPokemon = pp1;
	opponentPokemon = op1;
	//Setting up battle
	int opponentLives = 2;
	int playerLives = 2;
	int damage;
	std::string battle;
	std::string battleMsg= "Battle? y/n ";
	Util::GetInstance().EnterCorrectKey(battleMsg, yesNoValues, battle);
	while (battle=="y")
	{
		playerPokemon->printHP();
		opponentPokemon->printHP();
		while ((playerPokemon->getHP()>0) && (opponentPokemon->getHP()>0) && (opponentLives>0))
		{
			std::string moveSelection="Select Move 1)" + playerPokemon->move1name + "\t2)" + playerPokemon->move2name + "\t3)" + playerPokemon->move3name + "\n";
			int choice;
			std::vector<std::string> choiceMoves = { "1","2","3"};
			std::string strChoice;
			Util::GetInstance().EnterCorrectKey(moveSelection,choiceMoves,strChoice);
			choice = atoi(strChoice.c_str());
			BattleFunctions::GetInstance().setChoiceMove(choice, *playerPokemon);
			damage = BattleFunctions::GetInstance().typeAdjustment(BattleFunctions::GetInstance().getChoiceType(),opponentPokemon->getType(), BattleFunctions::GetInstance().getChoiceDamage());
			BattleFunctions::GetInstance().effectivenessMessage(BattleFunctions::GetInstance().getChoiceDamage(), damage);
			opponentPokemon->setHP(opponentPokemon->getHP() - damage);
			
			if (opponentPokemon->getHP() <= 0)
			{
				opponentLives--;
				opponentPokemon->setHP(0);
				opponentPokemon->printHP();
				cout << opponentPokemon->pokeName << " fainted.\n";
				playerPokemon->setLevel(playerPokemon->getLevel() + 1);
				cout << playerPokemon->pokeName << " leveled up to " << playerPokemon->getLevel() <<"\n";
				playerPokemon->setOriginalStats(playerPokemon->getHP(),playerPokemon->getLevel());
				playerPokemon->setAttributesWithLevel(playerPokemon->getLevel());
				if (opponentLives > 0)
				{
					opponentPokemon = op2;
					cout << opponentPokemon->pokeName << " entered the battle.\n";
				}
				break;
			}
			else 
			{
				opponentPokemon->printHP();
			}
			int opponentChoice = BattleFunctions::GetInstance().OpponentSmartAttack(*opponentPokemon, *playerPokemon);
			playerPokemon->setHP(playerPokemon->getHP() - opponentChoice);
			if (playerPokemon->getHP() <= 0)
			{
				playerLives--;
				playerPokemon->setHP(0);
				playerPokemon->printHP();
				cout << playerPokemon->pokeName << " fainted.\n";
				if (playerLives > 0)
				{
					playerPokemon = pp2;
					cout << playerPokemon->pokeName << " entered the battle.\n";
				}
			}
			else
			{
				playerPokemon->printHP();
			}
		}
		if (opponentLives == 0 || playerLives == 0)
		{
			cout << "Game Over\n";
			if (opponentLives == 0)
			{
				cout << "You win!\n";
			}
			break;
		}
		else
		{
			std::string continueMsg = "Continue? y/n: ";
			Util::GetInstance().EnterCorrectKey(battleMsg, yesNoValues, battle);
		}
	}
	fileObj.CreateFileToSaveProgress(fileName, *pp1, *pp2, *op1, *op2);
	std::cin.get();
	std::cin.get();
}