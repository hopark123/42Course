#include "Brain.hpp"

Brain::Brain(void)
{
	const std::string ideas[] = {
		"🥱",
		"🥵",
		"😢",
		"😱",
		"🥶",
		"🤯",
		"🤩",
		"🥰",
		"🥳",
		"🥴",
		"🤤",
		"🤢",
		"🤧",
		"🤮",
		"🤡",
		"🤠",
		"🤥",
		"🤤",
	};

	std::cout << "Constructor Brain:";
	for (int i = 0; i < 100; ++i)
	{
		this->IdeasNow[i] = ideas[rand() % (sizeof(ideas) / sizeof(std::string))];
		std::cout << " " << this->IdeasNow[i];
	}
	std::cout << std::endl;
}

Brain::Brain(const Brain &other){
	*this = other;
}

Brain &Brain::operator=(const Brain &other){
	if (this != &other)
	{
		for (int i = 0; i < 100; ++i)
			this->IdeasNow[i] = other.getIdea(i);
	}
	return (*this);
}

Brain::~Brain(void){
	std::cout << "Destructor called" << std::endl;
}

std::string	const Brain::getIdea(int index) const{
	return (this->IdeasNow[index]);
}