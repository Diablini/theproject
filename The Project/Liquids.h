
#pragma

enum LiquidType : char
{
	BLOOD,
	WATER,
	TEARS,
	VOMIT,
	SPINALFLUID,
	SWEAT,
};

// used as a holder for body fluids
class FluidContent
{
	void fill(size_t amount);
	size_t leak(size_t amount);

	LiquidType type() const;

private:
	LiquidType Liquidtype;
	// in mililiters
	size_t amount;
};