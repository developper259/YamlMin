#ifndef TYPE_NODE_YAML_HPP
#define TYPE_NODE_YAML_HPP

#include <iostream>
#include <cstring>

#include "Verif.hpp"

struct NValue
{
	char* value;

	void clear()
	{
		delete[] value;
	}
	void setValue(std::string v)
	{
		clear();

		value = new char[v.size() + 1];
		std::strcpy(value, v.c_str());
	}


	//constructor
	NValue(){}
	NValue(int value)
	{
		setValue(std::to_string(value));
	}
	NValue(float value)
	{
		setValue(std::to_string(value));
	}

	NValue(std::string value)
	{
		setValue(value);
	}
	NValue(bool value)
	{
		if (value == true)
			setValue("true");
		else
			setValue("false");
	}
	NValue(char value)
	{
		std::string str(1, value);
		setValue(str);
	}

	//destructor
	~NValue()
	{
		clear();
	}

	//operator
	const NValue& operator=(const int& value)
	{
		setValue(std::to_string(value));
		return *this;
	}
	const NValue& operator=(const float& value)
	{
		setValue(std::to_string(value));
		return *this;
	}
	const NValue& operator=(const std::string& value)
	{
		setValue(value);

		return *this;
	}
	const NValue& operator=(const bool& value)
	{
		if (value == true)
			setValue("true");
		else
			setValue("false");
		return *this;
	}
	const NValue& operator=(const char& value)
	{
		std::string str(1, value);
		setValue(str);
		return *this;
	}

	int getInt()
	{
		if (isInt(value))
			return toInt(value);
		else
			std::cerr << "cannot convert '" << value << " to int" << std::endl;
	}
	float getFloat()
	{
		if (isFloat(value))
			return toFloat(value);
		else
			std::cerr << "cannot convert '" << value << " to float" << std::endl;
	}
	char* getString()
	{
		return value;
	}
	bool getBool()
	{
		if (isBool(value) != -1)
			return isBool(value);
		else
			std::cerr << "cannot convert '" << value << " to bool" << std::endl;
	}
	char getChar()
	{
		if(isChar(value) != '\0')
			return isChar(value);
		else
			std::cerr << "cannot convert '" << value << "' to char" << std::endl;
	}

};
#endif