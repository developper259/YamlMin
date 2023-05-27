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

bool isInt(std::string str)
{
	try {
		size_t pos = 0;
		int nb = std::stoi(str, &pos);
		if (pos == str.length())
			return true;
		else
			return false;
	} catch (const std::exception&) {
		return false;
	}
}
int toInt(std::string str)
{
	try {
		size_t pos = 0;
		int nb = std::stoi(str, &pos);
		if (pos == str.length())
			return nb;
	} catch (const std::exception&) {}
	return 0;
}

bool isBool(std::string str)
{
	if (str == "true")
		return true;
	else if (str == "false")
		return false;
	else
		return -1;
}

char isChar(std::string str)
{
	if (str.size() == 1)
		return str[0];
	else
		return '\0';
}

std::string removeNonAscii(std::string& str)
{
	std::string result;
	for (char c : str)
	{
		//character '\x01'. if not removed i couldn't parse
		if (c != 1 && c < 128)
		{
			result += c;
		}
	}
    return result;
}

NValue convert(std::string str)
{
	if (str.compare("NULL") == 0 || str.empty())
		return NValue();

	str = removeNonAscii(str);

	if (isInt(str) == true)
		return NValue(toInt(str));
	if (isBool(str) != -1)
		return NValue(isBool(str));
	if (isChar(str) != '\0')
		return NValue(isChar(str));
	else
		return NValue((std::string) str);
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

	std::map<std::string, NValue> data{{key, value}};

	return data;
}

#endif