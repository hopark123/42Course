#include "WrongCat.hpp"

WrongCat::WrongCat(void) : Animal("WrongCat"){
	std::cout << "Default WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other){
	*this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other){
	this->type = other.type;
	std::cout << this->type << " Assignation Constructor called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void){
	std::cout << "Destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const{
	std::cout << "WrongCatttttt!!!!" << std::endl;
}
