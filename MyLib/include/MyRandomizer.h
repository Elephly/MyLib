#ifndef MYRANDOMIZER_H
#define MYRANDOMIZER_H

#include "shared.h"

namespace MyLib
{
	class MyRandomizer
	{
	public:
		MyRandomizer(int upper, int lower = 0);
		virtual ~MyRandomizer() = 0;

	protected:
		int next();

	private:
		int max;
		int min;
	};

	class MyDice : MyRandomizer
	{
	public:
		MyDice(unsigned int nSides);
		virtual ~MyDice();

		int roll();
	};

	enum CoinFace
	{
		HEADS,
		TAILS,
	};

	class MyCoin : MyRandomizer
	{
	public:
		MyCoin();
		virtual ~MyCoin();

		CoinFace flip();
	};
}

#endif // MYRANDOMIZER_H