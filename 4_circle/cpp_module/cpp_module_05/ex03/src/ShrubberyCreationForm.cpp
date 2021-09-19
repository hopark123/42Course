#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form() {
	// std::cout << "ShrubberyCreationForm Default constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", target, 145, 137){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : Form(other){
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	if (this != &other)
		this->Form::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void){
	// std::cout << "ShrubberyCreationForm Default Destructor" << std::endl;
}

void	ShrubberyCreationForm::do_execute(const Bureaucrat &exactor) const{
	this->Form::execute(exactor);
	std::ofstream file(this->getTarget() + "_shrubbery");

	if (file.is_open() == false)
		throw std::ofstream::failure("Could not open file " + this->getTarget() + "_shrubbery");
	file << ASCII_TREE;
}

Form	*ShrubberyCreationForm::create(const std::string &target){
	return (new ShrubberyCreationForm(target));
}
