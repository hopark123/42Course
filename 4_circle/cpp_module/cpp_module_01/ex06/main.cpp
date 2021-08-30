#include "Karen.hpp"

int main(int ac, char *av[])
{
	Karen karen;

	if (ac != 2)
		std::cout << "wrong input" << std::endl;
	else
		karen.complain(av[1]);
	return (0);
}