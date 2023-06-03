#include <iostream>
#include <fstream>
#include <vector>

#include "Yaml.hpp"

int main(int argc, char const *argv[])
{
	YamlNode node;
	std::vector<float> v{190.5784, 578.09, 940.13, 19.67, 4.5};

	node["table"] = toString(v);

	std::string table = node["table"];

	std::vector<float> vec = toVecFloat(table);

	for (auto value : vec)
	{
		std::cout << value << std::endl;
	}

	std::cout << table << std::endl;

	return 0;
}