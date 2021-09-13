#ifndef ANIMAL_HPP
# define ANIMAL_HPP


# include <iostream>

class	Animal
{
public :
	Animal(void);
	Animal(const std::string type);
	Animal(const Animal &other);
	Animal &operator=(const Animal &other);
	virtual ~Animal(void);

	std::string getType(void) const;
	virtual void makeSound(void) const;
protected :
	std::string	type;
};

#endif