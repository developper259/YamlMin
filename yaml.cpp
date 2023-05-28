#include <iostream>
#include <fstream>
#include <vector>

#include "Node.hpp"
#include "Type.hpp"


int main(int argc, char const *argv[])
{
	YamlNode node;

	node.read("data.yaml");

	std::cout << node["int"].getInt() << std::endl;
	std::cout << node["str"].getString() << std::endl;
	std::cout << node["float"].getFloat() << std::endl;
	std::cout << node["bool"].getString() << std::endl;
	std::cout << node["char"].getChar() << std::endl;

	/*node["str"] = (std::string) "hello world!";
	node["int"] = 1234;
	node["bool"] = true;
	node["char"] = 'h';
	node["float"] = 1.47593f;

	node.write("data.yaml");*/

	return 0;
}