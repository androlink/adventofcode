#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <unordered_map>

using std::unordered_map;
using std::cin;
using std::cout;
using std::string;

typedef std::unordered_map<long, long>	t_data;

/*
 * unordered_map solution of the internet
 */

t_data	applie(t_data &values)
{
	t_data	result;
	int j = 0;

	for (t_data::iterator i = values.begin(); i != values.end(); i++, j++)
	{
		long v = i->first;
		long c = i->second;
		//cout << "	" << j << " / " << values.size() << std::endl;
		if (v < 0)
			cout << "\a";	// prevent overflow with a beep
		if (v == 0)
		{
			result[1] += c;
		}
		else if ((long)log10(v) % 2)
		{
			long half = (log10(v) + 1) / 2;

			result[v / pow(10, half)] += c;
			result[v % (long)pow(10, half)] += c;
		}
		else
		{
			result[v * 2024] += c;
		}
	}
	return (result);
}

void	print(t_data values)
{
	cout << std::endl;
	cout << "values:	";
	for (t_data::iterator i = values.begin(); i != values.end(); i++)
		cout << i->first << ": " << i->second << ", ";
	cout << std::endl;
}

int	main()
{
	t_data	result;
	long		value;

	while (cin >> value)
	{
		result[value]++;
	}
	print(result);
	int stop = 75;
	for (long i = 0; i < stop; i++)
	{
		cout << i << " / " << stop << std::endl;
		result = applie(result);
		print(result);
	}
	long count = 0;
	for (t_data::iterator i = result.begin(); i != result.end(); i++)
	{
		count += i->second;
	}
	cout << "count: " << count << std::endl;
}
