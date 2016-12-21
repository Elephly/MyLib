#ifndef MEMMON_H
#define MEMMON_H

#include "SetMemMon.h"
#include "MapMemMon.h"

/**
 * MemMon - Memory monitor
 *
 * It is recommended to use the macros in this file rather than those in the
 * included files directly.
 */

#ifndef NULL_MEMMON_TYPE
#define NULL_MEMMON_TYPE 0
#endif // NULL_MEMMON_TYPE

#ifndef SETMEMMON_TYPE
#define SETMEMMON_TYPE 1
#endif // SETMEMMON_TYPE

#ifndef MAPMEMMON_TYPE
#define MAPMEMMON_TYPE 2
#endif // MAPMEMMON_TYPE

/**
 * Use this to set the type of memory monitoring to use.
 */
#ifndef MEMMON_TYPE
#define MEMMON_TYPE MAPMEMMON_TYPE
#endif // MEMMON_TYPE

/**
 * MemMon new
 */
#if MEMMON_TYPE==SETMEMMON_TYPE
	#ifndef mm_new
	#define mm_new _smm_new
	#endif
#elif MEMMON_TYPE==MAPMEMMON_TYPE
	#ifndef mm_new
	#define mm_new _mmm_new
	#endif
#else
	#ifndef mm_new
	#define mm_new(constructor) new constructor
	#endif
#endif // mm_new

/**
 * MemMon new array
 */
#if MEMMON_TYPE==SETMEMMON_TYPE
	#ifndef mm_new_a
	#define mm_new_a _smm_new_a
	#endif
#elif MEMMON_TYPE==MAPMEMMON_TYPE
	#ifndef mm_new_a
	#define mm_new_a _mmm_new_a
	#endif
#else
	#ifndef mm_new_a
	#define mm_new_a(type, n) new type[n]()
	#endif
#endif // mm_new_a

/**
 * MemMon delete
 */
#if MEMMON_TYPE==SETMEMMON_TYPE
	#ifndef mm_delete
	#define mm_delete _smm_delete
	#endif
#elif MEMMON_TYPE==MAPMEMMON_TYPE
	#ifndef mm_delete
	#define mm_delete _mmm_delete
	#endif
#else
	#ifndef mm_delete
	#define mm_delete(data) if(data!=0){delete data;data=0;}
	#endif
#endif // mm_delete

/**
 * MemMon delete array
 */
#if MEMMON_TYPE==SETMEMMON_TYPE
	#ifndef mm_delete_a
	#define mm_delete_a _smm_delete_a
	#endif
#elif MEMMON_TYPE==MAPMEMMON_TYPE
	#ifndef mm_delete_a
	#define mm_delete_a _mmm_delete
	#endif
#else
	#ifndef mm_delete_a
	#define mm_delete_a(data) if(data!=0){delete[] data;data=0;}
	#endif
#endif // mm_delete_a

/**
 * MemMon null check
 */
#if MEMMON_TYPE==SETMEMMON_TYPE
	#ifndef mm_null
	#define mm_null _smm_null
	#endif
#elif MEMMON_TYPE==MAPMEMMON_TYPE
	#ifndef mm_null
	#define mm_null _mmm_null
	#endif
#else
	#ifndef mm_null
	#define mm_null(data) (data == 0)
	#endif
#endif // mm_null

/**
 * MemMon memory size
 */
#if MEMMON_TYPE==MAPMEMMON_TYPE
	#ifndef mm_sizeof
	#define mm_sizeof _mmm_sizeof
	#endif
#endif // mm_sizeof

/**
 * MemMon element count
 */
#if MEMMON_TYPE==MAPMEMMON_TYPE
	#ifndef mm_count
	#define mm_count _mmm_count
	#endif
#endif // mm_count

class MemMon
{
public:
	virtual ~MemMon() = 0;

	void Cleanup();
};

#endif // MEMMON_H
