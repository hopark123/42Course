#include "HumanA.hpp"

HumanA::~HumanA(void)
{
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	return ;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attatck with his" << this->weapon.getType() << std::endl;
}