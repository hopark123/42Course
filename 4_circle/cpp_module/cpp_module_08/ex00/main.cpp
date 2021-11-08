#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void){
	std::cout << "****** vector test ******" << std::endl;;
	std::vector<int> myVect;
	for (int i = 0; i < 10 ; i++){
		myVect.push_back(i);
	}
	for (std::vector<int>::iterator ptr = myVect.begin(); ptr != myVect.end(); ++ptr){
		std::cout << *ptr << ' ';
	}
	std::cout << std::endl;
	try{
		std::cout << "find 11! : " << *easyfind< std::vector<int> >(myVect, 11) << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "****** list test ******" << std::endl;
	std::list<int> myList;
	for (int i = 0; i < 10; i++){
		myList.push_back(2 * i);
	}
	for (std::list<int>::iterator ptr = myList.begin(); ptr != myList.end(); ++ptr){
		std::cout << *ptr << ' ';
	}
	std::cout << std::endl;
	try{
		std::cout << "find 8! : " << *easyfind< std::list<int> >(myList, 8) << std::endl;
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}


int a;
int b = 3; b(3);
int c(b);
