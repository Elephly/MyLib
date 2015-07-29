#include "MyRandomizer.h"

namespace MyLib
{
	MyRandomizer::MyRandomizer(int upper, int lower) : max(upper), min(lower) { }

	inline MyRandomizer::~MyRandomizer() { }

	int MyRandomizer::next()
	{
		return rand() % (max - (min - 1)) + min;
	}

	MyDice::MyDice(unsigned int nSides) : MyRandomizer(nSides, 1) { }

	MyDice::~MyDice() { }

	int MyDice::roll()
	{
		return next();
	}

	MyCoin::MyCoin() : MyRandomizer(2, 1) { }

	MyCoin::~MyCoin() { }

	CoinFace MyCoin::flip()
	{
		return (CoinFace)next();
	}
}