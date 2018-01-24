#pragma once
#ifndef FILEPROGRESS_H
#define FILEPROGRESS_H
#include "PokemonObject.h"
class FileProgress
{
public:
	FileProgress();
	bool CreateFileToSaveProgress(std::string fileName, pokemonObject pObj, pokemonObject pObj2, pokemonObject oObj, pokemonObject oObj2);
	std::string PrintFileContent(std::string fileName, std::string wordSearch, std::string pokeName);
};

#endif