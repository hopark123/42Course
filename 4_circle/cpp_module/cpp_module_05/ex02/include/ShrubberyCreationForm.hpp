#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form{
public :
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm(void);

	void	do_execute(const Bureaucrat &exector) const;
};


#define ASCII_TREE "\
   *    *  ()   *   *\n\
*        * /\\         *\n\
      *   /i\\\\    *  *\n\
    *     o/\\\\  *      *\n\
 *       ///\\i\\    *\n\
     *   /*/o\\\\  *    *\n\
   *    /i//\\*\\      *\n\
        /o/*\\\\i\\   *\n\
  *    //i//o\\\\\\\\     *\n\
    * /*////\\\\\\\\i\\*\n\
 *    //o//i\\\\*\\\\\\   *\n\
   * /i///*/\\\\\\\\\\o\\   *\n\
  *    *   ||     *\n"
#endif