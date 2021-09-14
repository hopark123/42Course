#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << "Dog Constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &other){
	*this = other;
}

Dog &Dog::operator=(const Dog &other){
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain(*other.getBrain());
		std::cout << this->type << " Assignation Constructor called" << std::endl;
	}
	return (*this);
}

Dog::~Dog(void){
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound(void) const{
	std::cout << "Dogggggg!!!!" << std::endl;
}

Brain	*Dog::getBrain(void) const{
	return (this->brain);
}

void	Dog::setIdea(int index, std::string idea){
	this->brain->setIdea(index, idea);
}

std::string	Dog::getIdea(int index) const{
	std::cout << "myIdea : "<<this->brain->getIdea(index) << std::endl;
	return (this->brain->getIdea(index));
}