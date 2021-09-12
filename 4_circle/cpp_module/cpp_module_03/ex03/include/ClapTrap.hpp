#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(const std::string &name_);
	ClapTrap(const ClapTrap &other);
	~ClapTrap(void);

	void	attack(std::string const & target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamages(void) const;
	void	setHitPoints(unsigned int Hit_Points);
	void	setEnergyPoints(unsigned int EnergyPoints);
	void	setAttackDamages(unsigned int Attaack_Damages);
	std::string		getName(void) const;
	ClapTrap &operator=(const ClapTrap &other);

protected:
	std::string	name;
	unsigned int	Hit_Points;
	unsigned int	Energy_Points;
	unsigned int	Attack_Damages;
};

#endif
