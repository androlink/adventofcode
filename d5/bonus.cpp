
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

using std::vector;

typedef struct s_rule
{
	int	v1;
	int	v2;
}	t_rule;

vector<int> getvalues()
{
	std::string line;
	std::getline(std::cin, line);
	std::istringstream sl(line);
	vector<int> values; 
	while (sl)
	{
		int v;
		sl >> v;
		values.push_back(v);
		sl.ignore(1);
	}
	return (values);
}

int	proccess_rule(t_rule rule, vector<int> &values)
{
	int inco = 0;

	for (int i = 0; i < values.size(); i++)
	{
		if (values[i] != rule.v1)
			continue ;
		for (int j = 0; j < i; j++)
		{
			if (values[j] == rule.v2)
			{
				std::swap(values[i], values[j]);
				inco = 1;
				std::cout << rule.v1 << "|" << rule.v2 << std::endl;
			}
		}
	}
	return (inco);
}

int	is_line_valid(vector<t_rule> &rule_list, vector<int> &values)
{
	int inco = 0;

	for (int i = 0; i < values.size(); i++)
		std::cout << values[i] << " ";
	std::cout << std::endl;
	for (int i = 0; i < rule_list.size(); i++)
	{
		if (proccess_rule(rule_list[i], values))
		{
			inco = 1;
			i = 0;
		}
	}
	std::cout << "	";
	for (int i = 0; i < values.size(); i++)
		std::cout << values[i] << " ";
	std::cout << std::endl;
	return (inco);
}

int	process_line(vector<t_rule> &rule_list)
{
	vector<int> values = getvalues();

	if (!is_line_valid(rule_list, values))
		return (0);
	return (values[(values.size() / 2)]);
}

int	main()
{
	vector<t_rule>	rule_list;
	std::string	line;
	while (std::getline(std::cin, line))
	{
		if (line.empty())
			break ;
		if (line.find("|")) {
			std::stringstream	ss(line);
			t_rule			tmp;
			ss >> tmp.v1;
			ss.ignore(1);
			ss >> tmp.v2;
			rule_list.push_back(tmp);
		}
	}
	int result = 0;
	int tmp = 0;
	while (!std::cin.eof())
	{
		tmp = process_line(rule_list);
		result += tmp;
		std::cout << "	+=" << tmp << std::endl;
	}
	std::cout << result << std::endl;
}