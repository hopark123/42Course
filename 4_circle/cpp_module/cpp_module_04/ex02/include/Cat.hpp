#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
public :
	Cat(void);
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);
	virtual ~Cat(void);

	void	makeSound(void) const;
	Brain	*getBrain(void) const;
	void	setIdea(int index, std::string idea);
	std::string	getIdea(int index) const;

private :
	Brain	*brain;
};

#endif