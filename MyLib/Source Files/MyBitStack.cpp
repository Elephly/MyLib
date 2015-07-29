#include "MyBitStack.h"

namespace MyLib
{
	MyBitStack::MyBitStack(unsigned int size) : nBytes(size), nBits(0)
	{
		bytes = new unsigned char[nBytes];
	}

	MyBitStack::~MyBitStack()
	{
		if (bytes != 0)
		{
			delete[] bytes;
			bytes = 0;
		}
	}

	unsigned int MyBitStack::capacity()
	{
		return nBytes * 8;
	}

	unsigned int MyBitStack::size()
	{
		return nBits;
	}

	int MyBitStack::push(bit b)
	{
		unsigned int byte = nBits / 8;

		if (byte >= nBytes)
		{
			unsigned char *temp = bytes;
			bytes = new unsigned char[nBytes * 2];
			for (unsigned int i = 0; i < nBytes; i++)
			{
				bytes[i] = temp[i];
			}
			delete[] temp;
			nBytes *= 2;
		}
		
		nBits++;
		if (!set(nBits-1, b))
		{
			nBits--;
			return 0;
		}

		return 1;
	}

	int MyBitStack::pop()
	{
		if (nBits > 0)
		{
			int out = (*this)[nBits - 1];
			nBits--;

			unsigned int byte = nBits / 8;
			if (byte < (nBytes / 4))
			{
				unsigned char *temp = bytes;
				bytes = new unsigned char[nBytes / 2];
				for (unsigned int i = 0; i <= byte; i++)
				{
					bytes[i] = temp[i];
				}
				delete[] temp;
				nBytes /= 2;
			}
			return out;
		}
		return -1;
	}

	int MyBitStack::set(unsigned int i, bit b)
	{
		if (checkBit(i))
		{
			int byte = i / 8;
			int bit = i % 8;

			if (b == ONE)
			{
				bytes[byte] |= (1 << bit);
			}
			else if (b == ZERO)
			{
				bytes[byte] &= ~(1 << bit);
			}
			else
			{
				return 0;
			}
			return 1;
		}
		return 0;
	}

	int MyBitStack::flip(unsigned int i)
	{
		if (checkBit(i))
		{
			if ((*this)[i] == 1)
			{
				set(i, ZERO);
			}
			else if ((*this)[i] == 0)
			{
				set(i, ONE);
			}
			else
			{
				return 0;
			}
			return 1;
		}
		return 0;
	}

	void MyBitStack::flip()
	{
		for (unsigned int i = 0; i < nBits; i++)
		{
			flip(i);
		}
	}

	char *MyBitStack::toString()
	{
		char *str = new char[nBits + 1];
		for (unsigned int i = 0; i < nBits; i++)
		{
			if ((*this)[i])
			{
				str[i] = '1';
			}
			else
			{
				str[i] = '0';
			}
		}
		str[nBits] = '\0';
		return str;
	}

	MyBitStack &MyBitStack::operator+=(bit b)
	{
		push(b);
		return *this;
	}

	int MyBitStack::operator[](unsigned int i)
	{
		if (checkBit(i))
		{
			unsigned int byte = i / 8;
			unsigned int bit = i % 8;
		
			if ((bytes[byte] >> bit) & 1)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		return -1;
	}

	int MyBitStack::checkBit(unsigned int i)
	{
		if (i >= nBits)
		{
			throw out_of_range("Access violation: array index out of range.");
			return 0;
		}
		return 1;
	}
}