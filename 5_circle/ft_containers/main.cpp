#include <iostream>
#include "Vector.hpp"
#include "Iterator_utils.hpp"
#include "Vector_iterator.hpp"
// #include "tree.hpp"
// #include "map.hpp"
#include "ft_utils.hpp"
#include <vector>
// #include <map>
// #include <string.h>

// <template T>
// class less
// {
// 	if ()
// }
// int main()
// {
// 	// int a = 3;
// 	// int b = 4;
// 	// ft::Pair<int, int> c = ft::make_pair<int, int>(a, b);
// 	// ft::Pair<int, int> d = ft::make_pair<int, int>(5, 6);


// 	// ft::Map<int, int> ma;
// 	// std::map<int, int> f;

// 	// ma.insert(c);
// 	// ma.insert(d);

// 	// ft::Map<int,int>::iterator it;
// 	// it = ma.begin();
// 	// it++;
// 	// std::cout << it->first << std::endl;
// 	// ma.clear();


// // 	ft::Tree<int>::Node	node1(1);
// // 	ft::Tree<int>::Node	node2(2);
// // 	ft::Tree<int>::Node	node3(3);
// // 	ft::Tree<int>::Node	node4(4);
// // 	ft::Tree<int>::Node	node5(5);
// // 	ft::Tree<int>::Node	node6(6);
// // 	ft::Tree<int>::Node	node7(7);
// // 	ft::Tree<int>::Node	node8(8);
// // 	ft::Tree<int>::Node	node9(9);
// // 	ft::Tree<int>::Node	node10(10);
// // 	ft::Tree<int>::Node	node11(11);

// // 	ft::Tree<int>::node_ptr ptr;
// // 	// Tree->copy_node(&ptr, ptr, ptr);

// // 	ptr = &node2;
// // 	Tree->insert_node(&node5, &node3);
// // 	Tree->insert_node(&node5, &node2);
// // 	Tree->insert_node(&node5, &node7);
// // 	Tree->insert_node(&node5, &node4);
// // 	Tree->insert_node(&node5, &node1);
// // 	Tree->insert_node(&node5, &node9);
// // 	Tree->insert_node(&node5, &node6);
// // 	Tree->insert_node(&node5, &node8);
// // 	Tree->insert_node(&node5, &node10);
// // 	Tree->insert_node(&node5, &node11);
// // 	Tree->print(&node5);
// // 	// std::cout << Tree->_root->_data <<std::endl;
// // 	Tree->erase_node(&node5, &node4);
// // 	std::cout << "\n" << std::endl;
// // 	Tree->print(&node5);

// 	std::Vector<int> b;
// 	std::Vector<int>::iterator itb;
// 	itb = b.begin();
// 	// b.assign(8, 0);
// 	const int c = 6;
// 	b.insert(itb, 3);
// 	ft::Vector<int> a;
// 	ft::Vector<int>::iterator ita;
// 	a.rbegin();
// 	ita = a.begin();
// 	a.assign(3, c);
// 	ita = a.begin();
// 	ita++;
// 	a.insert(ita, 4);
// 	a.debug();
// }

#include "containers_test/srcs/vector/common.hpp"
int		main(void)
{
	TESTED_NAMESPACE::Vector<int> vct(7);
	TESTED_NAMESPACE::Vector<int> vct_two(4);
	TESTED_NAMESPACE::Vector<int> vct_three;
	TESTED_NAMESPACE::Vector<int> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	printSize(vct);
	printSize(vct_two);

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	printSize(vct);
	printSize(vct_two);
	printSize(vct_three);
	printSize(vct_four);

	vct_four.assign(6, 84);
	printSize(vct_four);

	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	printSize(vct);
	printSize(vct_two);

	return (0);
}