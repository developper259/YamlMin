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

std::string join(const std::vector<std::string>& vec) {
	std::string result;
	for (const std::string& str : vec) {
		result += str;
	}
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

#endif