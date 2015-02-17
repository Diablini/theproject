
#pragma once

#include <string>
#include <list>
#include <fstream>
#include <vector>
#include "Wound.h"

using std::vector;
using std::list;

enum TissueType : char
{
	HAIR = 0,
	SKIN,
	FAT,
	MUSCLE,
	ARTERY,
	BONE,
	JOINT,
	ORGAN
};

// used for class below - read below
enum ExtentOfCover : char
{
	// tissue is an entire layer completely covering target tissue
	// example - skin around entire body
	COMPLETE = 0,
	// tissue is wrapped around target but can be bypassed
	// example - ribs wrap around the heart
	// some muscles almost completely surround a bone
	WRAP,
	// tissue is adjacent to target tissue but only covers a portion
	// example - muscles adjacent to bone on one side
	PARTIAL,
	// tissue is some distance away from target
	// example - heart - stomach
	// this usually shouldn't get used but is included just in case
	NONE,
};



// this is used to specify which tissue covers which
// and how much
struct CoverRelation
{
	ExtentOfCover cover;
	Tissue * over;
	Tissue * under;
	bool equal;
};

struct BodyConnection
{
	// tissues of the superior limb which connect to
	// the lesser and can be damaged when connection is severed
	std::list<Tissue *> superiorConnected;
	// tissue of lesser limb that connect to superior
	std::list<Tissue *> lesserConnected;
	// connecting joint if available
	Tissue * joint;
};


// TODO: expand
struct Organ
{
	std::string name;
	
};

struct Tissue
{
	TissueType type;

	// TODO: specify some kind of unit for these
	size_t mass;
	size_t volume;
	size_t blood;
	size_t bloodCapacity;
	std::vector<TissueWound> wounds;
	CoverRelation coveredTissueRelation;
};

struct BodyPart
{
	std::string name;

	std::vector<Tissue> tissues;
	
	/*We have two types of connected body parts
	Superior - If this body part is severed the first type
	will also be severed from the body - that is
	it's dependant on this body part for support

	The second type of part - lesser, is independent from this one
	which means that if this part is severed the rest
	will remain part of the actual body*/

	std::list<BodyConnection *> super;
	std::list<BodyConnection *> lesser;
};

class Body
{


};