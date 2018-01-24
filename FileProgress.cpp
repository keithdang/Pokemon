#include <iostream>
#include "fileProgress.h"
#include <fstream>
#include <string>
#include "PokemonObject.h"
using namespace std;
FileProgress::FileProgress()
{
}
bool FileProgress::CreateFileToSaveProgress(std::string fileName, pokemonObject pObj, pokemonObject pObj2, pokemonObject oObj, pokemonObject oObj2)
{
	ofstream myfile;
	myfile.open(fileName);
	pokemonObject arr[4] = { pObj , pObj2 , oObj, oObj2 };
	for (int i = 0; i < 4; i++)
	{
		//int pokemon = 2;
		if (i < 2)
		{
			myfile << "Player 1 Information.\n";
			myfile << "Pokemon " << i + 1 << " name:\t" << arr[i].pokeName << "\t";
			myfile << "Pokemon " << i + 1 << " hp:\t" << arr[i].getHP() << "\n";
			myfile << "Pokemon " << i + 1 << " #:\t" << arr[i].getPokemonNumber() << "\n";
			myfile << "Pokemon " << i + 1 << " level:\t" << arr[i].getLevel() << "\n";
		}
	}

	myfile << pObj.pokeName;
	myfile.close();
	return true;
}
std::string FileProgress::PrintFileContent(std::string fileName, std::string wordSearch, std::string pokeName) {
	std::string line;
	std::string wordFound;
	std::size_t found;
	std::size_t foundName;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			foundName = line.find(pokeName);
			if (foundName != std::string::npos)
			{
				found = line.find(wordSearch);
				if (found != std::string::npos)
				{
					wordFound = line.substr(found + wordSearch.length() + 1);
				}
			}
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file";
	}
	return wordFound;
}

