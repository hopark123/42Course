#include "common.hpp"

#define T1 char
#define T2 int
typedef _pair<const T1, T2> T3;

template <class MAP>
void	cmp(const MAP &lhs, const MAP &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

// int		main(void)
// {
// 	TESTED_NAMESPACE::map<T1, T2> mp1;
// 	TESTED_NAMESPACE::map<T1, T2> mp2;

// 	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
// 	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

// 	cmp(mp1, mp1); // 0
// 	cmp(mp1, mp2); // 1

// 	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

// 	cmp(mp1, mp2); // 2
// 	cmp(mp2, mp1); // 3

// 	(++(++mp1.begin()))->second = 42;
// 	// mp1.print();
// 	// mp2.print();
// 	cmp(mp1, mp2); // 4
// 	cmp(mp2, mp1); // 5

// 	swap(mp1, mp2);

// 	cmp(mp1, mp2); // 6
// 	cmp(mp2, mp1); // 7

// std::cout << "=============================" << std::endl;
// 	std::map<char, int> tp1;
// 	std::map<char, int> tp2;

// 	tp1['a'] = 2; tp1['b'] = 3; tp1['c'] = 4; tp1['d'] = 5;
// 	tp2['a'] = 2; tp2['b'] = 3; tp2['c'] = 4; tp2['d'] = 5;

// 	cmp(tp1, tp1); // 0
// 	cmp(tp1, tp2); // 1

// 	tp2['e'] = 6; tp2['f'] = 7; tp2['h'] = 8; tp2['h'] = 9;

// 	cmp(tp1, tp2); // 2
// 	cmp(tp2, tp1); // 3

// 	(++(++tp1.begin()))->second = 42;
// 	// (tp1.begin())->second = 42;

// 	cmp(tp1, tp2); // 4
// 	cmp(tp2, tp1); // 5

// 	swap(tp1, tp2);

// 	cmp(tp1, tp2); // 6
// 	cmp(tp2, tp1); // 7

// 	return (0);
// }


int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp1;
	TESTED_NAMESPACE::map<T1, T2> mp2;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	cmp(mp1, mp1); // 0
	cmp(mp1, mp2); // 1

	mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	cmp(mp1, mp2); // 2
	cmp(mp2, mp1); // 3

	(++(++mp1.begin()))->second = 42;
	// mp1.print();
	// mp2.print();
	cmp(mp1, mp2); // 4
	cmp(mp2, mp1); // 5

	swap(mp1, mp2);

	cmp(mp1, mp2); // 6
	cmp(mp2, mp1); // 7


	return (0);
}
