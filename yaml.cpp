#include <iostream>
#include <fstream>
#include <vector>

#include "Yaml.hpp"

int main(int argc, char const *argv[])
{
	YamlNode node;
	/*std::vector<std::string> v{"hello", "hi", "holla", "hallo", ""};

	node["table"] = toString(v);

	node.write("data.yml");*/
	node.read("data.yml");

	/*std::string table = node["table"];

	std::vector<std::string> vec = toVecString(table);

	for (auto value : vec)
	{
		std::cout << value << std::endl;
	}*/

	std::cout << node["table"] << std::endl;

	return 0;
}