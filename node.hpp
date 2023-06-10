#ifndef YAML_NODE_HPP
#define YAML_NODE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>

#include "Parser.hpp"
#include "Verif.hpp"

class YamlNode
{
private:
	std::map<std::string, std::string> data;

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
			exit(0);
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
				std::string value = pair.second;
				if (value == "")
				{
					file << pair.first << ": null" << std::endl;
				}else if (isTable(value))
				{
					std::vector<std::string> vec = toVecString(value);
					file << pair.first << ": " << std::endl;

					for (auto v : vec)
					{
						if (v == "")
						{
							v = "null";
						}
						file << "	- " << v << std::endl;
					}

				}else
				{
					file << pair.first << ": " << value << std::endl;
				}
			}
			file.close();
		}else
		{
			std::cerr << "error to open file : " << path << std::endl;
			exit(0);
		}
	}

	void read(const char* path)
	{
		std::ifstream file(path);

		if (file.is_open()) {
			std::string line;
			std::vector<std::string> vec;
			std::string vecKey;

			while (std::getline(file, line)) {

				line = supFirstElement(line, ' ');
				line = supFirstElement(line, '\t');

				if (line.at(0) == '-')
				{
					if (vecKey == "")
					{
						std::cerr << "error when reading " << path << " file: elements of a table are instantiated but no table has been created" << std::endl;
						exit(0);
					}

					line = supFirstElement(line, '-');
					line = supFirstElement(line, ' ');

					vec.push_back(line);
				}else
				{
					std::vector<std::string> l = split(line.c_str(), ':');

					std::string key = l[0];
					std::string value = l[1];

					value = supFirstElement(value, ' ');

					if (value == "" || value == " ")
					{
						vecKey = key;
					}else
					{
						if (vecKey != "")
						{
							data[vecKey] = toString(vec);

							vecKey.clear();
							vec.clear();
						}
						data[key] = value;
					}

				}
			}
			if (vecKey != "")
			{
				data[vecKey] = toString(vec);

				vecKey.clear();
				vec.clear();
			}

			file.close();
		} else {
			std::cerr << "Erreur lors de l'ouverture du fichier : " << path << std::endl;
			exit(0);
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

	bool asSpecialChar(const std::string& str)
	{
		std::string specialChars = " !@#$%^&*():;,?./\\§&#'{[|`^à@)]°=+}";
		size_t found = str.find_first_of(specialChars);

		if(found != std::string::npos)
			return false;
		else
			return true;
	}
	bool asLeters(const std::string& str, std::string leters)
	{
		size_t found = str.find_first_of(leters);

		if(found != std::string::npos)
			return false;
		else
			return true;
	}
	
	//operator
	std::string& operator[](const std::string& key)
	{
		if (!asSpecialChar(key))
		{
			std::cerr << "forbids letter special characters in key : " << key << std::endl;
			exit(0);
		}else
			return data[key];
	}
};

#endif