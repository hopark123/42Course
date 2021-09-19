#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : Form() {
	// std::cout << "PresidentialPardonForm Default constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form("PresidentialPardonForm", target, 25, 5){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other){
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	if (this != &other)
		this->Form::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void){
	// std::cout << "PresidentialPardonForm Default Destructor" << std::endl;
}

void	PresidentialPardonForm::do_execute(const Bureaucrat &exactor) const{
	this->Form::execute(exactor);
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
