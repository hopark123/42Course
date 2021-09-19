#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

	Intern Intern;
	Form *form;
	std::cout << "\n-------------------ExistForm-------------------" << std::endl;
	form = Intern.makeForm("PresidentialPardonForm", "target");
	test_form(*form, Boss, Slave);
	delete form;

	std::cout << "\n-------------------NotExistForm-------------------" << std::endl;

	try
	{
		form = Intern.makeForm("NotExistForm", "target");
		test_form(*form, Boss, Slave);
		delete form;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}