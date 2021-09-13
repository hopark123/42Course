#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain{
public:
	Brain(void);
	Brain(const Brain &other);
	Brain	&operator=(const Brain &other);
	virtual ~Brain(void);

	std::string	const getIdea(int index) const;
private:
	std::string IdeasNow[100];
};

#endif