#include "MyVariable.h"

namespace MyLib
{
#pragma region Type

	std::ostream &operator<<(std::ostream &os, const Type &type)
	{
		switch (type)
		{
		case Boolean:
			os << "Boolean";
			break;
		case Char:
			os << "Char";
			break;
		case Double:
			os << "Double";
			break;
		case Int16:
			os << "Int16";
			break;
		case Int32:
			os << "Int32";
			break;
		case Int64:
			os << "Int64";
			break;
		case Int8:
			os << "Int8";
			break;
		case Single:
			os << "Single";
			break;
		case CString:
			os << "CString";
			break;
		case UInt16:
			os << "UInt16";
			break;
		case UInt32:
			os << "UInt32";
			break;
		case UInt64:
			os << "UInt64";
			break;
		case UInt8:
			os << "UInt8";
			break;
		case Missing:
			os << "Missing";
		default:
			break;
		}

		return os;
	}

#pragma endregion

#pragma region Var

#pragma region Constructors/Destructors

	MyVariable::MyVariable() : type(Missing)
	{

	}

	MyVariable::MyVariable(const bool &value) : type(Boolean), boolVal(value)
	{

	}

	MyVariable::MyVariable(const char &value) : type(Char), charVal(value)
	{

	}

	MyVariable::MyVariable(const cstring &value) : type(CString), cstringVal(value)
	{

	}

	MyVariable::MyVariable(const double &value) : type(Double), doubleVal(value)
	{

	}

	MyVariable::MyVariable(const int16 &value) : type(Int16), int16Val(value)
	{

	}

	MyVariable::MyVariable(const int32 &value) : type(Int32), int32Val(value)
	{

	}

	MyVariable::MyVariable(const int64 &value) : type(Int64), int64Val(value)
	{

	}

	MyVariable::MyVariable(const int8 &value) : type(Int8), int8Val(value)
	{

	}

	MyVariable::MyVariable(const single &value) : type(Single), singleVal(value)
	{

	}

	MyVariable::MyVariable(const uint16 &value) : type(UInt16), uint16Val(value)
	{

	}

	MyVariable::MyVariable(const uint32 &value) : type(UInt32), uint32Val(value)
	{

	}

	MyVariable::MyVariable(const uint64 &value) : type(UInt64), uint64Val(value)
	{

	}

	MyVariable::MyVariable(const uint8 &value) : type(UInt8), uint8Val(value)
	{

	}

	MyVariable::MyVariable(const MyVariable &value)
	{
		*this = value;
	}

	MyVariable::~MyVariable()
	{

	}

#pragma endregion

#pragma region Accessors

	Type MyVariable::GetType() const
	{
		return type;
	}

	bool MyVariable::GetBoolVal() const
	{
		return boolVal;
	}

	char MyVariable::GetCharVal() const
	{
		return charVal;
	}

	char *MyVariable::GetCStringVal() const
	{
		return cstringVal;
	}

	double MyVariable::GetDoubleVal() const
	{
		return doubleVal;
	}

	int16 MyVariable::GetInt16Val() const
	{
		return int16Val;
	}

	int32 MyVariable::GetInt32Val() const
	{
		return int32Val;
	}

	int64 MyVariable::GetInt64Val() const
	{
		return int64Val;
	}

	int8 MyVariable::GetInt8Val() const
	{
		return int8Val;
	}

	void *MyVariable::GetMissingVal() const
	{
		return nullptr;
	}

	single MyVariable::GetSingleVal() const
	{
		return singleVal;
	}

	uint16 MyVariable::GetUInt16Val() const
	{
		return uint16Val;
	}

	uint32 MyVariable::GetUInt32Val() const
	{
		return uint32Val;
	}

	uint64 MyVariable::GetUInt64Val() const
	{
		return uint64Val;
	}

	uint8 MyVariable::GetUInt8Val() const
	{
		return uint8Val;
	}

	void *MyVariable::GetVal() const
	{
		switch (type)
		{
		case Boolean:
			return (void *)&boolVal;
			break;
		case Char:
			return (void *)&charVal;
			break;
		case CString:
			return (void *)&cstringVal;
			break;
		case Double:
			return (void *)&doubleVal;
			break;
		case Int16:
			return (void *)&int16Val;
			break;
		case Int32:
			return (void *)&int32Val;
			break;
		case Int64:
			return (void *)&int64Val;
			break;
		case Int8:
			return (void *)&int8Val;
			break;;
		case Single:
			return (void *)&singleVal;
			break;
		case UInt16:
			return (void *)&uint16Val;
			break;
		case UInt32:
			return (void *)&uint32Val;
			break;
		case UInt64:
			return (void *)&uint64Val;
			break;
		case UInt8:
			return (void *)&uint8Val;
			break;
		default:
			return nullptr;
			break;
		}
	}

#pragma endregion

#pragma region Assignment operators

#pragma region operator=

	MyVariable &MyVariable::operator=(const bool &value)
	{
		boolVal = value;
		type = Boolean;
		return *this;
	}

	MyVariable &MyVariable::operator=(const char &value)
	{
		charVal = value;
		type = Char;
		return *this;
	}

	MyVariable &MyVariable::operator=(const cstring &value)
	{
		cstringVal = value;
		type = CString;
		return *this;
	}

	MyVariable &MyVariable::operator=(const double &value)
	{
		doubleVal = value;
		type = Double;
		return *this;
	}

	MyVariable &MyVariable::operator=(const int16 &value)
	{
		int16Val = value;
		type = Int16;
		return *this;
	}

	MyVariable &MyVariable::operator=(const int32 &value)
	{
		int32Val = value;
		type = Int32;
		return *this;
	}

	MyVariable &MyVariable::operator=(const int64 &value)
	{
		int64Val = value;
		type = Int64;
		return *this;
	}

	MyVariable &MyVariable::operator=(const int8 &value)
	{
		int8Val = value;
		type = Int8;
		return *this;
	}

	MyVariable &MyVariable::operator=(const single &value)
	{
		singleVal = value;
		type = Single;
		return *this;
	}

	MyVariable &MyVariable::operator=(const uint16 &value)
	{
		uint16Val = value;
		type = UInt16;
		return *this;
	}

	MyVariable &MyVariable::operator=(const uint32 &value)
	{
		uint32Val = value;
		type = UInt32;
		return *this;
	}

	MyVariable &MyVariable::operator=(const uint64 &value)
	{
		uint64Val = value;
		type = UInt64;
		return *this;
	}

	MyVariable &MyVariable::operator=(const uint8 &value)
	{
		uint8Val = value;
		type = UInt8;
		return *this;
	}

	MyVariable &MyVariable::operator=(const MyVariable &value)
	{
		switch (value.GetType())
		{
		case Boolean:
			*this = value.GetBoolVal();
			break;
		case Char:
			*this = value.GetCharVal();
			break;
		case CString:
			*this = value.GetCStringVal();
			break;
		case Double:
			*this = value.GetDoubleVal();
			break;
		case Int16:
			*this = value.GetInt16Val();
			break;
		case Int32:
			*this = value.GetInt32Val();
			break;
		case Int64:
			*this = value.GetInt64Val();
			break;
		case Int8:
			*this = value.GetInt8Val();
			break;;
		case Single:
			*this = value.GetSingleVal();
			break;
		case UInt16:
			*this = value.GetUInt16Val();
			break;
		case UInt32:
			*this = value.GetUInt32Val();
			break;
		case UInt64:
			*this = value.GetUInt64Val();
			break;
		case UInt8:
			*this = value.GetUInt8Val();
			break;
		default:
			break;
		}

		return *this;
	}

#pragma endregion

#pragma endregion

#pragma endregion
}

#pragma region operator<<

std::ostream &operator<<(std::ostream &os, const MyLib::MyVariable &value)
{
	switch (value.GetType())
	{
	case MyLib::Boolean:
		os << value.GetBoolVal();
		break;
	case MyLib::Char:
		os << value.GetCharVal();
		break;
	case MyLib::CString:
		os << value.GetCStringVal();
		break;
	case MyLib::Double:
		os << value.GetDoubleVal();
		break;
	case MyLib::Int16:
		os << value.GetInt16Val();
		break;
	case MyLib::Int32:
		os << value.GetInt32Val();
		break;
	case MyLib::Int64:
		os << value.GetInt64Val();
		break;
	case MyLib::Int8:
		os << value.GetInt8Val();
		break;;
	case MyLib::Single:
		os << value.GetSingleVal();
		break;
	case MyLib::UInt16:
		os << value.GetUInt16Val();
		break;
	case MyLib::UInt32:
		os << value.GetUInt32Val();
		break;
	case MyLib::UInt64:
		os << value.GetUInt64Val();
		break;
	case MyLib::UInt8:
		os << value.GetUInt8Val();
		break;
	default:
		break;
	}

	return os;
}

#pragma endregion

#pragma region Arithmetic operators

#pragma region operator+

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const bool &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const bool &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const char &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const char &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::cstring &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::cstring &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const double &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const double &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::int16 &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::int16 &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::int32 &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::int32 &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::int64 &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::int64 &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::int8 &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::int8 &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::single &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::single &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::uint16 &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::uint16 &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::uint32 &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::uint32 &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::uint64 &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::uint64 &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value1, const MyLib::uint8 &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::uint8 &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}

MyLib::MyVariable operator+(const MyLib::MyVariable &value, const MyLib::MyVariable &value2)
{
	MyLib::MyVariable out;
	return out;
}


#pragma endregion

#pragma endregion