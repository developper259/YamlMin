#include <iostream>
#include <fstream>
#include <vector>

#include "Yaml.hpp"

int main(int argc, char const *argv[])
{
	YamlNode node;

	node.read("data.yaml");

	int number = toInt(node["number"]);

	std::cout << number << std::endl;

	return 0;
}