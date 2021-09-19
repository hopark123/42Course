#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat bure("BOSS", 2);

	std::cout << "------- test increase -------\n" << bure << std::endl;
	try
	{
		bure.increaseGrade();
		std::cout << bure << std::endl;
		bure.increaseGrade();
		std::cout << bure << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat bure2("SLAVE", 149);
	std::cout << "------- test decrease -------\n" << bure2 << std::endl;
	try
	{
		bure2.decreaseGrade();
		std::cout << bure2 << std::endl;
		bure2.decreaseGrade();
		std::cout << bure2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}