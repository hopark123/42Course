#include <iostream>

int	main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "str " << &string << " " << string << std::endl;
	std::cout << "ptr " << stringPTR << " " << *stringPTR << std::endl;
	std::cout << "ref " << &stringREF << " " << stringREF << std::endl;
}