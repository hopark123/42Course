#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << "Default Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &other){
	*this = other;
}

Dog &Dog::operator=(const Dog &other){
	this->type = other.type;
	std::cout << this->type << " Assignation Constructor called" << std::endl;
	return (*this);
}

Dog::~Dog(void){
	std::cout << "Destructor called" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "Dogggggg!!!!" << std::endl;
}
