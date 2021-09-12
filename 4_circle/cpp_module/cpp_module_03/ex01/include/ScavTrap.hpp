#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public :
	ScavTrap(void);
	ScavTrap(const std::string name_);
	ScavTrap(ScavTrap &other);
	~ScavTrap(void);

	ScavTrap &operator=(const ScavTrap &other);
	
	void	attack(std::string const & target);
	void	guardGate(void);
private :

};

#endif