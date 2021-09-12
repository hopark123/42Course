#include "ScavTrap.hpp"

int main()
{
	ScavTrap GREEN;
	ScavTrap Black("black");
	ScavTrap White(Black);

	std::cout << "--------constructor-----" << std::endl;
	Black.beRepaired(30);
	Black.attack("Red");
	Black.takeDamage(40);
	Black.guardGate();
}