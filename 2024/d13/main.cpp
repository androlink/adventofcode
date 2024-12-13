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
	long	x;
	long	y;
}	t_polong;

typedef struct 
{
	t_polong	a;
	t_polong	b;
	t_polong	prize;
}	t_machine;

long	resolve(t_machine &machine)
{
	long	count = __LONG_MAX__;
	
	cout << "." << std::endl;

	for (long a = 0; a < 100; a++)
	{
		for (long b = 0; b < 100; b++)
		{
			if ((a * machine.a.x + b * machine.b.x) == machine.prize.x && (a * machine.a.y + b * machine.b.y) == machine.prize.y)
			{
				// cout << "." << std::endl;
				// cout << count << std::endl;
				// cout << a * 3 + b * 1 << std::endl;
				if ((a * 3 + b * 1) < count)
				{
					// cout << "fuck" << std::endl;
					count = a * 3 + b * 1;
					// std::cout << count << std::endl;
					cout << a << std::endl;
					cout << b << std::endl;
				}
			}
		}
	}
	// std::cout << count << std::endl;
	return ((count != __LONG_MAX__) * count);
}

int main()
{
	vector<t_machine>	machines;

	string	line;
	while (cin)
	{
		t_machine mac;

		getline(cin, line);
		std::istringstream str(line);
		str.ignore(12);
		str >> mac.a.x;
		str.ignore(4);
		str >> mac.a.y;
		getline(cin, line);
		str = std::istringstream(line);
		str.ignore(12);
		str >> mac.b.x;
		str.ignore(4);
		str >> mac.b.y;
		getline(cin, line);
		str = std::istringstream(line);
		str.ignore(9);
		str >> mac.prize.x;
		str.ignore(4);
		str >> mac.prize.y;
		getline(cin, line);
		machines.push_back(mac);
	}
	long count = 0;
	for (long i = 0; i < machines.size(); i++)
		count += resolve(machines[i]);
	cout << "result: "<< count << std::endl;
}
