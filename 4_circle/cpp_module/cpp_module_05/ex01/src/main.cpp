#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat hopark("hopark", 10);
	std::cout << "start " << hopark << std::endl;
	try
	{
		hopark.increaseGrade();
		std::cout << hopark << std::endl;
		hopark.increaseGrade();
		std::cout << hopark << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form formA("a", 10, 10);
	Form formB("b", 7, 10);
	std::cout << "formA : " << formA << std::endl;
	std::cout << "formB : " << formB << std::endl;
	hopark.signForm(formA);
	hopark.signForm(formB);
	return 0;
}