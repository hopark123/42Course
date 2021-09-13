#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("default"){
	std::cout << "Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string type) : type(type){
	std::cout << this->type << " Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other){
	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other){
	this->type = other.type;
	std::cout << this->type << " Assignation Constructor called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "Destructor called" << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "WWWWWrongAnimal!!!!!!" << std::endl;
}
