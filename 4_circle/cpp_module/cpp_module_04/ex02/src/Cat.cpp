#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "Cat Constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &other){
	*this = other;
}

Cat &Cat::operator=(const Cat &other){
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain(*other.getBrain());
		std::cout << this->type << " Assignation Constructor called" << std::endl;
	}
	return (*this);
}

Cat::~Cat(void){
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound(void) const{
	std::cout << "Catttttt!!!!" << std::endl;
}

Brain	*Cat::getBrain(void) const{
	return (this->brain);
}

void	Cat::setIdea(int index, std::string idea){
	this->brain->setIdea(index, idea);
}

std::string	Cat::getIdea(int index) const{
	std::cout << "myIdea : "<<this->brain->getIdea(index) << std::endl;
	return (this->brain->getIdea(index));
}