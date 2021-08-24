#include "Zombie.hpp"

int	main(void)
{
	int			N = 7;
	Zombie *Horder_Zombies;
	Horder_Zombies = zombieHorde(N, "horde");

	for (int i = 0; i < N; i++)
		Horder_Zombies[i].announce();
	delete [] Horder_Zombies;
	return (0);
}