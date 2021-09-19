#include "Form.hpp"

Form::Form(void) : _name("default"), _signGrade(1), _execGrade(1), _signed(false){
	std::cout << "Form Default constructor" << std::endl;
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false) {
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _signGrade(other._signGrade), _execGrade(other._execGrade), _signed(false){
	*this = other;
}

Form	&Form::operator=(const Form &other){
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

Form::~Form(void){
	// std::cout << "Form Default Destructor" << std::endl;
}

std::string	Form::getName(void) const {
	return (this->_name);
}

int	Form::getSignGrade(void) const{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const{
	return (this->_execGrade);
}

bool	Form::isSigned(void) const{
	return (this->_signed);
}

void	Form::beSigned(Bureaucrat &bureaucrat){
	if (bureaucrat.getGrade() > this->_signGrade || bureaucrat.getGrade() > this->_execGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade to High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade to Low [Form]");
}

std::ostream &operator<<(std::ostream&os, const Form &form){
	os << "[ Name : " << form.getName() \
		<< " | Sign_grade : " << form.getSignGrade() \
		<< " | Excute_grade : " << form.getExecGrade();
	if (form.isSigned())
		os << " | signed ]";
	else
		os << " | unsigned ]";
	return os;
}