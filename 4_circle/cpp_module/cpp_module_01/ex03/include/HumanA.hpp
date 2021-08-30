#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{
	public :
		HumanA(std::string name, Weapon &wepon);
		~HumanA(void);

		void	attack(void);
	private :
		HumanA(void);
		std::string	name;
		Weapon	&weapon;
		
};

#endif