#ifndef VERIF_NODE_YAML_HPP
#define VERIF_NODE_YAML_HPP

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

bool isFloat(std::string str)
{
	try {
		float f = std::stof(str);
		return true;
	} catch (const std::exception&) {
		return false;
	}
}
float toFloat(std::string str)
{
	try {
		float f = std::stof(str);
		return f;
	} catch (const std::exception&) {}

	return 0;
}

int isBool(const std::string& str)
{
	if (str == "true")
		return 1;
	else if (str == "false")
		return 0;
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

#endif