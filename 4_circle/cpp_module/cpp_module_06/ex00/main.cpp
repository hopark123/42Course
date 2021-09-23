#include <iostream>
#include "Convert.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong Number of arguments" << std::endl;
		return (1);
	}
	Convert conv(argv[1]);
	std::cout << conv;
	return (0);
}