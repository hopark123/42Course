#include <iostream>
#include "vector.hpp"
#include "vector_Iterator.hpp"
#include "tree.hpp"
#include "map.hpp"
#include "ft_stl.hpp"
#include <vector>
#include <map>
#include <string.h>

// <template T>
// class less
// {
// 	if ()
// }
int main()
{
	int a = 3;
	int b = 4;
	ft::Pair<int, int> c = ft::make_pair<int, int>(a, b);
	ft::Pair<int, int> d = ft::make_pair<int, int>(5, 6);


	ft::Map<int, int> ma;
	std::map<int, int> f;

	ma.insert(c);
	ma.insert(d);

	ft::Map<int,int>::iterator it;
	it = ma.begin();
	it++;
	std::cout << it->first << std::endl;
	ma.clear();


// 	ft::Tree<int>::Node	node1(1);
// 	ft::Tree<int>::Node	node2(2);
// 	ft::Tree<int>::Node	node3(3);
// 	ft::Tree<int>::Node	node4(4);
// 	ft::Tree<int>::Node	node5(5);
// 	ft::Tree<int>::Node	node6(6);
// 	ft::Tree<int>::Node	node7(7);
// 	ft::Tree<int>::Node	node8(8);
// 	ft::Tree<int>::Node	node9(9);
// 	ft::Tree<int>::Node	node10(10);
// 	ft::Tree<int>::Node	node11(11);

// 	ft::Tree<int>::node_ptr ptr;
// 	// Tree->copy_node(&ptr, ptr, ptr);

// 	ptr = &node2;
// 	Tree->insert_node(&node5, &node3);
// 	Tree->insert_node(&node5, &node2);
// 	Tree->insert_node(&node5, &node7);
// 	Tree->insert_node(&node5, &node4);
// 	Tree->insert_node(&node5, &node1);
// 	Tree->insert_node(&node5, &node9);
// 	Tree->insert_node(&node5, &node6);
// 	Tree->insert_node(&node5, &node8);
// 	Tree->insert_node(&node5, &node10);
// 	Tree->insert_node(&node5, &node11);
// 	Tree->print(&node5);
// 	// std::cout << Tree->_root->_data <<std::endl;
// 	Tree->erase_node(&node5, &node4);
// 	std::cout << "\n" << std::endl;
// 	Tree->print(&node5);

}


