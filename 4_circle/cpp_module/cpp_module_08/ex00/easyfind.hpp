#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <iterator>

class NotExistValueException : public std::exception {
public :
	const char *what() const throw(){
			return ("NotExistValue");
	}
};

template<class T>
typename T::iterator easyfind(T &container, int value){
	typename T::iterator ptr = std::find(container.begin(), container.end(), value);
	if (ptr == container.end())
		throw NotExistValueException();
	return (ptr);
};

#endif