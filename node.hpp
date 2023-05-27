#ifndef YAML_NODE_HPP
#define YAML_NODE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "Type.hpp"
#include "Parser.hpp"

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

				file << pair.first << ": " << node.getString() << std::endl;
			}
			file.close();
		}else
		{
			std::cerr << "error to open file : " << path << std::endl;
		}
	}

	void read(const char* path)
	{
		std::ifstream file(path);

		if (file.is_open()) {
			std::string line;

			while (std::getline(file, line)) {
				std::map<std::string, NValue> d = parseReadYaml(line);

				data.insert(d.begin(), d.end());

			}

			file.close();
		} else {
			std::cerr << "Erreur lors de l'ouverture du fichier : " << path << std::endl;
		}
	}

	int length()
	{
		return data.size();
	}

	bool contains(std::string key)
	{
		if(data.find(key) != data.end())
			return true;
		else
			return false;
	}
	
	//operator
	NValue& operator[](const std::string& key)
	{
		std::string specialChars = " !@#$%^&*():;,?./\\§&#'{[-|`_^à@)]°=+}";
		size_t found = key.find_first_of(specialChars);

		if (found != std::string::npos) 
			std::cerr << "forbids letter special characters in key : " << key << std::endl;

		return data[key];
	}

};

#endif