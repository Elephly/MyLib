#include "MyConvert.h"

#include "MyStringOps.h"

namespace MyLib
{
	int stringToInt(const char *str, int *out)
	{
		*out = 0;
		int decimalPlace = 1;
		for (int i = stringLength(str) - 1; i >= 0; i--)
		{
			if (str[i] <= '9' && str[i] >= '0')
			{
				*out += (decimalPlace * (str[i] - '0'));
			}
			else
			{
				return 0;
			}
			decimalPlace *= 10;
		}
		return 1;
	}
}