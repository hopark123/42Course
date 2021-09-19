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
  static Form *create(const std::string &target);
};


#define ASCII_TREE "\
   *    *  ()   *   *\
*        * /\\         *\
      *   /i\\\\    *  *\
    *     o/\\\\  *      *\
 *       ///\\i\\    *\
     *   /*/o\\\\  *    *\
   *    /i//\\*\\      *\
        /o/*\\\\i\\   *\
  *    //i//o\\\\\\\\     *\
    * /*////\\\\\\\\i\\*\
 *    //o//i\\\\*\\\\\\   *\
   * /i///*/\\\\\\\\\\o\\   *\
  *    *   ||     *"
#endif