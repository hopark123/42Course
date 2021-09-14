#include "Character.hpp"

Character::Character() : name("default"){
	for(int i = 0; i < 4; i++)
		materia[i] = NULL;
}

Character::Character(std::string name) : name(name){
	for(int i = 0; i < 4; i++)
		materia[i] = NULL;
}

Character::Character(const Character &other){
	*this = other;
}

Character	&Character::operator=(const Character &other){
	if (this != &other)
		for(int i = 0; i < 4; i++)
			this->materia[i] = other.materia[i];
	return (*this);
}

Character::~Character(){
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] != NULL)
			delete this->materia[i];
	}
}

std::string	const	&Character::getName() const{
	return (this->name);
}

void	Character::equip(AMateria *m){
	for(int i = 0; i < 4; i++)
	{
		if (this->materia[i] == NULL)
		{
			this->materia[i] = m;
			break;
		}
	}
}

void	Character::unequip(int idx){
	if (idx >= 0 && idx < 4)
		this->materia[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target){
	if (idx >= 0 && idx < 4 && this->materia[idx] != NULL)
		this->materia[idx]->use(target);
}