

#pragma once
#include <stdint.h>

enum stat : uint8_t
{
	
	// TODO: add more stats

// PHYSICAL STATS

	// raw muscle power
	strength = 0,

	// ability to move and run fast and general coordination
	dexterity,

	// ability to exert one's body for prolonged periods
	endurance,

	// resistance to physical harm and ability 
	// to heal injuries
	toughness,

	// raw abillity to fight in a wild scuffle
	// affects ability to stun opponents and to get stunned
	brawling,

	// ability to fend off blows with a shield
	// item or barehanded
	defence,


	
// MENTAL STATS

	// predisposition of character to make enemies
	// focus his attention and attacks on him/her
	taunt,

	// eagerness of character to improve himself
	// and to strive for greatness
	ambition,

	// predisposition of character to follow orders
	// consistently train and keep his life organized
	discipline,

	// predisposition of character to put himself in danger
	// or act impulsively
	impulsivity,

	// ability to push the limits of body, mind and soul
	// and resist evil
	willpower,

	// ability to pull off extraordinary feats of strenght and skill
	tenacity,

// SKILL STATS

	// charecter's skill in escaping the enemy's attacks
	evasion,

	// character's skill in running and jumping
	athletics,

	// ability to use ranged weapons such as bows, crossbows and guns;
	marksmanship,

	// ability to use bladed melee weapons in combat
	// affects melee damage, parrying and dodging attacks
	swordsmanship,



	// dummy element used to get the count of the elements
	STAT_COUNT
};

struct Soul
{
public:


private:
	uint8_t currentState[STAT_COUNT];
	uint8_t potentialState[STAT_COUNT];
};

