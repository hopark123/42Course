#include "Animal.hpp"

Animal::Animal(void): type("default"){
	std::cout << "Default Constructor called" << std::endl;
}

Animal::Animal(const std::string type) : type(type){
	std::cout << this->type << " Constructor called" << std::endl;
}

Animal::Animal(const Animal &other){
	*this = other;
}

Animal &Animal::operator=(const Animal &other){
	this->type = other.type;
	std::cout << this->type << " Assignation Constructor called" << std::endl;
	return (*this);
}

Animal::~Animal(void){
	std::cout << "Destructor called" << std::endl;
}

std::string	Animal::getType(void) const{
	return (this->type);
}

void	Animal::makeSound(void) const{
	std::cout << "AAAAAAnimal!!!!!!" << std::endl;
}
