#ifndef TYPE_NODE_YAML_HPP
#define TYPE_NODE_YAML_HPP

#include <iostream>
#include <string>

#include "parser.hpp"


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
	NValue(std::string value)
	{
		type = NValueType::STRING;
        stringV = new char[value.size() + 1];
        std::strcpy(stringV, value.c_str());
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

	//destructor
	~NValue()
	{
		if (type == NValueType::STRING)
			delete[] stringV;
	}

	//operator
	const NValue& operator=(const int& value)
	{
		type = NValueType::INT;
		intV = value;
		return *this;
	}
	const NValue& operator=(const std::string& value)
	{
		if (type == NValueType::STRING)
			delete[] stringV;

		type = NValueType::STRING;
		stringV = new char[value.size() + 1];
		std::strcpy(stringV, value.c_str());

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