#ifndef NNERROR_H
#define NNERROR_H

typedef enum
{
	NNERROR_SUCCESS             = 0x00000000,
	NNERROR_INVALID_FUNCTION    = 0x00000001,
	NNERROR_FILE_NOT_FOUND      = 0x00000002,
	NNERROR_PATH_NOT_FOUND      = 0x00000004,
	NNERROR_TOO_MANY_OPEN_FILES = 0x00000008,
	NNERROR_ACCESS_DENIED       = 0x00000010,
	NNERROR_INVALID_HANDLE      = 0x00000020,
	NNERROR_ARENA_TRASHED       = 0x00000040,
	NNERROR_NOT_ENOUGH_MEMORY   = 0x00000080,
	NNERROR_INVALID_BLOCK       = 0x00000100,
	NNERROR_BAD_ENVIRONMENT     = 0x00000200,
	NNERROR_MAX                 = 0xFFFFFFFF,
} NNERROR_e;

extern const NNERROR_e NNERROR[];
extern const int       NNERROR_NUM[];
extern const char    * NNERROR_STR[];

#endif // NNERROR_H