#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>

using std::vector;
using std::cin;
using std::cout;
using std::string;


vector<long>	applie(vector<long> values)
{
	vector<long>	result;

	for (long i = 0; i < values.size(); i++)
	{
		if (values[i] < 0)
			cout << "\a";	// prevent overflow with a beep
		if (values[i] == 0)
		{
			result.push_back(1);
		}
		else if ((long)log10(values[i]) % 2)
		{
			//cout << "half " << values[i] << std::endl;
			long half = (log10(values[i]) + 1) / 2;
			//cout << half << std::endl;
			result.push_back(values[i] / pow(10, half));
			result.push_back(values[i] % (long)pow(10, half));
		}
		else
		{
			result.push_back(values[i] * 2024);
		}
	}
	return (result);
}

void	print(vector<long> values)
{
	cout << std::endl;
	cout << "values:	";
	for (long i = 0; i < values.size(); i++)
		cout << values[i] << " ";
	cout << std::endl;
}

int	main()
{
	vector<long>	result;
	long		value;

	while (cin >> value)
	{
		result.push_back(value);
	}
	print(result);
	for (long i = 0; i < 25; i++)
	{
		result = applie(result);
		//print(result);
	}
	cout << "count: " << result.size() << std::endl;
}
