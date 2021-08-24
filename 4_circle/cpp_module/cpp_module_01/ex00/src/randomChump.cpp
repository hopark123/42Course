#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	random_Chump = Zombie(name);

	random_Chump.announce();
	return ;
}