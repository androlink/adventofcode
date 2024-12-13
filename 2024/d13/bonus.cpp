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
}	t_point;

typedef struct 
{
	t_point	a;
	t_point	b;
	t_point	prize;
}	t_machine;

long	resolve(t_machine &machine)
{
	cout << "." << std::endl;

	long a = (machine.prize.x * machine.b.y - machine.b.x * machine.prize.y)
			/ (machine.a.x * machine.b.y - machine.b.x * machine.a.y);

	long b = (machine.prize.x - machine.a.x * a) /(double) machine.b.x * 1000.;
	long check = (machine.prize.y - machine.a.y * a) /(double) machine.b.y * 1000.;
	cout << a << std::endl;
	cout << b << std::endl;
	cout << check << std::endl;
	if (b != check)
		return (0);
	cout << "work" << std::endl;
	return (a * 3 + b / 1000);
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
		mac.prize.x += 10000000000000;
		str.ignore(4);
		str >> mac.prize.y;
		mac.prize.y += 10000000000000;
		getline(cin, line);
		machines.push_back(mac);
	}
	long count = 0;
	for (long i = 0; i < machines.size(); i++)
		count += resolve(machines[i]);
	cout << "result: "<< count << std::endl;
}

/*
	long	count = __LONG_MAX__;

	cout << "resolve" << std::endl;
	for (long a = 0; (a * machine.a.x <= machine.prize.x) && (a * machine.a.y <= machine.prize.y); a++)
	{
		if (a % 100 == 0)
			cout << "a: " << a << std::endl;
		// 	cout << "waou" << std::endl;
		for (long b = 0; (a * machine.a.x + b * machine.b.x <= machine.prize.x) && (a * machine.a.y + b * machine.b.y <= machine.prize.y); b++)
		{
			if (b % 100000000 == 0)
				cout << "b: " << b << std::endl;
			if ((a * machine.a.x + b * machine.b.x) == machine.prize.x && (a * machine.a.y + b * machine.b.y) == machine.prize.y)
			{
				cout << "." << std::endl;
				cout << count << std::endl;
				cout << a * 3 + b * 1 << std::endl;
				if ((a * 3 + b * 1) < count)
				{
					cout << "fuck" << std::endl;
					count = a * 3 + b * 1;
					std::cout << count << std::endl;

				}
			}
		}
	}
	std::cout << count << std::endl;
	return ((count != __LONG_MAX__) * count);
*/