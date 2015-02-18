

#pragma once
#include <stdint.h>

enum stat : uint8_t
{
	// These are the 6 primary stats
	strength = 0,
	dexterity,
	endurance,
	intelligence,
	wisdom,
	charisma,

	// TODO: add more stats
	// here

	// dummy element used to get the count of the elements
	STAT_COUNT
};

struct StatTable
{
public:


private:
	uint8_t data[STAT_COUNT];
};

