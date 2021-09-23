#include "Convert.hpp"

Convert::Convert(){
	// std::cout << "Default Constructor" << std::endl;
}

Convert::Convert(std::string value) : _value(value){
	// std::cout << "value is " << value << std::endl;
}

Convert::Convert(const Convert &other){
	(*this) = other;
}

Convert const &Convert::operator=(const Convert &other){
	if (this != &other){
		this->_value = other._value;
	}
	return (*this);
}

Convert::~Convert(){
	// std::cout << "Default Destructor" << std::endl;
}

const char *Convert::ImpossibleException::what() const throw(){
	return ("impossible");
}

const char *Convert::NonDisplayableException::what() const throw(){
	return ("Non displayable");
}

char	Convert::toChar(void) const{
	int	c;

	try {
		c = std::stoi(this->_value);
		if (c < 0 || c > 255)
			throw Convert::ImpossibleException();
	}
	catch(...) {
		throw Convert::ImpossibleException();
	}
	if (!isprint(c))
	{
		throw Convert::NonDisplayableException();
	}
	return (static_cast<char>(c));
}

int	Convert::toInt(void) const{
	int	n;
	
	try {
		n = std::stoi(this->_value);
	}
	catch(...){
		throw Convert::ImpossibleException();
	}
	return (n);
}

float	Convert::toFloat(void) const{
	float f;

	try {
		f = std::stof(this->_value);
	}
	catch(...){
		throw Convert::ImpossibleException();
	}
	return (f);
}

double Convert::toDouble(void) const{
	double d;

	try {
		d = std::stod(this->_value);
	}
	catch(...){
		throw Convert::ImpossibleException();
	}
	return (d);
}
std::ostream &operator<<(std::ostream &os, const Convert &obj){
	os << "char : ";
	try {
		char	c = obj.toChar();
		os << "'" << c << "'" << std::endl;
	}
	catch (const std::exception &e){
		os << e.what() << std::endl;
	}

	os << "int : ";
	try {
		int	i = obj.toInt();
		os << i << std::endl;
	}
	catch (const std::exception &e){
		os << e.what() << std::endl;
	}
	os << "float : ";
	try {
		float f = obj.toFloat();
		os << f;
		if (!std::isnan(f) && (f - (int)f == 0))
			os << ".0";
		os << "f"<< std::endl;
	}
	catch (const std::exception &e){
		os << e.what() << std::endl;
	}
	os << "double : ";
	try {
		double d = obj.toDouble();
		os << d;
		if (!std::isnan(d) && (d - (int)d == 0))
			os << ".0";
		os << std::endl;
	}
	catch (const std::exception &e){
		os << e.what() << std::endl;
	}
	return (os);
}