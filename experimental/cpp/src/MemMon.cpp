#include "MemMon.h"

void MemMon::Cleanup()
{
	SetMemMon::Cleanup();
	MapMemMon::Cleanup();
}
