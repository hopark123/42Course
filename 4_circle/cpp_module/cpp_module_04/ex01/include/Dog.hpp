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
	~Dog(void);

	void	makeSound(void) const;
	Brain	*getBrain(void) const;
	void	setIdea(int index, std::string idea);
	std::string	getIdea(int index) const;
private :
	Brain	*brain;
};

#endif