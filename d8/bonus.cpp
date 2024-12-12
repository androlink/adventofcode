#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <unordered_map>

using std::vector;
using std::cin;
using std::cout;
using std::string;


typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_point_char
{
	int	x;
	int	y;
	u_char	freq;
}	t_point_char;

typedef std::unordered_map<u_char, vector<t_point>>	it;

t_point		dimention = {0};

void	print_set(it &umap)
{
	cout << "set:" << std::endl;
	for (it::iterator i = umap.begin(); i != umap.end(); i++)
	{
		cout << i->first << ": ";
		for (auto j = i->second.begin(); j != i->second.end(); j++)
			cout << "{" << j->x << ", " << j->y << "},";
		cout <<std::endl;
	}
}

void	resolve_loop(vector<t_point_char> &result, t_point start, t_point delta, u_char freq)
{
	if (delta.x == 0 && delta.y == 0)
		return ;
	while (start.x >= 0
		&& start.y >= 0
		&& start.x < dimention.x
		&& start.y < dimention.y)
	{
		t_point_char tmp = {.x = start.x, .y = start.y, .freq = freq};
		result.push_back(tmp);
		start.x += delta.x;
		start.y += delta.y;
	}
}

void	resolve(it &umap, vector<t_point_char> &result)
{
	for (it::iterator i = umap.begin(); i != umap.end(); i++)
	{
		for (std::vector<t_point>::iterator j = i->second.begin(); j != i->second.end(); j++)
		{
			for (std::vector<t_point>::iterator k = i->second.begin(); k != i->second.end(); k++)
			{
				resolve_loop(result, *k, {.x = j->x - k->x, .y = j->y - k->y}, i->first);
			}
		}
	}
}

void	clean(it &umap, vector<t_point_char> &result, t_point dimention)
{
	// for (it::iterator i = umap.begin(); i != umap.end(); i++)
	// {
	// 	for (std::vector<t_point>::iterator j = i->second.begin(); j != i->second.end(); j++)
	// 	{
	// 		for (std::vector<t_point_char>::iterator k = result.begin(); k != result.end(); k++)
	// 		{
	// 			if (k->freq != i->first)
	// 				continue ;
	// 			if (j->x == k->x && j->y == k->y)
	// 			{
	// 				cout << "conflict	erase: " << k->x << " " << k->y << std::endl;
	// 				result.erase(k);
	// 				k--;
	// 			}
	// 		}
	// 	}
	// }
	for (std::vector<t_point_char>::iterator i = result.begin(); i != result.end(); i++)
		for (std::vector<t_point_char>::iterator j = result.begin(); j != result.end(); j++)
		{
			if (i == j)
				continue ;
			if (i->x < 0 || i->y < 0 || i->x >= dimention.x || i->y >= dimention.y)
			{
				cout << "oob	erase: " << i->x << " " << i->y << std::endl;
				result.erase(i);
				i--;
				j--;
				break ;
			}
			else if ((j->x == i->x && j->y == i->y))
			{
				cout << "dup	erase: " << i->x << " " << i->y << std::endl;
				result.erase(i);
				i--;
				j--;
				break ;
			}
		}
}

int	main()
{
	it		umap;
	vector<t_point_char>	result;
	int j = 0;
	string	line;

	while (getline(cin, line))
	{
		std::istringstream sl(line);
		u_char	tmp;
		int	i = 0;
		dimention.x = 0;
		while (sl >> tmp)
		{
			if (tmp != '.')
			{
				umap[tmp].push_back({.x = i, .y = j});
			}
			i++;
			dimention.x++;
		}
		dimention.y++;
		j++;
	}
	print_set(umap);
	resolve(umap, result);
	cout << "before" << std::endl;
	for (auto j = result.begin(); j != result.end(); j++)
		cout << "{" << j->x << ", " << j->y << "},";
	cout <<std::endl;
	clean(umap, result, dimention);
	cout << "after" << std::endl;
	for (auto j = result.begin(); j != result.end(); j++)
		cout << "{" << j->x << ", " << j->y << "},";
	cout <<std::endl;
	cout << "result: " << result.size() << std::endl;
}
