#include <cstdio>
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <ctime>

#include "MemMon.h"
#include "NNError.h"

int main(int argc, char *argv[])
{
	int rc = 0;

	int nnerrno = 0;
	NNERROR_e err = NNERROR[nnerrno];

	while (err != NNERROR_MAX)
	{
		err = NNERROR[nnerrno++];
		printf("%d\n", (int)err);
		printf("%d\n", NNERROR_NUM[err]);
		printf("%s\n", NNERROR_STR[err]);
		printf("\n");
	}

	getchar();
	rc = _CrtDumpMemoryLeaks();
	return rc;
}