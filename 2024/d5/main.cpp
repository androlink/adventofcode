
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

int	is_rule_valid(t_rule rule, vector<int> &values)
{
	for (int i = 0; i < values.size(); i++)
	{
		if (values[i] != rule.v1)
			continue ;
		for (int j = 0; j < i; j++)
		{
			if (values[j] == rule.v2)
				return (0);
		}
	}
	return (1);
}

int	is_line_valid(vector<t_rule> &rule_list, vector<int> &values)
{
	for (int i = 0; i < rule_list.size(); i++)
	{
		if (!is_rule_valid(rule_list[i], values))
		{
			std::cout << rule_list[i].v1 << "|" << rule_list[i].v2 << std::endl;
			return (0);
		}
	}
	return (1);
}

int	process_line(vector<t_rule> &rule_list)
{
	vector<int> values = getvalues();

	for (int i = 0; i < values.size(); i++)
		std::cout << values[i] << " ";
	std::cout << std::endl;
	if (is_line_valid(rule_list, values))
	{
		return (values[(values.size() / 2)]);
	}
	return (0);
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
	while (!std::cin.eof())
	{
		result += process_line(rule_list);
	}
	std::cout << result << std::endl;
}