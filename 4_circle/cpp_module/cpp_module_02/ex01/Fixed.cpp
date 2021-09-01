#include "Fixed.hpp"

Fixed::Fixed(void) : value(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value){
	this->value = value << Fixed::fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value){
	this->value = (int)roundf(value * (1 << Fixed::fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Assignation operator called" << std::endl;
	this->value = other.value;
	return (*this);
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(const int raw){
	std::cout << "setRawBits called" << std::endl;
	this->value = raw;
}

float	Fixed::toFloat(void) const{
	return ((float)this->value / (float)(1 << Fixed::fractional_bits));
}

int		Fixed::toInt(void) const{
	return (this->value >> Fixed::fractional_bits);
}

std::ostream &operator<<(std::ostream &ost, const Fixed &Value){
	ost << Value.toFloat();
	return (ost);
}
