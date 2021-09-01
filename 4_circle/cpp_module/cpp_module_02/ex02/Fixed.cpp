#include "Fixed.hpp"

Fixed::Fixed(void) : value(0){
}

Fixed::Fixed(const int value){
	this->value = value << Fixed::fractional_bits;
}

Fixed::Fixed(const float value){
	this->value = (int)roundf(value * (1 << Fixed::fractional_bits));
}

Fixed::Fixed(const Fixed &other){
	*this = other;
}

Fixed::~Fixed(void){
}

Fixed &Fixed::operator=(const Fixed &other){
	this->value = other.value;
	return (*this);
}

bool Fixed::operator>(const Fixed &other) const{
	return (this->value > other.value);
}

bool Fixed::operator<(const Fixed &other) const{
	return (this->value < other.value);
}

bool Fixed::operator>=(const Fixed &other) const{
	return (this->value >= other.value);
}

bool Fixed::operator<=(const Fixed &other) const{
	return (this->value <= other.value);
}

bool Fixed::operator==(const Fixed &other) const{
	return (this->value == other.value);
}

bool Fixed::operator!=(const Fixed &other) const{
	return (this->value != other.value);
}

Fixed Fixed::operator+(const Fixed &other) const{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed &Fixed::operator++(void){
	this->value += 1;
	return (*this);
}

Fixed &Fixed::operator--(void){
	this->value -= 1;
	return (*this);
}

const Fixed Fixed::operator++(int){
	Fixed temp = (*this);

	this->value += 1;
	return (temp);
}

const Fixed Fixed::operator--(int){
	Fixed temp = (*this);

	this->value -= 1;
	return (temp);
}

int	Fixed::getRawBits(void) const{
	return (this->value);
}

void	Fixed::setRawBits(const int raw){
	this->value = raw;
}

float	Fixed::toFloat(void) const{
	return ((float)this->value / (float)(1 << Fixed::fractional_bits));
}

int		Fixed::toInt(void) const{
	return (this->value >> Fixed::fractional_bits);
}

Fixed &Fixed::min(Fixed &a, Fixed &b){
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
	if (a > b)
		return (a);
	return (b);
}
std::ostream &operator<<(std::ostream &ost, const Fixed &Value){
	ost << Value.toFloat();
	return (ost);
}