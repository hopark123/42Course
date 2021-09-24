#include "iter.hpp"
#include <iostream>

template<typename T>
void	print_arry(T arry[], int size){
	for (int i = 0; i < size ; i++)
	{
		std::cout << arry[i] << std::endl;
	}
}

void	increase(int &num){
	num++;
}

void	star(std::string &str){
	str = '*' + str + '*';
}
int	main(void){
	std::cout << "---------int---------" << std::endl;
	int arry[] = {-1, 2, 3 , 4};
	iter<int>(arry, 4, &increase);
	print_arry(arry, 4);

	std::cout << "---------string---------" << std::endl;
	std::string str[] = {"a", "b", "c", "d"};
	iter<std::string>(str, 4, &star);
	print_arry(str, 4);

}