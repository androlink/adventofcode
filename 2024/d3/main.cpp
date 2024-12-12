
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

int proccess(std::string str)
{
	std::smatch	match;
	std::regex	format("[0-9]+");
	int		res;
	int		val;

	res = 1;
	while (std::regex_search(str, match, format))
	{
		std::cout << "value: " << match.str(0) << std::endl;
		std::istringstream tmp(match.str(0));
		tmp >> val;
		res *= val;
		str = match.suffix().str();
	}
	return (res);
}

int main()
{
	std::string	file;
	std::getline(std::cin, file, '\0');
	std::smatch match;
	std::regex format("mul\\([0-9]+,[0-9]+\\)");
	int res = 0;

	while (std::regex_search(file, match, format))
	{
		std::cout << match.str(0) << std::endl;
		res += proccess(match.str(0));
		file = match.suffix().str();
	}

	std::cout << res << std::endl;
}