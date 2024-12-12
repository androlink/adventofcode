#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <utility>

using std::vector;
using std::cin;
using std::cout;
using std::string;
using std::pair;

typedef vector<long>	t_rules;

typedef struct
{
	long		id;
	long		size;
}	t_drawer;

typedef vector<t_drawer>	t_shelf;

void	fill(vector<long> &result, t_rules &rules)
{
	long	curent = 0;

	for (long i = 0; i < rules.size(); i++)
	{
		for (long j = 0; j < rules[i]; j++)
		{
		//cout << rules[i] << std::endl;
			if (i & 1)
				result.push_back(-1);
			else
				result.push_back(curent);
		}
		if (~i & 1)
			curent++;
	}
}

void	sort_shelf(t_shelf &shelf)
{
	for (int i = shelf.size() - 1; i >= 0; i--)
	{
		if (shelf[i].id == -1)
			continue ;
		for (int empty = 0; empty < i; empty++)
		{
			if (shelf[empty].id != -1)
				continue ;
			if (shelf[empty].size >= shelf[i].size)
			{
				cout << "swaping ";
				cout << "drawer " << shelf[i].id << " sized " << shelf[i].size << " with ";
				cout << "drawer " << shelf[empty].id << " sized " << shelf[empty].size << std::endl;
				std::swap(shelf[i], shelf[empty]);
				t_drawer drawer;
				drawer.id = -1;
				drawer.size = shelf[i].size - shelf[empty].size;
				shelf[i].size -= drawer.size;
				shelf.insert(shelf.begin() + (empty + 1), drawer);
				i++;
				break ;
			}
		}
	}
}

void	process(vector<long> &result)
{
	t_shelf	shelf;

	for (int i = 0; i < result.size(); i++)
	{
		t_drawer	drawer = {0};
		drawer.id = result[i];
		while (i < result.size() && result[i] == drawer.id)
		{
			drawer.size++;
			i++;
		}
		i--;
		shelf.push_back(drawer);
		cout << "drawer " << drawer.id << " sized " << drawer.size << std::endl;
	}
	sort_shelf(shelf);
	result.clear();
	for (int i = 0; i < shelf.size(); i++)
	{
		while (shelf[i].size--)
		{
			result.push_back(shelf[i].id);
		}
	}
}

long	count(vector<long> &result)
{
	long	count = 0;

	for (long i = 0; i < result.size(); i++)
	{
		if (result[i] == -1)
			continue ;
		count += result[i] * i;
	}
	return (count);
}

int main()
{
	t_rules	rules;
	vector<long> result;

	while (cin)
	{
		char	tmp;
		cin >> tmp;
		if (tmp >= '0' && tmp <= '9')
			rules.push_back((long)((tmp - '0')) & 0xff);
	}
	fill(result, rules);
	cout << "fill: " << std::endl;
	for (long i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << std::endl; 
	process(result);
	long c = count(result);
	cout << "process: " << std::endl;
	for (long i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << std::endl; 
	cout << "size: "<< result.size() << std::endl;
	cout << "result: " << c << std::endl;
}