#ifndef NODE_YAML_PARSER_HPP
#define NODE_YAML_PARSER_HPP

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

#include "Type.hpp"


std::vector<char*> split(const char* str, char delimiter)
{
	char tv[100][255];
	int index = 0;
	int index2 = 0;
	for (int i = 0; i < strlen(str); i++)
	{
		char c = str[i];
		if(c == delimiter)
		{
			index++;
			index2 = 0;
		}else
		{
			tv[index][index2] = c;
			index2++;
		}
	}

	std::vector<char*> result(tv, tv + (index + 1));

	return result;
}

std::string supFirstSpace(std::string str)
{
	size_t pos = str.find_first_not_of(' ');
	if (pos != std::string::npos)
		return str.substr(pos);
	else
		return str;
}

std::map<std::string, NValue> parseReadYaml(std::string line)
{
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
	}
	//-------------fin convert-------------

	std::map<std::string, NValue> data{{key, value}};

	return data;
}

#endif