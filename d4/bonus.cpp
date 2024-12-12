#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <regex>

using std::vector;

typedef vector<vector<char>> wtf;

int	MSMS(wtf &t, int x, int y)
{
	if (t[y][x] != 'A')
		return (0);
	if (t[y - 1][x - 1] != 'M')
		return (0);
	if (t[y - 1][x + 1] != 'S')
		return (0);
	if (t[y + 1][x - 1] != 'M')
		return (0);
	if (t[y + 1][x + 1] != 'S')
		return (0);
	std::cout << "MSMS" << std::endl;
	return (1);
}

int	MMSS(wtf &t, int x, int y)
{
	if (t[y][x] != 'A')
		return (0);
	if (t[y - 1][x - 1] != 'M')
		return (0);
	if (t[y - 1][x + 1] != 'M')
		return (0);
	if (t[y + 1][x - 1] != 'S')
		return (0);
	if (t[y + 1][x + 1] != 'S')
		return (0);
	std::cout << "MMSS" << std::endl;
	return (1);
}

int	SMSM(wtf &t, int x, int y)
{
	if (t[y][x] != 'A')
		return (0);
	if (t[y - 1][x - 1] != 'S')
		return (0);
	if (t[y - 1][x + 1] != 'M')
		return (0);
	if (t[y + 1][x - 1] != 'S')
		return (0);
	if (t[y + 1][x + 1] != 'M')
		return (0);
	std::cout << "SMSM" << std::endl;
	return (1);
}

int	SSMM(wtf &t, int x, int y)
{
	if (t[y][x] != 'A')
		return (0);
	if (t[y - 1][x - 1] != 'S')
		return (0);
	if (t[y - 1][x + 1] != 'S')
		return (0);
	if (t[y + 1][x - 1] != 'M')
		return (0);
	if (t[y + 1][x + 1] != 'M')
		return (0);
	std::cout << "SSMM" << std::endl;
	return (1);
}

int	main()
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
	for (int j = 1; j + 1 < t.size(); j++)
		for (int i = 1; i + 1 < t[0].size(); i++)
		{
			std::cout << "test: " << i << " " << j << std::endl;
			res += MMSS(t, i, j);
			res += MSMS(t, i, j);
			res += SMSM(t, i, j);
			res += SSMM(t, i, j);
		}
	std::cout << res << std::endl;
}