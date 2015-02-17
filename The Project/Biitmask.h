
#pragma once
#include <stdint.h>

namespace bit
{
// define first four and second four bitmasks
#define FIRST_HALF 31;
#define SECOND_HALF   

#define DEFAULT_VALUE 0;

	// enumerate bit access masks
	enum bit_pos
	{
		bit_one = 1,
		bit_two = 2,
		bit_three = 4,
		bit_four = 8,
		bit_five = 16,
		bit_six = 32,
		bit_seven = 64,
		bit_eight = 128,
	};

	struct Bitfield
	{
		// init with default value
		Bitfield();
		// init with value
		Bitfield(uint8_t val);

		// get direct bit mask access
		bool operator[](uint8_t pos);
		// get bit at pos
		bool operator[](bit_pos pos);
		// set bit at position to value
		Bitfield& set(uint8_t pos, bool val);

	private:
		void operator++() {};
		void operator++(int) {};
		void operator--() {};
		void operator--(int) {};

		uint8_t storage;
	};





}