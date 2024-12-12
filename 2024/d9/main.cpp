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

void	process(vector<long> &result)
{
	long	j;

	for (long i = result.size() - 1; i >= 0; i--)
	{
		if (result[i] == -1)
			continue ;
		j = 0;
		while (j < i && result[j] != -1)
			j++;
		std::swap(result[i], result[j]);
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