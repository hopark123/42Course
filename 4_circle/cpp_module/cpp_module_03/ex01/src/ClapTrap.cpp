# include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : name("Default"), Hit_Points(10), Energy_Points(10), Attack_Damages(0){
	std::cout << "ClapTrap : " << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name(name), Hit_Points(10), Energy_Points(10), Attack_Damages(0){
	std::cout << "ClapTrap : " << this->name << " Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other){
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other){
	this->name = other.name;
	this->Hit_Points = other.Hit_Points;
	this->Energy_Points = other.Energy_Points;
	this->Attack_Damages = other.Attack_Damages;
	std::cout << "ClapTrap : " << this->name << " Assignation Constructor called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void){
	std::cout << "ClapTrap : " << "Destructor called" << std::endl;
}

void	ClapTrap::attack(std::string const &target){
		std::cout << "ClapTrap : " << this->name << " attacks " << target << ", causing " << this->Attack_Damages << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (Hit_Points >= amount)
	{
		Hit_Points -= amount;
		std::cout << "ClapTrap : " << this->name << " was taken "  << amount << " Hit_Point ["<< this->Hit_Points <<"]"<<std::endl;
	}
	else
	{
		Hit_Points = 0;
		std::cout << "ClapTrap : " << this->name << " was attacked and Hit_Point is zero" << " ["<< this->Hit_Points <<"]"<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	Hit_Points += amount;
	std::cout << "ClapTrap : " << this->name << " is reparing HitPoint" << " ["<< this->Hit_Points <<"]" << std::endl;
}

unsigned int	ClapTrap::getHitPoints(void) const{
	return (this->Hit_Points);
}

unsigned int	ClapTrap::getEnergyPoints(void) const{
	return (this->Energy_Points);
}

unsigned int	ClapTrap::getAttackDamages(void) const{
	return (this->Attack_Damages);
}

void	ClapTrap::setHitPoints(unsigned int Hit_Points){
	this->Hit_Points = Hit_Points;
}

void	ClapTrap::setEnergyPoints(unsigned int Energy_Points){
	this->Energy_Points = Energy_Points;
}

void	ClapTrap::setAttackDamages(unsigned int Attack_Damages){
	this->Attack_Damages = Attack_Damages;
}