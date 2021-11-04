// #include "Vector.hpp"
#include <iostream>
#include "Vector.hpp"
#include <vector>
int main()
{
	// std::vector<int> A;

	// A.push_back(10);
	// A.push_back(11);
	// A.push_back(12);
	// A.push_back(13);
	// A.push_back(14);

	// std::vector<int>::iterator it;
	// std::vector<int>::const_iterator cit;

	// it = A.begin();
	// cit = A.begin();

	// it + 3 ;
	// std::cout << *(it + 3) << "\n+\n" << *(++it) << std::endl;
	// // it[3] += 3;
	// cit[3];
	// std::cout<< (it - cit) << std::endl;
	// // std::cout<< it[3] << std::endl;
	// std::cout<< cit[3] << std::endl;
	// ft::VectorIterator<int>	it;
	// ft::VectorIterator<>	it;
	std::vector<int> A;
	std::vector<int>::iterator it_A;
	std::vector<int>::iterator it_B;
	std::vector<int>::const_iterator cit_A;


	cit_A = A.begin();
	it_A = A.begin();

	ft::Vector<int> C;
	ft::Vector<int>::iterator it;
	ft::Vector<int>::const_iterator cit;

	

	C.push_back(3);
	C.push_back(1321312);
	C.pop_back();
	C.push_back(4);

	it = C.begin();
	std::cout << *it << "\n" << *(++it) << std::endl;



}


