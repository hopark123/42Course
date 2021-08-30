#include "Karen.hpp"

int main()
{
	std::string arr[5] = {"DEBUG", "INFO", "WARNING", "ERROR", "wrong"};
	Karen karen;

	for (int i = 0; i < 5; i++)
		karen.complain(arr[i]);
	return (0);
}