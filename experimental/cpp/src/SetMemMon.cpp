#include "SetMemMon.h"

using namespace std;

std::set<void *> * SetMemMon::allocatedMemory = 0;

void SetMemMon::Initialize()
{
	if (allocatedMemory == 0)
	{
		allocatedMemory = new std::set<void *>();
	}
}

void SetMemMon::Cleanup()
{
	if (allocatedMemory != 0)
	{
		delete allocatedMemory;
		allocatedMemory = 0;
	}
}

bool SetMemMon::Null(void * address)
{
	bool rc = (allocatedMemory == 0);
	rc = (!rc ? allocatedMemory->find(address) == allocatedMemory->end() : rc);
	return rc;
}
