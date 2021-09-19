#include <iostream>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void test_form(Form &form, Bureaucrat &correct, Bureaucrat &wrong)
{
	wrong.signForm(form);
	wrong.executeForm(form);
	correct.signForm(form);
	correct.executeForm(form);
}

int main()
{
	Bureaucrat Boss("BOSS", 1);
	Bureaucrat Slave("SLAVE", 150);

	ShrubberyCreationForm form1("test.S");
	RobotomyRequestForm form2("test.R");
	PresidentialPardonForm form3("test.P");
	std::cout << "\n-------------------ShrubberyCreationForm-------------------" << std::endl;
	test_form(form1, Boss, Slave);
	std::cout << "\n-------------------RobotomyRequestForm-------------------" << std::endl;
	test_form(form2, Boss, Slave);
	std::cout << "\n-------------------PresidentialPardonForm-------------------" << std::endl;
	test_form(form3, Boss, Slave);

	return 0;
}