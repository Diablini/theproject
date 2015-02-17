

#include "Liquids.h"

void FluidContent::fill(size_t amount) 
{
	// TODO: check for overflow
	this->amount += amount;
}

size_t FluidContent::leak(size_t amount)
{
	if (this->amount < amount)
	{
		size_t temp = this->amount;
		this->amount = 0;
		return temp;
	}
	this->amount -= amount;
	return amount;
}

LiquidType FluidContent::type() const {return Liquidtype;}
