#include "Array.hpp"

int main(void)
{
	Array<std::string> array1(5);

	for (int i = 0; i < 5; i++)
		array1[i] = std::string("Hello" + std::to_string(i));
	for (int i = 0; i < 5; i++)
		std::cout << array1[i] << std::endl;


	Array<std::string> array2;
	array2 = array1;
	array2[2] = "aa";
	for (int i = 0; i < 5; i++)
		std::cout << "arrary1 : " << array1[i] << std::endl;
	std::cout << "----------" << std::endl;
	for (int i = 0; i < 5; i++)
		std::cout << "arrary2 : " << array2[i] << std::endl;
	std::cout << "------out of range test-------" << std::endl;
	try {
		for (int i = 0; i < 8; i++)
			std::cout << "arrary2 : " << array2[i] << std::endl;
	}
	catch (const std::exception &e){
		std::cout << "** excpection **" <<  e.what() << std::endl;
	}
	Array<const int> arr(4);
	
	std::cout << arr[2] << std::endl;
	return (0);
}