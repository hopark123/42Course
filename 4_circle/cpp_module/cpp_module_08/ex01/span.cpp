#include "span.hpp"

Span::Span() : _size(0){}

Span::Span(unsigned int	N) : _size(N){
}

Span::Span(const Span &other){
	(*this) = other;
}

Span	&Span::operator=(const Span &other){
	if (this != &other){
		this->_size = other._size;
		this->_value = other._value;
	}
	return (*this);
}
Span::~Span(){}

int	&Span::operator[](int i){
	if (i < 0 || i > static_cast<int>(this->_size))
		throw OutofRangeException();
	return (this->_value[i]);
}

void	Span::addNumber(int n){
	if (_value.size() >= this->_size)
		throw FullSpanException();
	_value.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator const &begin, std::vector<int>::iterator const &end){
	int size = std::distance(begin, end);
	if (_value.size() + size > this->_size)
		throw Span::FullSpanException();
	_value.insert(_value.end(), begin, end);
}

unsigned int	Span::longestSpan() const{
	if (this->_value.size() < 2)
		throw TooShortSpanException();
	
	std::vector<int> temp = this->_value;
	std::sort(temp.begin(), temp.end());
	return (temp.back() - temp.front());
}

unsigned int	Span::shortestSpan() const{
	if (this->_value.size() < 2)
		throw TooShortSpanException();
	
	std::vector<int> temp = this->_value;
	std::sort(temp.begin(), temp.end());
	std::vector<int>::iterator pt = temp.begin();
	std::vector<int>::iterator pt_n = ++temp.begin();
	long	min = LONG_MAX;
	while (pt_n != temp.end())
	{
		if (*pt_n - *pt < min)
			min = *pt_n - *pt;
		pt++;
		pt_n++;
	}
	return (static_cast<unsigned int>(min));
}