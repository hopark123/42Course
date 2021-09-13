#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP


# include <iostream>

class	WrongAnimal
{
public :
	WrongAnimal(void);
	WrongAnimal(const std::string type);
	WrongAnimal(const WrongAnimal &other);
	WrongAnimal &operator=(const WrongAnimal &other);
	virtual	~WrongAnimal(void);

	std::string getType(void) const;
	void makeSound(void) const;
protected :
	std::string	type;
};

#endif