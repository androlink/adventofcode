
#include <vector>
#include <iostream>

using std::vector;
using std::iterator;
using std::swap;

int count(vector<int> list, int value)
{
	int res = 0;

	for (int i = 0; i < list.size(); i++)
		if (list[i] == value)
			res++;
	return (res);
}

int main()
{
	vector<int> l1;
	vector<int> l2;

	while (1)
	{
		int value;

		if (!(std::cin >> value))
			break ;
		l1.push_back(value);
		if (!(std::cin >> value))
			break ;
		l2.push_back(value);
	}

	size_t res = 0;
	for (int i = 0; i < l1.size(); i++)
	{
		int tmp = count(l2, l1[i]);
		tmp *= l1[i];
		res += tmp;
	}
	std::cout << res << std::endl;
}