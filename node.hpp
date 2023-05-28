#ifndef YAML_NODE_HPP
#define YAML_NODE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>

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
				NValue node = pair.second;

				file << pair.first << ": " << node.getString() << std::endl;
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

			while (std::getline(file, line)) {

				char tv[2][1024];

				int index = 0;
				int index2 = 0;
				int index3 = 0;

				for (int i = 0; i < line.size(); i++)
				{
					char c = line.at(i);
					if (index == 0)
					{
						if (c == ':')
						{
							index++;
						}else{
							tv[index][index2] = c;
							index2++;
						}
					}else{
						tv[index][index3] = c;
						index3++;
					}
				}

				std::string key(tv[0], index2);
				std::string valueSTR(tv[1], index3);

				valueSTR = supFirstSpace(valueSTR);

				NValue value;

				//-------------convert-------------
				if (valueSTR.compare("NULL") != 0 && !valueSTR.empty())
				{
					value.setValue((std::string) valueSTR);
					std::cout << value.getString() << std::endl;
				}
				//-------------fin convert-------------

				data.insert(std::make_pair(key, value));

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
	
	//operator
	NValue& operator[](const std::string& key)
	{
		std::string specialChars = " !@#$%^&*():;,?./\\§&#'{[|`^à@)]°=+}";
		size_t found = key.find_first_of(specialChars);

		if (found != std::string::npos)
		{
			std::cerr << "forbids letter special characters in key : " << key << std::endl;
			exit(0);
		}
		else if (!contains(key))
		{
			std::cerr << "key not found : " << key << std::endl;
			exit(0);
		}
		else
			return data[key];
	}

};

#endif