#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

using std::vector;
using std::cin;
using std::cout;
using std::string;

long long	op_div(long long v1, long long v2) {return (v1 / (float)v2);}
long long	op_mul(long long v1, long long v2) {return (v1 * v2);}
long long	op_add(long long v1, long long v2) {return (v1 + v2);}
long long	op_sub(long long v1, long long v2) {return (v1 - v2);}

long long (*const op_list[4])(long long, long long) = {op_add, op_mul};

typedef struct
{
	vector<long long>	values;
	long long		result;
}	t_operation;

long long	brut_force(t_operation &operation, long long depth, long long last)
{
	long long	op = 0;

	//cout << "depth: " << depth << std::endl;
	//cout << "last: " << last <<std::endl;
	if (depth < 0)
	{
		// cout << "test: " << operation.result << " [" << last << "]" << std::endl;
		return (last == operation.result);
	}
	//cout << std::setw((operation.values.size() - depth) * 8) << *(operation.values.end() - depth - 1) << std::endl;
	for (long long i = 0; i < 2; i++)
	{
		if (brut_force(operation,
			depth - 1,
			op_list[op](last, *(operation.values.end() - depth - 1))))
			return (1);
		op++;
	}
	return (0);
}

inline long long	is_valide(t_operation &operation)
{
	// cout << "testing: ";
	// cout << operation.result << ":";
	// for (long long j = 0; j < operation.values.size(); j++)
	// 	cout << " " << operation.values[j];
	// cout << std::endl;
	if (brut_force(operation, operation.values.size() - 2, operation.values[0]))
		return (operation.result);
	return (0);
}

int	main()
{
	string			line;
	vector<t_operation>	list;
	long long			result = 0;

	while (std::getline(cin, line))
	{
		t_operation op;
		std::istringstream sl(line);
		sl >> op.result;
		sl.ignore(1);
		long long	v;
		while (sl >> v)
			op.values.push_back(v);
		list.push_back(op);
	}
	for (long long i = 0; i < list.size(); i++)
	{
		cout << i << "/" << list.size() << std::endl;
		result += is_valide(list[i]);
	}
	cout << result << std::endl;
}

// cout << list[i].result << ":";
// 		for (long long j = 0; j < list[i].values.size(); j++)
// 			cout << " " << list[i].values[j];
// 		cout << std::endl;