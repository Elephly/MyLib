#include "MapMemMon.h"

using namespace std;

std::map<void *, size_t> * MapMemMon::allocatedMemory = 0;

void MapMemMon::Initialize()
{
	if (allocatedMemory == 0)
	{
		allocatedMemory = new std::map<void *, size_t>();
	}
}

void MapMemMon::Cleanup()
{
	if (allocatedMemory != 0)
	{
		delete allocatedMemory;
		allocatedMemory = 0;
	}
}

bool MapMemMon::Null(void * address)
{
	bool rc = (allocatedMemory == 0);
	rc = (!rc ? allocatedMemory->find(address) == allocatedMemory->end() : rc);
	return rc;
}

size_t MapMemMon::SizeOf(void * data)
{
	size_t s = 0;
	if (!Null(data))
	{
		s = (*allocatedMemory)[data];
	}
	return s;
}
