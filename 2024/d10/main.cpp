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


int	resolve(t_map &map, char highness, t_point co, vector<t_point> &result)
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
		result.push_back(co);
		return (1);
	}
	int count = 0;
	for (int i = 0; i < 4; i++)
	{
		count += resolve(map, highness + 1, {.x = co.x + ((i & 1) * ((i & 2) - 1)), .y = co.y + ((~i & 1) * ((i & 2) - 1))}, result);
	}
	return (count);
}



int	count(vector<t_point> &result)
{
	int c = 0;

	cout << "cleaning" << std::endl;
	for (int i = 0; i < result.size(); i++)
	{
		cout << i << " out of " << result.size() << std::endl;
		for (int j = 0; j < i; j++)
		{
			if (result[i].x == result[j].x
				&& result[i].y == result[j].y)
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
	int c = 0;

	for (int j = 0; j < map.size(); j++)
	{
		for (int i = 0; i < map[j].size(); i++)
		{
			vector<t_point> result;
			cout << "testing: " << i << " " << j << std::endl;
			if (resolve(map, '0', {i, j}, result) == 0)
				continue ;
			int tmp = count(result);
			cout << "found: " << tmp << " at " << i << " " << j << std::endl;
			c += tmp;
		}
	}

	cout << "result: " << c << std::endl;
}
