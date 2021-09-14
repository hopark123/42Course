#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
}

Cure::Cure(const Cure &other){
	*this = other;
}

Cure	&Cure::operator=(const Cure &other){
	if (this != &other){
		this->type = other.getType();
	}
	return (*this);
}

Cure::~Cure(void){
}

AMateria *Cure::clone(void) const{
	Cure	*clone = new Cure;
	return (clone);
}

void	Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
