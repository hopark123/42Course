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
	void	setIdea(int index, std::string idea);
private:
	std::string Ideas[100];
};

#endif