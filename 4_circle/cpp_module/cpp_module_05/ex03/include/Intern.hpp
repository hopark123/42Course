#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern {
public :
	Intern(void);
	Intern(const Intern &);
	Intern &operator=(const Intern &other);
	~Intern(void);

	Form *makeForm(std::string formName, std::string target);
	
	class NotExistFormException : public std::exception
	{
		public :
			virtual const char *what() const throw();
	};	
};

#endif