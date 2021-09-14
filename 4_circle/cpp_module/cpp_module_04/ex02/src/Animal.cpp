#include "Animal.hpp"

Animal::Animal(void): type("default"){
	std::cout << "Default Animal Constructor called" << std::endl;
}

Animal::Animal(const std::string type) : type(type){
	std::cout << this->type << " Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal &other){
	*this = other;
}

Animal &Animal::operator=(const Animal &other){
	if (this != &other)
		this->type = other.type;
	std::cout << this->type << " Assignation Constructor called" << std::endl;
	return (*this);
}

Animal::~Animal(void){
	std::cout << this->type << " Animal Destructor called" << std::endl;
}

std::string	Animal::getType(void) const{
	return (this->type);
}
