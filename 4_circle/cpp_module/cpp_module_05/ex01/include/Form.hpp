#ifndef FORM_HPP
# define FORM_HPP


# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
public :
	Form(void);
	Form(const std::string name, const int signGrade, const int execGrade);
	Form(const Form &other);
	Form	&operator=(const Form &other);
	~Form(void);

	std::string	getName(void) const;
	int	getSignGrade(void) const;
	int	getExecGrade(void) const ;
	bool	isSigned(void) const;
	
	void	beSigned(Bureaucrat &bureaucrat);
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{		
		public:
			virtual const char *what() const throw();
	};

private :
	const std::string	_name;
	const int	_signGrade;
	const int	_execGrade;
	bool	_signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif