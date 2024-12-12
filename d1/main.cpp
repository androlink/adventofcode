
#include <vector>
#include <iostream>

using std::vector;
using std::swap;

void	sort(vector<int> &list)
{
	for (int j = 0; j < list.size() - 1; j++)
	{
		for (int i = j + 1; i > 0; i--)
		{
			if (list[i] < list[i - 1])
			{
				swap(list[i], list[i - 1]);
			}
		}
	}
}

int main()
{
	vector<int> l1;
	vector<int> l2;

	while (std::cin)
	{
		int value;

		std::cin >> value;
		l1.push_back(value);
		std::cin >> value;
		l2.push_back(value);
	}
	sort(l1);
	sort(l2);
	size_t res = 0;
	for (int i = 0; i < l1.size(); i++)
		res += abs(l2[i] - l1[i]);
	std::cout << res << std::endl;
}