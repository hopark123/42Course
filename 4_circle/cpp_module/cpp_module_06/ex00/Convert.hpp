#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <cmath>
class Convert{
public :
	Convert();
	Convert(std::string value);
	Convert(const Convert &other);
	Convert	const &operator=(const Convert &other);
	~Convert();

	class ImpossibleException : public std::exception{
		public :
			const char *what() const throw();
	};

	class NonDisplayableException : public std::exception{
		public :
			const char *what() const throw();
	};

	const std::string	getValue(void) const;
	char	toChar(void) const;
	int		toInt(void) const;
	float	toFloat(void) const;
	double	toDouble(void) const;

private :
	std::string _value;
};

std::ostream &operator<<(std::ostream &os, const Convert &obj);

#endif