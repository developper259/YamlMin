#ifndef YAML_PARSER_HPP
#define YAML_PARSER_HPP

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

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

#endif