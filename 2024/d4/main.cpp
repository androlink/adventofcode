#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

using std::vector;

typedef vector<vector<char>> wtf;

int	is_ho(wtf &t, int x, int y, const char word[4])
{
	if (x > t[y].size() - 4)
		return (0);
	for (int i = 0; i < 4; i++)
		if (t[y][x + i] != word[i])
			return (0);
	std::cout << "ho" << std::endl;
	return (1);
}

int	is_du(wtf &t, int x, int y, const char word[4])
{
	if (y < 3)
		return (0);
	if (x > t[0].size() - 4)
		return (0);
	for (int i = 0; i < 4; i++)
		if (t[y - i][x + i] != word[i])
			return (0);
	std::cout << "du" << std::endl;
	return (1);
}

int	is_dd(wtf &t, int x, int y, const char word[4])
{
	if (y > t.size() - 4)
		return (0);
	if (x > t[0].size() - 4)
		return (0);
	for (int i = 0; i < 4; i++)
		if (t[y + i][x + i] != word[i])
			return (0);
	std::cout << "dd" << std::endl;
	return (1);
}

int	is_ve(wtf &t, int x, int y, const char word[4])
{
	if (y > t.size() - 4)
		return (0);
	for (int i = 0; i < 4; i++)
		if (t[y + i][x] != word[i])
			return (0);
	std::cout << "ve" << std::endl;
	return (1);
}


int main()
{
	std::string	line;
	wtf		t;
	int		res = 0;

	while (std::getline(std::cin, line))
	{
		vector<char>	tmp;
		for (int i = 0; i < line.size(); i++)
			tmp.push_back(line[i]);
		t.push_back(tmp);
	}
	for (int j = 0; j < t.size(); j++)
		for (int i = 0; i < t[0].size(); i++)
		{
			res += is_ve(t, i, j, "XMAS");
			res += is_ve(t, i, j, "SAMX");
			res += is_dd(t, i, j, "XMAS");
			res += is_dd(t, i, j, "SAMX");
			res += is_du(t, i, j, "XMAS");
			res += is_du(t, i, j, "SAMX");
			res += is_ho(t, i, j, "XMAS");
			res += is_ho(t, i, j, "SAMX");

		}
	std::cout << res << std::endl;
}
