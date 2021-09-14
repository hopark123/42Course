#include "Animal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	// const Animal k;
	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	j->makeSound();
	i->makeSound();
	delete i;
	delete j;
	return 0;
}
