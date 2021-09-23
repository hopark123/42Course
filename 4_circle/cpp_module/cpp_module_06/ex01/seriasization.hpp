#ifndef SERIASIZATION_HPP
# define SERIASIZATION_HPP

# include <iostream>

typedef struct	s_Data{
	int num;
	std::string str;
}	Data;

uintptr_t	serialize(Data* ptr);
Data*	deserialize(uintptr_t raw);

#endif