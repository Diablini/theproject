

#include "Biitmask.h"

using namespace bit;

Bitfield::Bitfield()
{
	storage = DEFAULT_VALUE;
}

inline bool Bitfield::operator[](uint8_t mask)
{
	return storage & mask;
}

inline bool Bitfield::operator[](bit_pos pos)
{ 
	return storage & pos;
}

