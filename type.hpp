#ifndef TYPE_NODE_YAML
#define TYPE_NODE_YAML

#include <iostream>
#include <string>


enum class NValueType
{
	INT,
	STRING,
	BOOL,
	CHAR
};

struct NValue
{
	NValueType type;

	union 
	{
		int intV;
		char* stringV;
		bool boolV;
		char charV;
	};

	//constructor
	NValue()
	{
		type = NValueType::INT;
		intV = 0;
	}
	NValue(int value)
	{
		type = NValueType::INT;
		intV = value;
	}
	NValue(char* value)
	{
		type = NValueType::STRING;
		stringV = value;
	}
	NValue(bool value)
	{
		type = NValueType::BOOL;
		boolV = value;
	}
	NValue(char value)
	{
		type = NValueType::CHAR;
		charV = value;
	}

	//operator
	const NValue& operator=(const int& value)
	{
		type = NValueType::INT;
		intV = value;
		return *this;
	}
	const NValue& operator=(char*& value)
	{
		type = NValueType::STRING;
		stringV = value;
		return *this;
	}
	const NValue& operator=(const bool& value)
	{
		type = NValueType::BOOL;
		boolV = value;
		return *this;
	}
	const NValue& operator=(const char& value)
	{
		type = NValueType::CHAR;
		charV = value;
		return *this;
	}

	int getIntValue()
	{
		return intV;
	}
	char* getStringValue()
	{
		return stringV;
	}
	bool getBoolValue()
	{
		return boolV;
	}
	char getCharValue()
	{
		return charV;
	}

};
#endif