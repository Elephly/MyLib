#include "MyStringOps.h"

namespace MyLib
{
	int stringLength(const char *str)
	{
		int length = 0;
		while (str[++length]);
		return length;
	}
}