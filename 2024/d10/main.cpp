#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using std::vector;
using std::cin;
using std::cout;
using std::string;

typedef	struct
{
	int	x;
	int	y;
}	t_point;

typedef vector<vector<char>>	t_map;


int	resolve(t_map &map, char highness, t_point co, vector<t_point> &fuck_you)
{
	if (co.x < 0 || co.x >= map[0].size() || co.y < 0 || co.y >= map.size())
	{
		cout << "oob: " << co.x << " " << co.y << std::endl;
		return (0);
	}
	if (highness != map[co.y][co.x])
	{
		cout << "bad: " << co.x << " " << co.y << std::endl;
		return (0);
	}

	cout << "continue: '" << highness << "' at " << co.x << " " << co.y << std::endl;

	if (highness == '9')
	{
		cout << "end: " << co.x << " " << co.y << std::endl;
		fuck_you.push_back(co);
		return (1);
	}
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		count += resolve(map, highness + 1, {.x = co.x + ((i & 1) * ((i & 2) - 1)), .y = co.y + ((~i & 1) * ((i & 2) - 1))}, fuck_you);
	}
	return (count);
}



int	count(vector<t_point> &fuck_you)
{
	int c = 0;

	cout << "cleaning" << std::endl;
	for (int i = 0; i < fuck_you.size(); i++)
	{
		cout << i << " out of " << fuck_you.size() << std::endl;
		for (int j = 0; j < i; j++)
		{
			if (fuck_you[i].x == fuck_you[j].x
				&& fuck_you[i].y == fuck_you[j].y)
				goto next;
		}
		c++;
		next:
		(void) "C++23 feature";
	}
	return (c);
}

int	main()
{
	t_map		map;
	std::string	line;

	while (std::getline(cin, line))
	{
		char c;
		vector<char> tmp;

		std::istringstream sl(line);
		while(sl >> c)
			tmp.push_back(c);
		map.push_back(tmp);
	}
	int result = 0;

	for (int j = 0; j < map.size(); j++)
	{
		for (int i = 0; i < map[j].size(); i++)
		{
			vector<t_point> fuck_you;
			cout << "testing: " << i << " " << j << std::endl;
			if (resolve(map, '0', {i, j}, fuck_you) == 0)
				continue ;
			int tmp = count(fuck_you);
			cout << "found: " << tmp << " at " << i << " " << j << std::endl;
			result += tmp;
		}
	}

	cout << "result: " << result << std::endl;
}
