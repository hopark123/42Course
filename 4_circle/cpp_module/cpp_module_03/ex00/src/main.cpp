#include "ClapTrap.hpp"

int main()
{
	ClapTrap GREEN;
	ClapTrap Black("black");
	ClapTrap White(Black);

	std::cout << "--------constructor-----" << std::endl;
	Black.beRepaired(30);
	Black.attack("Red");
	Black.takeDamage(20);
}