

#include "Integer.h"
#include <stdint.h>

unsigned char highestOneBit(size_t a)
{
	if (!a) return 0;
	uint8_t count = 0;
	while(a != 0)
	{
		++count;
		a >>= 1;
	}
	return count;
}

bool addition_safe(size_t a, size_t b)
{
	return (highestOneBit(a) < 32) && (highestOneBit(b) < 32);
}

