#ifndef FORM_HPP
# define FORM_HPP


# include <iostream>
# include <fstream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
public :
	Form(void);
	Form(const std::string name, std::string target, const int signGrade, const int execGrade);
	Form(const Form &other);
	Form	&operator=(const Form &other);
	virtual ~Form(void);

	std::string	getName(void) const;
	std::string	getTarget(void) const;
	int	getSignGrade(void) const;
	int	getExecGrade(void) const ;
	bool	isSigned(void) const;
	void	beSigned(Bureaucrat &bureaucrat);
	void	execute(const Bureaucrat &exector) const;
	virtual void	do_execute(const Bureaucrat &exector) const = 0;
	class GradeTooHighException : public std::exception{
		public:
			virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception{
		public:
			virtual const char *what() const throw();
	};
	class notSignedException : public std::exception{
		public :
			virtual const char *what() const throw();
	};
private :
	const std::string	_name;
	const std::string	_target;
	const int	_signGrade;
	const int	_execGrade;
	bool	_signed;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif