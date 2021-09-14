#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void){
	for(int i = 0; i < 4; i++)
		this->materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other){
	*this = other;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &other){
	if (this != &other)
		for(int i = 0; i < 4; i++)
			this->materia[i] = other.materia[i]->clone();
	return (*this);
};

MateriaSource::~MateriaSource(void){
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] != NULL)
			delete this->materia[i];
	}
}

void	MateriaSource::learnMateria(AMateria *materia){
	for(int i = 0; i < 4; i++)
	{
		if (this->materia[i] == NULL)
		{
			this->materia[i] = materia;
			break;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type){
	for (int i = 0; i < 4; i++)
	{
		if (this->materia[i] != NULL && this->materia[i]->getType() == type)
			return (this->materia[i]->clone());
	}
	return 0;
}