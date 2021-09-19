#include "FragTrap.hpp"

int main()
{
	FragTrap GREEN;
	FragTrap Black("black");
	FragTrap White(Black);

	std::cout << "--------constructor-----" << std::endl;
	Black.beRepaired(30);
	Black.attack("Red");
	Black.takeDamage(40);
	Black.highFivesGuys();
}