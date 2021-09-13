#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Animal.hpp"

class	WrongCat : public Animal
{
public :
	WrongCat(void);
	WrongCat(const WrongCat &other);
	WrongCat &operator=(const WrongCat &other);
	virtual ~WrongCat(void);

	void makeSound(void) const;
private :
};

#endif