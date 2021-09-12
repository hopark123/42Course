#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public :
	DiamondTrap(void);
	DiamondTrap(const std::string &name_);
	DiamondTrap(DiamondTrap &other);
	~DiamondTrap(void);

	DiamondTrap &operator=(const DiamondTrap &other);

	void	whoAmI(void);
private :
	std::string	name;

};

#endif