#include <iostream>
#include <fstream>
#include <vector>

#include "Node.hpp"
#include "Type.hpp"


int main(int argc, char const *argv[])
{
	YamlNode node;

	node.read("data.yaml");

	std::cout << node["age"].getIntValue() << std::endl;

	return 0;
}