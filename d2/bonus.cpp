
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using std::vector;
using std::string;

int is_safe(vector<int> &values)
{
	int count = 0;

	for (int i = 0; i < values.size() - 2; i++)
	{
		if (((values[i] > values[i + 1])
			^ (values[i + 1] > values[i + 2])))
			count++;
		if (abs(values[i] - values[i + 1]) > 3)
			count++;
		if (values[i] == values[i + 1])
			count++;
		if (abs(values[i + 1] - values[i + 2]) > 3)
			count++;
		if (values[i + 1] == values[i + 2])
			count++;
	}
	return (count < 1);
}

int is_really_safe(vector<int> &values)
{
	int i = 0;

	if (is_safe(values))
		return (1);
	while (i < values.size())
	{
		vector<int> copy = values;
		copy.erase(copy.begin() + i);
		if (is_safe(copy))
			return (1);
		i++;
	}
	return (0);
}

int main()
{
	vector<int>	values;
	string		line;
	int		total = 0;
	int		res = 0;

	while(std::getline(std::cin, line))
	{
		values.clear();
		int value;
		std::istringstream sline(line);
		while (sline >> value)
			values.push_back(value);
		res += is_really_safe(values);
		total++;
	}
	std::cout << "total: " << total << std::endl; 
	std::cout << res << std::endl;
}
