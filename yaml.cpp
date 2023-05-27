#include <iostream>
#include <fstream>
#include <vector>

#include "Node.hpp"
#include "Type.hpp"


int main(int argc, char const *argv[])
{
	YamlNode node;

	/*node.read("data.yaml");

	std::cout << node["age"].getInt() << std::endl;
	std::cout << node["message"].getString() << std::endl;*/

	node["str"] = (std::string) "hello world!";
	node["int"] = 1234;
	node["bool"] = true;
	node["char"] = 'h';
	node["float"] = 1.47593f;

	node.write("data.yaml");

	return 0;
}