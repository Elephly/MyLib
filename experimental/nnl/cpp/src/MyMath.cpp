#include "MyMath.h"

namespace MyLib
{
	int MyMod(int n, int m)
	{
		int out = n;
		while (out > m)
		{
			out -= n;
		}
		return out;
	}
}