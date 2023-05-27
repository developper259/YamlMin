#ifndef YAML_NODE_HPP
#define YAML_NODE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "type.hpp"

class YamlNode
{
private:
	std::map<std::string, NValue> data;

public:

	YamlNode()
	{

	}

	void init(const char* path)
	{
		std::ofstream file(path);

		if(file.is_open())
		{
			file.close();
		}
	}

	void write(const char* path)
	{

	}
	
	//operator
	NValue& operator[](const std::string& key)
	{
		return data[key];
	}

};

#endif