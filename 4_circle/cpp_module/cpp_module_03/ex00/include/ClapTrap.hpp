#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap(void);

	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap &operator=(const ClapTrap &other);
private:
	std::string name;
	unsigned int	Hit_Points;
	unsigned int	Energy_Points;
	unsigned int	Attack_Damages;
};

#endif
