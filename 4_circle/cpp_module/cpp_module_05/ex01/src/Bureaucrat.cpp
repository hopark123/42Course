# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
	std::cout << "Bureaucrat Default constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
	std::cout << "Bureaucrat "<< name << " constructor" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other){
	*this = other;
}

Bureaucrat	const &Bureaucrat::operator=(const Bureaucrat &other){
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void){
	// std::cout << "Bureaucrat Default Destructor" << std::endl;
}

std::string	Bureaucrat::getName(void) const{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

void	Bureaucrat::increaseGrade(void){
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decreaseGrade(void){
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat Grade to High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat Grade to Low");
}

void	Bureaucrat::signForm(Form &form){
	try
	{
		std::cout << *this << " >>> signs " << form << std::endl;
		form.beSigned(*this);
	}
	catch (const std::exception &e)
	{
		std::cout << *this << " >>> can't sign " << form << " * because " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &bureaucrat){
	os << bureaucrat.getName() << ", Bureaucrat Grade : " << bureaucrat.getGrade();
	return os;
}