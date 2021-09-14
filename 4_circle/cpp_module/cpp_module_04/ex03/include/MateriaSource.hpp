#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
class MateriaSource : public IMateriaSource{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource(void);

	void	learnMateria(AMateria *materia);
	AMateria	*createMateria(std::string const &type);
private:
	AMateria *materia[4];
};

#endif