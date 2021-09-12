#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap GREEN;
	DiamondTrap Black("black");
	DiamondTrap White(Black);

	std::cout << "--------constructor-----" << std::endl;
	Black.beRepaired(30);
	Black.attack("Red");
	Black.takeDamage(40);
	Black.guardGate();
	Black.highFivesGuys();
	Black.whoAmI();
	GREEN.whoAmI();
}