#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string.h>

class	Contact
{
	public:
		void	add(void);
		void	del(void);
		void	search(int cnt);
		void	print(void);
		void	print_short(int index);
	private:
		std::string		first_name;
		std::string		last_name;
		std::string		nickname;
		std::string		phone_number;
		std::string		darkest_secret;
};

#endif