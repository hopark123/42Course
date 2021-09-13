#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "Default Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &other){
	*this = other;
}

Cat &Cat::operator=(const Cat &other){
	this->type = other.type;
	std::cout << this->type << " Assignation Constructor called" << std::endl;
	return (*this);
}

Cat::~Cat(void){
	std::cout << "Destructor called" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "Catttttt!!!!" << std::endl;
}
