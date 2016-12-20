#ifndef MAPMEMMON_H
#define MAPMEMMON_H

#include <cstdlib>
#include <type_traits>
#include <map>

/**
 * SetMemMon - Memory monitor using a stl map
 *
 * It is not recommended to use the macros and functions in this file directly.
 * Instead, use MemMon.h and set the MEMMON_TYPE preprocessor definition to
 * MAPMEMMON_TYPE.
 */

/**
 * MapMemMon new
 */
#ifndef _mmm_new
#define _mmm_new(constructor) MapMemMon::New<decltype(constructor)>(new constructor, 1)
#endif // _mmm_new

/**
 * MapMemMon new array
 */
#ifndef _mmm_new_a
#define _mmm_new_a(type, n) MapMemMon::New<type>(new type[n](), n)
#endif // _mmm_new_a

/**
 * MapMemMon delete
 */
#ifndef _mmm_delete
#define _mmm_delete(data) MapMemMon::Delete<std::remove_reference<decltype(*data)>::type>(data)
#endif // _mmm_delete

/**
 * MapMemMon null check
 */
#ifndef _mmm_null
#define _mmm_null MapMemMon::Null
#endif // _mmm_null

/**
 * MapMemMon memory size
 */
#ifndef _mmm_sizeof
#define _mmm_sizeof(data) MapMemMon::SizeOf((void *)data)
#endif // _mmm_sizeof

/**
 * MapMemMon element count
 */
#ifndef _mmm_count
#define _mmm_count(data) mm_sizeof((void *)data)/sizeof(decltype(*data))
#endif // _mmm_count

class MapMemMon
{
public:
	virtual ~MapMemMon() = 0;

	static void Initialize();

	static void Cleanup();

	template<typename T>
	static T * New(T * data, size_t count);

	template<typename T>
	static size_t Delete(T * data);

	static bool Null(void * address);

	static size_t SizeOf(void * data);

private:
	static std::map<void *, size_t> * allocatedMemory;

};

template<typename T>
inline T * MapMemMon::New(T * data, size_t count)
{
	if (allocatedMemory == 0)
	{
		Initialize();
	}
	if (allocatedMemory != 0 && data != 0 && count > 0)
	{
		(*allocatedMemory)[(void *)data] = sizeof(T) * count;
	}
	else
	{
		if (data != 0)
		{
			if (count > 1)
			{
				delete[] data;
			}
			else
			{
				delete data;
			}
			data = 0;
		}
	}
	return data;
}

template<typename T>
inline size_t MapMemMon::Delete(T * data)
{
	size_t bytesDeleted = 0;
	size_t dataSize = SizeOf(data);
	size_t dataCount = dataSize / sizeof(T);
	if (data != 0)
	{
		if (allocatedMemory != 0)
		{
			allocatedMemory->erase((void *)data);
			bytesDeleted = dataSize;
			if (allocatedMemory->empty()) {
				Cleanup();
			}
		}
		if (dataCount > 1)
		{
			delete[] data;
		}
		else
		{
			delete data;
		}
	}
	return bytesDeleted;
}

#endif // MAPMEMMON_H
