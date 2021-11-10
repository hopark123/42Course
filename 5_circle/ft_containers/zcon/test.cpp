/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 22:07:22 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/07 22:38:29 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "common.hpp"
#include <list>

#define TESTED_TYPE int
typedef std::list<TESTED_TYPE> container_type;
#define t_stack_ TESTED_NAMESPACE::stack<TESTED_TYPE, container_type>

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}

int		main(void)
{
	container_type	ctnr;

	ctnr.push_back(21);
	ctnr.push_back(42);
	ctnr.push_back(1337);
	ctnr.push_back(19);
	ctnr.push_back(0);
	ctnr.push_back(183792);

	t_stack_	stck(ctnr);
	t_stack_	stck2(ctnr);

	cmp(stck, stck);  // 0
	cmp(stck, stck2); // 1

	stck2.push(60);
	stck2.push(61);
	stck2.push(62);

	cmp(stck, stck2); // 2
	cmp(stck2, stck); // 3

	stck.push(42);

	cmp(stck, stck2); // 4
	cmp(stck2, stck); // 5

	stck.push(100);

	cmp(stck, stck2); // 6
	cmp(stck2, stck); // 7
	return (0);
}

/*
#include "vector.hpp"
#include "stack.hpp"
#include "map.hpp"
#include <vector>

int main(void) {
	
	ft::map<int, ft::vector<int> > ftMap1;
	ft::vector<int> ftVector1;
	ft::vector<int> ftVector2;
	ft::vector<int> ftVector3;
	ft::vector<int> ftVector4;
	ft::vector<int> ftVector5;
	ft::vector<int> ftVector6;
	ft::vector<int> ftVector7;
	ft::vector<int> ftVector8;
	ft::vector<int> ftVector9;

	ftMap1.insert(ft::pair<int, ft::vector<int> >(4, ftVector4));
	ftMap1.insert(ft::pair<int, ft::vector<int> >(6, ftVector6));
	ftMap1.insert(ft::pair<int, ft::vector<int> >(8, ftVector8));
	ftMap1.insert(ft::pair<int, ft::vector<int> >(3, ftVector3));
	ftMap1.insert(ft::pair<int, ft::vector<int> >(7, ftVector7));
	ftMap1.insert(ft::pair<int, ft::vector<int> >(5, ftVector5));
	ftMap1.insert(ft::pair<int, ft::vector<int> >(2, ftVector2));
	ftMap1.insert(ft::pair<int, ft::vector<int> >(9, ftVector9));
	ftMap1.insert(ft::pair<int, ft::vector<int> >(1, ftVector1));

	std::cout << ftMap1[1].capacity() << std::endl;

	ftMap1[1].insert(ftMap1[1].begin(), 42);
	ftMap1[1].insert(ftMap1[1].end(), 84);

	ftMap1[7].insert(ftMap1[7].begin(), 1);
	ftMap1[7].insert(++ftMap1[7].begin(), 2);
	ftMap1[7].insert(ftMap1[7].begin(), 3);
	ftMap1[7].insert(++(++(++ftMap1[7].begin())), 9);

	ft::map<int, ft::vector<int> > ftMap2(ftMap1);
	
	ft::map<int, ft::vector<int> >::iterator fi1;
	ft::map<int, ft::vector<int> >::iterator fi2;
	
	ft::map<int, ft::vector<int> >::reverse_iterator fri1;
	ft::map<int, ft::vector<int> >::reverse_iterator fri2;
	

	std::cout << std::endl;
	fi1 = ftMap1.begin();
	fi2 = ftMap1.end();

	fri1 = ftMap2.rbegin();
	fri2 = ftMap2.rend();
	std::cout << "--- print ftMap1 elements ---\n";
	std::cout << "size     = " << ftMap1.size() << std::endl;
	std::cout << "max_size = " << ftMap1.max_size() << std::endl;
	std::cout << "		vector max_size = " << fi1->second.max_size() << std::endl;
	for (; fi1 != fi2; fi1++) {
		std::cout << "		--- print [" << fi1->first << "] ---\n";
		std::cout << "		cap      = " << fi1->second.capacity() << std::endl;
		std::cout << "		size     = " << fi1->second.size() << std::endl;
		std::cout << "		max_size = " << fi1->second.max_size() << std::endl;
		ft::vector<int>::iterator vb = fi1->second.begin();
		ft::vector<int>::iterator ve = fi1->second.end();
		for (;vb != ve; vb++) {
			std::cout << *vb << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "--- print ftMap2 elements ---\n";
	std::cout << "size     = " << ftMap2.size() << std::endl;
	std::cout << "max_size = " << ftMap2.max_size() << std::endl;
	std::cout << "		vector max_size = " << fi1->second.max_size() << std::endl;
	for (; fri1 != fri2; fri1++) {
		std::cout << "		--- print [" << fri1->first << "] ---\n";
		std::cout << "		cap      = " << fi1->second.capacity() << std::endl;
		std::cout << "		size     = " << fi1->second.size() << std::endl;
		ft::vector<int>::reverse_iterator vb = fri1->second.rbegin();
		ft::vector<int>::reverse_iterator ve = fri1->second.rend();
		for (;vb != ve; vb++) {
			std::cout << *vb << std::endl;
		}
	}

	
	ftMap1.erase(3);
	ftMap1.erase(1);
	ftMap1.erase(4);

	ftMap2[7].erase(++ftMap2[7].begin(), --ftMap2[7].end());

	std::cout << std::endl;
	fi1 = ftMap1.begin();
	fi2 = ftMap1.end();

	fri1 = ftMap2.rbegin();
	fri2 = ftMap2.rend();
	std::cout << "--- print ftMap1 elements ---\n";
	std::cout << "size     = " << ftMap1.size() << std::endl;
	std::cout << "max_size = " << ftMap1.max_size() << std::endl;
	std::cout << "		vector max_size = " << fi1->second.max_size() << std::endl;
	for (; fi1 != fi2; fi1++) {
		std::cout << "		--- print [" << fi1->first << "] ---\n";
		std::cout << "		cap      = " << fi1->second.capacity() << std::endl;
		std::cout << "		size     = " << fi1->second.size() << std::endl;
		ft::vector<int>::iterator vb = fi1->second.begin();
		ft::vector<int>::iterator ve = fi1->second.end();
		for (;vb != ve; vb++) {
			std::cout << *vb << std::endl;
		}
	}

	std::cout << std::endl;
	std::cout << "--- print ftMap2 elements ---\n";
	std::cout << "size     = " << ftMap2.size() << std::endl;
	std::cout << "max_size = " << ftMap2.max_size() << std::endl;
	std::cout << "		vector max_size = " << fi1->second.max_size() << std::endl;
	for (; fri1 != fri2; fri1++) {
		std::cout << "		--- print [" << fri1->first << "] ---\n";
		std::cout << "		cap      = " << fi1->second.capacity() << std::endl;
		std::cout << "		size     = " << fi1->second.size() << std::endl;
		ft::vector<int>::reverse_iterator vb = fri1->second.rbegin();
		ft::vector<int>::reverse_iterator ve = fri1->second.rend();
		for (;vb != ve; vb++) {
			std::cout << *vb << std::endl;
		}
	}


	std::cout << std::endl;
	ft::stack<std::string> fs;
	fs.push("hello");
	fs.push("world");

	ft::stack<std::string>::container_type::iterator sb;
	ft::stack<std::string>::container_type::iterator se;

	while (!fs.empty()) {
		std::cout << fs.top() << std::endl;
		fs.pop();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << std::endl;
	ft::vector<int> k2;
	k2.push_back(1);
	k2.push_back(2);
	k2.push_back(3);
	k2.push_back(4);
	k2.push_back(5);
	k2.insert(k2.begin() + 1, 5);
	k2.insert(k2.begin() + 1, 5, 10);
	for (ft::vector<int>::iterator it = k2.begin(); it < k2.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;


	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	ftMap1.showTree();
	
	std::cout << std::endl;
	std::cout << std::endl;
	ftMap2.showTree();

	
}

*/
