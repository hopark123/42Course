#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>

class	Zombie{
	public :
		std::string name;

		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void);
	private :
};

Zombie	*zombieHorde(int N, std::string name);

#endif