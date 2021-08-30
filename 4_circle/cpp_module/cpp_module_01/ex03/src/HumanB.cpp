#include "HumanB.hpp"


HumanB::HumanB(std::string name) : name(name)
{
	return ;
}

HumanB::~HumanB(void)
{
}

void	HumanB::attack(void)
{
	std::cout << this->name << " attatck with his" << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}