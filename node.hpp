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
		}else
		{
			std::cerr << "error to open file : " << path << std::endl;
		}
	}

	void write(const char* path)
	{
		init(path);

		std::ofstream file(path);

		if(file.is_open())
		{
			for (const auto& pair : data)
			{
				NValue node = pair.second;
				if (node.type == NValueType::STRING)
					std::cout << "1" << std::endl;

				if(node.type == NValueType::INT)
					file << pair.first << ": " << node.getIntValue() << std::endl;
				if(node.type == NValueType::STRING)
					file << pair.first << ": " << '"' << node.getStringValue() << '"' << std::endl;
				if(node.type == NValueType::BOOL)
				{
					char* value;
					if(node.getBoolValue() == true)
						value = "true";
					else
						value = "false";
					file << pair.first << ": " << value << std::endl;
				}
				if(node.type == NValueType::CHAR)
					file << pair.first << ": " << node.getCharValue() << std::endl;
			}
			file.close();
		}
	}
	
	//operator
	NValue& operator[](const std::string& key)
	{
		return data[key];
	}

};

#endif