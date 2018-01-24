#include "Util.h"
#include <iostream>
#include <string>

Util::Util()
{
}
void Util::EnterCorrectKey(std::string message, std::vector<std::string> values, std::string& output)
{
	bool enteredCorrectKey = false;
	while (!enteredCorrectKey)
	{
		std::cout << message;
		std::cin >> output;
		try
		{
			bool foo = false;
			for (int i = 0; i < values.size(); i++)
			{
				if (output == values[i])
				{
					foo = true;
				}
			}
			if (!foo) 
			{
				throw 1;
			}
			enteredCorrectKey = true;
		}
		catch (int x)
		{
			std::cout << "Err: " << x << " Invalid key.\n";
		}
	}
}
std::vector<std::string> Util::numberList(int number) 
{
	std::vector<std::string> pokeList;
	for (int i = 0; i < number; i++)
	{
		pokeList.push_back( std::to_string(i+1));
	}
	return pokeList;
}
void Util::PrintStatsOfPokemon(pokemonObject pokeObj)
{
	std::cout << "Name: " << pokeObj.pokeName << "\n";
	std::cout << "Hp: " << pokeObj.getHP() << "\n";
	std::cout << "Move\t\t\t\tType\t\tPP\n";
	std::cout << pokeObj.getMove1Name() << "\t\t\t" << pokeObj.move1type << "\t\t" << pokeObj.getMove1Damage() << "\n";
	std::cout << pokeObj.getMove2Name() << "\t\t\t" << pokeObj.move2type << "\t\t" << pokeObj.getMove2Damage() << "\n";
	std::cout << pokeObj.getMove3Name() << "\t\t\t" << pokeObj.move3type << "\t\t" << pokeObj.getMove3Damage() << "\n";
}
Util::~Util()
{
}
