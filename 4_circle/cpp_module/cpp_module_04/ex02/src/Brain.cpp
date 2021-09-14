#include "Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::Brain(const Brain &other){
	*this = other;
}

Brain &Brain::operator=(const Brain &other){
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->Ideas[i] = other.getIdea(i);
	}
	return (*this);
}

Brain::~Brain(void){
	std::cout << "Brain Destructor called" << std::endl;
}

std::string	const Brain::getIdea(int index) const{
	return (this->Ideas[index]);
}

void	Brain::setIdea(int index, std::string idea){
	this->Ideas[index] = idea;
}
