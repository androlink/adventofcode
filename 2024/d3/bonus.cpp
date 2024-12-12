
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
	std::cout << "mul: ";
	while (std::regex_search(str, match, format))
	{
		std::istringstream tmp(match.str(0));
		tmp >> val;
		std::cout << val << " ";
		res *= val;
		str = match.suffix().str();
	}
	std::cout << "= " << res;
	std::cout << std::endl;
	return (res);
}

int main()
{
	std::string	file;
	int		is_active = 1;
	std::getline(std::cin, file, '\0');
	std::smatch match;
	std::regex format(
		"don't\\(\\)"
		"|do\\(\\)"
		"|mul\\([0-9]+,[0-9]+\\)"
		);
	int res = 0;

	while (std::regex_search(file, match, format))
	{
		std::cout << match.str(0) << std::endl;
		std::cout << is_active << std::endl;
		if (match.str(0) == "don't()")
			is_active = 0;
		else if (match.str(0) == "do()")
			is_active = 1;
		else if (is_active)
			res += proccess(match.str(0));
		file = match.suffix().str();
	}

	std::cout << res << std::endl;
}