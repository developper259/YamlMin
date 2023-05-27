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

int isInt(std::string str)
{
	try {
        size_t pos = 0;
        int nb = std::stoi(str, &pos);
        if (pos == str.length())
        	return nb;
       	else
       		return -1;
    } catch (const std::exception&) {
        return -1;
    }
}

bool isBool(std::string str)
{
	if (str == "true")
		return true;
	else if (str == "false")
		return false;
	else
		return NULL;
}

char isChar(std::string str)
{
	if (str.size() == 1)
		return str[0];
	else
		return NULL;
}

NValue convert(std::string str)
{
	if (str.compare("NULL") == 0 || str.empty())
		return NValue();

	if (isInt(str) != -1)
		return NValue(isInt(str));
	if (isBool(str) != NULL)
		return NValue(isBool(str));
	if (isChar(str) != '\0')
		return NValue(isChar(str));
	else
		return NValue((std::string) str);
}

std::string supFirstSpace(std::string str)
{
	char tv[1024];

	bool isCommenced = false;
	int index = 0;

	for (int i = 0; i < str.size(); ++i)
	{
		char c = str.at(i);
		if(c != ' ')
			isCommenced = true;

		if (isCommenced == true)
		{
			tv[index] = c;
			index++;
		}
	}

	return (std::string) tv;
}

std::map<std::string, NValue> parseReadYaml(std::string line, std::map<std::string, NValue> data)
{
	char tv[2][1024];
	int index = 0;
	int index2 = 0;
	for (int i = 0; i < line.size(); i++)
	{
		char c = line.at(i);
		if(c == ':' && index == 0)
		{
			index++;
			index2 = 0;
		}else
		{
			tv[index][index2] = c;
			index2++;
		}
	}

	std::string key(tv[0]);
	std::string valueSTR(tv[1]);

	NValue value = convert(supFirstSpace(valueSTR));
	data[key] = value;

	return data;
}

#endif