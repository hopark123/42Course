#include "Zombie.hpp"
#include <cstdlib>

const std::string	RAND_NAME[] = {
	"Tank" ,
	"Witch" ,
	"Smoker" ,
	"Hunter" ,
	"Boomer" ,
};

int		main(void)
{
	Zombie	stack_Zombie = Zombie("Stack_Zombie");
	Zombie	*heap_Zombie = newZombie("Heap_Zombie");
	
	stack_Zombie.announce();
	heap_Zombie->announce();
	delete heap_Zombie;

	for (int i = 0; i < 5; i ++)
		randomChump(RAND_NAME[rand() % 5]);
}