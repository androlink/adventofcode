
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using std::vector;
using std::string;

int is_safe(vector<int>   &values)
{
	for (int i = 0; i < values.size() - 2; i++)
	{
		if (((values[i] > values[i + 1])
			+ (values[i + 1] > values[i + 2])) == 1)
			return (0);
		if (abs(values[i] - values[i + 1]) > 3
			|| values[i] == values[i + 1])
			return (0);
		if (abs(values[i + 1] - values[i + 2]) > 3
			|| values[i + 1] == values[i + 2])
			return (0);
	}
	return (1);		
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
		res += is_safe(values);
		total++;
	}
	std::cout << "total: " << total << std::endl; 
	std::cout << res << std::endl;
}
