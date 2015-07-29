#ifndef MYBITSTACK_H
#define MYBITSTACK_H

#include "shared.h"

namespace MyLib
{
	enum BIT { ZERO=0, ONE=1 };
	typedef BIT bit;

	class MyBitStack
	{
	public:
		MyBitStack(unsigned int size = 1);
		~MyBitStack();
		unsigned int capacity();
		unsigned int size();
		int push(bit b = ZERO);
		int pop();
		int set(unsigned int i, bit b);
		int flip(unsigned int i);
		void flip();
		char *toString();
		
		MyBitStack &operator+=(bit b);
		int operator[](unsigned int i);

	private:
		int checkBit(unsigned int i);

		unsigned int nBits;
		unsigned int nBytes;
		unsigned char *bytes;
	};
}

#endif // MYBITSTACK_H