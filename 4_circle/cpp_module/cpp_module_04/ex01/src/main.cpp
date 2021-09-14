#include "Animal.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	int i = 10;
	Animal *animals[10];

	for(int j = 0; j < i/2; j++)
		animals[j] = new Dog();
	for(int j = i/2; j < i; j++)
		animals[j] = new Cat();
	for(int j = 0; j < i; j++)
		animals[j]->makeSound();
	for(int j = 0; j < i; j++)
		delete animals[j];
	std::cout << "*******************" << std::endl;

	Dog dog;
	Dog dog2(dog);

	dog.setIdea(5, "5 Dog idea");
	dog2.setIdea(5, "change dog2 idea");
	dog.getIdea(5);
	dog2.getIdea(5);

	Cat cat;
	cat.setIdea(5, "5 Cat idea");
	dog.getIdea(5);
	cat.getIdea(5);
}
