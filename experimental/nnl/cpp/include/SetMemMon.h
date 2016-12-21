#ifndef SETMEMMON_H
#define SETMEMMON_H

#include <cstdlib>
#include <type_traits>
#include <set>

/**
 * SetMemMon - Memory monitor using a stl set
 *
 * It is not recommended to use the macros and functions in this file directly.
 * Instead, use MemMon.h and set the MEMMON_TYPE preprocessor definition to
 * SETMEMMON_TYPE.
 */

/**
 * SetMemMon new
 */
#ifndef _smm_new
#define _smm_new(constructor) SetMemMon::New<decltype(constructor)>(new constructor, 1)
#endif // _smm_new

/**
 * SetMemMon new array
 */
#ifndef _smm_new_a
#define _smm_new_a(type, n) SetMemMon::New<type>(new type[n](), n)
#endif // _smm_new_a

/**
 * SetMemMon delete
 */
#ifndef _smm_delete
#define _smm_delete(data) SetMemMon::Delete<std::remove_reference<decltype(*data)>::type>(data, false)
#endif // _smm_delete

/**
 * SetMemMon delete array
 */
#ifndef _smm_delete_a
#define _smm_delete_a(data) SetMemMon::Delete<std::remove_reference<decltype(*data)>::type>(data, true)
#endif // _smm_delete_a

/**
 * SetMemMon null check
 */
#ifndef _smm_null
#define _smm_null SetMemMon::Null
#endif // _smm_null

class SetMemMon
{
public:
	virtual ~SetMemMon() = 0;

	static void Initialize();

	static void Cleanup();

	template<typename T>
	static T * New(T * data, size_t count);

	template<typename T>
	static void Delete(T * data, bool isArray);

	static bool Null(void * address);

private:
	static std::set<void *> * allocatedMemory;

};

template<typename T>
inline T * SetMemMon::New(T * data, size_t count)
{
	if (allocatedMemory == 0)
	{
		Initialize();
	}
	if (allocatedMemory != 0 && data != 0 && count > 0)
	{
		allocatedMemory->insert((void *)data);
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
inline void SetMemMon::Delete(T * data, bool isArray)
{
	if (data != 0)
	{
		if (allocatedMemory != 0)
		{
			allocatedMemory->erase((void *)data);
			if (allocatedMemory->empty()) {
				Cleanup();
			}
		}
		if (isArray)
		{
			delete[] data;
		}
		else
		{
			delete data;
		}
	}
}

#endif // SETMEMMON_H
