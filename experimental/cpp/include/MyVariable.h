#ifndef VAR_H
#define VAR_H

#include "shared.h"

namespace MyLib
{
	enum Type
	{
		Boolean,
		Char,
		CString,
		Double,
		Int16,
		Int32,
		Int64,
		Int8,
		Single,
		UInt16,
		UInt32,
		UInt64,
		UInt8,
		Missing,
	};

	std::ostream &operator<<(std::ostream & os, const Type &type);

	typedef char *				cstring;
	typedef signed short		int16;
	typedef signed int			int32;
	typedef signed long long	int64;
	typedef signed char			int8;
	typedef float				single;
	typedef unsigned short		uint16;
	typedef unsigned int		uint32;
	typedef unsigned long long	uint64;
	typedef unsigned char		uint8;

	class MyDeclaredTypes
	{
	public:
		static bool		Boolean;
		static char		Char;
		static cstring	CString;
		static double	Double;
		static int16	Int16;
		static int32	Int32;
		static int64	Int64;
		static int8		Int8;
		static single	Single;
		static uint16	UInt16;
		static uint32	UInt32;
		static uint64	UInt64;
		static uint8	UInt8;
	};
	typedef MyDeclaredTypes DeclType;

	class MyVariable
	{
	public:
		// Constructors/Destructors
		MyVariable();
		MyVariable(const bool &value);
		MyVariable(const char &value);
		MyVariable(const cstring &value);
		MyVariable(const double &value);
		MyVariable(const int16 &value);
		MyVariable(const int32 &value);
		MyVariable(const int64 &value);
		MyVariable(const int8 &value);
		MyVariable(const single &value);
		MyVariable(const uint16 &value);
		MyVariable(const uint32 &value);
		MyVariable(const uint64 &value);
		MyVariable(const uint8 &value);
		MyVariable(const MyVariable &value);
		~MyVariable();

		// Accessors
		Type	GetType()		const;
		bool	GetBoolVal()	const;
		char	GetCharVal()	const;
		char *	GetCStringVal()	const;
		double	GetDoubleVal()	const;
		int16	GetInt16Val()	const;
		int32	GetInt32Val()	const;
		int64	GetInt64Val()	const;
		int8	GetInt8Val()	const;
		void *	GetMissingVal()	const;
		single	GetSingleVal()	const;
		uint16	GetUInt16Val()	const;
		uint32	GetUInt32Val()	const;
		uint64	GetUInt64Val()	const;
		uint8	GetUInt8Val()	const;
		void *	GetVal()		const;

		// Operator overloaders
		/// Assignment operators
		//// operator=
		MyVariable &operator=(const bool &value);
		MyVariable &operator=(const char &value);
		MyVariable &operator=(const cstring &value);
		MyVariable &operator=(const double &value);
		MyVariable &operator=(const int16 &value);
		MyVariable &operator=(const int32 &value);
		MyVariable &operator=(const int64 &value);
		MyVariable &operator=(const int8 &value);
		MyVariable &operator=(const single &value);
		MyVariable &operator=(const uint16 &value);
		MyVariable &operator=(const uint32 &value);
		MyVariable &operator=(const uint64 &value);
		MyVariable &operator=(const uint8 &value);
		MyVariable &operator=(const MyVariable &value);


		operator Type();

	private:
		Type type;
		union
		{
			bool	boolVal;
			char	charVal;
			cstring	cstringVal;
			double	doubleVal;
			int16	int16Val;
			int32	int32Val;
			int64	int64Val;
			int8	int8Val;
			single	singleVal;
			uint16	uint16Val;
			uint32	uint32Val;
			uint64	uint64Val;
			uint8	uint8Val;
		};
	};

	typedef MyVariable var;
}

std::ostream & operator<<(std::ostream & os, const MyLib::MyVariable &var);

/// Arithmetic operators
//// operator+
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const bool &value);
MyLib::MyVariable operator+(const bool &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const char &value);
MyLib::MyVariable operator+(const char &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::cstring &value);
MyLib::MyVariable operator+(const MyLib::cstring &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const double &value);
MyLib::MyVariable operator+(const double &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::int16 &value);
MyLib::MyVariable operator+(const MyLib::int16 &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::int32 &value);
MyLib::MyVariable operator+(const MyLib::int32 &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::int64 &value);
MyLib::MyVariable operator+(const MyLib::int64 &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::int8 &value);
MyLib::MyVariable operator+(const MyLib::int8 &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::single &value);
MyLib::MyVariable operator+(const MyLib::single &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::uint16 &value);
MyLib::MyVariable operator+(const MyLib::uint16 &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::uint32 &value);
MyLib::MyVariable operator+(const MyLib::uint32 &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::uint64 &value);
MyLib::MyVariable operator+(const MyLib::uint64 &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &var, const MyLib::uint8 &value);
MyLib::MyVariable operator+(const MyLib::uint8 &value, const MyLib::MyVariable &var);
MyLib::MyVariable operator+(const MyLib::MyVariable &value, const MyLib::MyVariable &var);

#endif // VAR_H