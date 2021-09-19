#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class	Form;
class	Bureaucrat{
public :
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat const &operator=(const Bureaucrat &other);
	~Bureaucrat(void);

	std::string	getName(void) const;
	int	getGrade(void) const;

	void	increaseGrade(void);
	void	decreaseGrade(void);
	void	signForm(Form &form);
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
	int	_grade;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif