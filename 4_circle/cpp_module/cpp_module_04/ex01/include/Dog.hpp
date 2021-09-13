#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
public :
	Dog(void);
	Dog(const Dog &other);
	Dog	&operator=(const Dog &other);
	virtual ~Dog(void);

	void	makeSound(void) const;
	Brain	getBrain(void) const;
private :
	Brain	*brain;
};

#endif