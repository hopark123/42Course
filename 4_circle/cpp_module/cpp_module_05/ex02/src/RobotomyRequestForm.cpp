#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : Form() {
	// std::cout << "RobotomyRequestForm Default constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", target, 72, 45){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other){
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	if (this != &other)
		this->Form::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){
	// std::cout << "RobotomyRequestForm Default Destructor" << std::endl;
}

void	RobotomyRequestForm::do_execute(const Bureaucrat &exactor) const{
	this->Form::execute(exactor);
	std::cout << "Makes some drilling noises ";
	if (rand() % 100 < 50)
		std::cout << this->getTarget() << " has been robotomized successfully\n";
	else
		std::cout << this->getTarget() << " Faillure\n";
}
