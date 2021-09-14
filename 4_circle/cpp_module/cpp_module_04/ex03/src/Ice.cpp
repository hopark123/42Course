#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
}

Ice::Ice(const Ice &other){
	*this = other;
}

Ice	&Ice::operator=(const Ice&other){
	if (this != &other){
		this->type = other.getType();
	}
	return (*this);
}

Ice::~Ice(void){
}

AMateria *Ice::clone(void) const{
	Ice	*clone = new Ice;
	return (clone);
}

void	Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}