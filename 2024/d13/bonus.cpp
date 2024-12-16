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
