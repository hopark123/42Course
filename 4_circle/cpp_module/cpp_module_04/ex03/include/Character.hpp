#ifndef CHARACTER_CPP
# define CHARACTER_CPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter{
public:
	Character(void);
	Character(std::string name);
	Character(const	Character &other);
	Character &operator=(const Character &other);

	~Character(void);

	std::string	const &getName() const;
	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter &target);
private:
	std::string	name;
	AMateria	*materia[4];
};

#endif