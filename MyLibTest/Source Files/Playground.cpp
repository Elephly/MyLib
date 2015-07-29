#include "Playground.h"

namespace Playground
{
	long fib1(int n)
	{
		if (n == 0) return 0L;
		if (n == 1) return 1L;
		return (fib1(n - 1) + fib1(n - 2));
	}

	long fib2(int n)
	{
		if (n == 0) return 0L;
		if (n == 1) return 1L;
		long nm2 = 0;
		long nm1 = 1;
		long f = 1;
		for (int i = 2; i < n; i++)
		{
			nm2 = nm1;
			nm1 = f;
			f = nm1 + nm2;
		}
		return f;
	}
}