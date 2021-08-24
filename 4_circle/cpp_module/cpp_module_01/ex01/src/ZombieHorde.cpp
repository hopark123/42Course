#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*Horder_Zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
		Horder_Zombies[i].name = name;
	
	return (Horder_Zombies);
}