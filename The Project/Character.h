

#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include "CharacterHistory.h"
#include "Soul.h"

// TODO: expand class

class Character
{
private:
	std::string name;
	CharacterHistory history;
	Soul stats;

};

