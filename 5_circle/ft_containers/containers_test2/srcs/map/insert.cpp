#include "common.hpp"

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator iterator;

static int iter = 0;

template <typename MAP, typename U>
void	ft_insert(MAP &mp, U param)
{
	_pair<iterator, bool> tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param);
	std::cout << "insert return: " << printPair(tmp.first);
	std::cout << "Created new node: " << tmp.second << std::endl;
	printSize(mp);
}

template <typename MAP, typename U, typename V>
void	ft_insert(MAP &mp, U param, V param2)
{
	iterator tmp;

	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	tmp = mp.insert(param, param2);
	std::cout << "insert return: " << printPair(tmp);
	printSize(mp);
}

// int		main(void)
// {
// 	TESTED_NAMESPACE::map<T1, T2> mp, mp2;

// 	ft_insert(mp, T3(42, "lol"));
// 	ft_insert(mp, T3(42, "mdr"));

// 	ft_insert(mp, T3(50, "mdr"));
// 	ft_insert(mp, T3(35, "funny"));

// 	ft_insert(mp, T3(45, "bunny"));
// 	ft_insert(mp, T3(21, "fizz"));
// 	ft_insert(mp, T3(38, "buzz"));

// std::cout << "=============test A =========" << std::endl;
// 	ft_insert(mp, mp.begin(), T3(55, "fuzzy"));
// std::cout << "=============test B =========" << std::endl;

// 	ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
// 	ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
// 	ft_insert(mp2, mp2.end(), T3(1500, "World"));


// 	typedef std::map<int, std::string>::value_type tt;
// 	std::map<int, std::string> tmp, tmp2;
// 	std::map<int, std::string>::iterator it;

// 	tmp.insert(tt(42, "lol"));
// 	tmp.insert(tt(42, "mdr"));

// 	tmp.insert(tt(50, "mdr"));
// 	tmp.insert(tt(35, "funny"));

// 	tmp.insert(tt(45, "bunny"));
// 	tmp.insert(tt(21, "fizz"));
// 	tmp.insert(tt(38, "buzz"));
// 	it = tmp.begin();
// 	for (; it != tmp.end();it++){
// 		std::cout << it->first << std::endl;
// 	}
// 	std::cout << "--" <<std::endl;
// 	tmp.insert(tmp.begin(), tt(55, "fuzzy"));
// 	it = tmp.begin();
// 	for (; it != tmp.end();it++){
// 		std::cout << it->first << std::endl;
// 	}
// 	std::cout << "--" <<std::endl;
// 	tmp.insert(tmp.begin(), tt(55, "fuzzy"));

// 	tmp2.insert(tmp2.begin(), tt(1337, "beauty"));
// 	tmp2.insert(tmp2.end(), tt(1000, "Hello"));
// 	tmp2.insert(tmp2.end(), tt(1500, "World"));
// 	it = tmp2.begin();
// 	for (; it != tmp2.end();it++){
// 		std::cout << it->first << std::endl;
// 	}

// 	return (0);
// }










int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp, mp2;

	ft_insert(mp, T3(42, "lol"));
	ft_insert(mp, T3(42, "mdr"));

	ft_insert(mp, T3(50, "mdr"));
	ft_insert(mp, T3(35, "funny"));

	ft_insert(mp, T3(45, "bunny"));
	ft_insert(mp, T3(21, "fizz"));
	ft_insert(mp, T3(38, "buzz"));

	ft_insert(mp, mp.begin(), T3(55, "fuzzy"));
	ft_insert(mp2, mp2.begin(), T3(1337, "beauty"));
	ft_insert(mp2, mp2.end(), T3(1000, "Hello"));
	ft_insert(mp2, mp2.end(), T3(1500, "World"));

	return (0);
}