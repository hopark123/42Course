#include "Intern.hpp"

Intern::Intern(){
	// std::cout << "Intern Default constructor" << std::endl;
}

Intern::Intern(const Intern &other){
	*this = other;
}

Intern	&Intern::operator=(const Intern &){
	return (*this);
}

Intern::~Intern(){
	// std::cout << "Intern Default Destructor" << std::endl;
}

Form	*Intern::makeForm(std::string formName, std::string target){
	const std::string formlist[3] = {
		"PresidentialPardonForm", \
		"RobotomyRequestForm", \
		"ShrubberyCreationForm"
	};

	Form *(*form[3])(const std::string &target) = {
		&PresidentialPardonForm::create,
		&RobotomyRequestForm::create,
		&ShrubberyCreationForm::create,
	};

	for (int i = 0; i < 3; i++){
		if (formName == formlist[i])
		{
			std::cout << "Intern create " << formName << std::endl;
			return (form[i](target));
		}
	}
	throw Intern::NotExistFormException();
}

const char *Intern::NotExistFormException::what() const throw(){
	return ("Form does not exist");
}