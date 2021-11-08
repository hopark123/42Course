#ifndef _VECTOR_ITERATOR_
# define _VECTOR_ITERATOR_

#include <iostream>
#include "ft_stl.hpp"
#include "Vector.hpp"

namespace ft {
template<typename T>
class VectorIterator
{
	public :
		typedef T					valuetype;
		typedef T&					reference;
		typedef T*					pointer;
		typedef const T&			const_reference;
		typedef const T*			const_pointer;
		typedef std::ptrdiff_t		difference_type;
	private :
		pointer						_p;
		typedef	VectorIterator<T>	_Self;
	public :
		VectorIterator() : _p(NULL) {}
		VectorIterator(pointer p) : _p(p) {}
		VectorIterator(_Self const &other) : _p(other._p) {}
		~VectorIterator() {}

		_Self const &operator=(const _Self &other){
			if (this != &other)
				this->_p = other._p;
			return (*this);
		}
		reference	&operator*(void){
			return (*(this->_p));
		}
		const_reference	&operator*(void) const{
			return (*(this->_p));
		}
		pointer		&operator->(void){
			return (this->_p);
		}
		const_pointer		&operator->(void) const{
			return (this->_p);
		}
		_Self &operator++(void){ // prefix increment
			++(this->_p);
			return (*this);
		}
		const _Self operator++(int){ // postfix increment
			_Self temp(this);
			++(this->_p);
			return (temp);
		}
		_Self &operator--(void){ // prefix decrement
			--(this->_p);
			return (*this);
		}
		const _Self operator--(int){ // postfix decrement
			_Self temp(*this);
			--(this->_p);
			return (temp);
		}
		_Self &operator+=(int value){
			(this->_p) += value;
			return (*this);
		}
		_Self &operator-=(int value){
			(this->_p) -= value;
			return (*this);
		}
		_Self operator+(int value) const{
			_Self temp(*this);
			temp += value;
			return (temp);
		}
		_Self operator-(int value) const{
			_Self temp(*this);
			temp -= value;
			return (temp);
		}
		reference &operator[](int value){
			return (*(this->_p + value));
		}
		const_reference &operator[](int value) const{
			return (*(this->_p + value));
		}
		difference_type operator-(_Self const &other) const{
			return (this->_p - other._p);
		}
		bool operator==(_Self const &other) const{
			return (this->_p == other._p);
		}
		bool operator!=(_Self const &other) const{
			return (this->_p != other._p);
		}
		bool operator<(_Self const &other) const{
			return (this->_p < other._p);
		}
		bool operator<=(_Self const &other) const{
			return (this->_p <= other._p);
		}
		bool operator>(_Self const &other) const{
			return (this->_p > other._p);
		}
		bool operator>=(_Self const &other) const{
			return (this->_p >= other._p);
		}
};

template<typename T>
class VectorRevIterator
{
	public :
		typedef T				valuetype;
		typedef T&				reference;
		typedef T*				pointer;
		typedef const T&		const_reference;
		typedef const T*		const_pointer;
		typedef std::ptrdiff_t	difference_type;
	private :
		pointer							_p;
		typedef	VectorRevIterator<T>	_Self;
	
	public :
		VectorRevIterator() : _p(NULL) {}
		VectorRevIterator(_Self const &other) : _p(other._p) {}
		~VectorRevIterator() {}

		_Self const &operator=(const _Self &other){
			if (this != &other)
				this->_p = other._p;
			return (*this);
		}
		reference	&operator*(void){
			return (*(this->_p));
		}
		const_reference	&operator*(void) const{
			return (*(this->_p));
		}
		pointer		&operator->(void){
			return (this->_p);
		}
		const_pointer		&operator->(void) const{
			return (this->_p);
		}
		_Self &operator++(void){ // prefix increment
			--(this->_p);
			return (*this);
		}
		const _Self operator++(int){ // postfix increment
			_Self temp(this);
			--(this->_p);
			return (temp);
		}
		_Self &operator--(void){ // prefix decrement
			++(this->_p);
			return (*this);
		}
		const _Self operator--(int){ // postfix decrement
			_Self temp(this);
			++(this->_p);
			return (temp);
		}
		_Self &operator+=(int value){
			(this->_p) -= value;
			return (this);
		}
		_Self &operator-=(int value){
			(this->_p) += value;
			return (this);
		}
		_Self &operator+(int value) const{
			_Self temp(this);
			return (temp += value);
		}
		_Self &operator-(int value) const{
			_Self temp(this);
			return (temp -= value);
		}
		reference &operator[](int value){
			return (*(this->_p + value));
		}
		const_reference &operator[](int value) const{
			return (*(this->_p + value));
		}
		difference_type operator-(_Self const &other) const{
			return (this->_p - other->_p);
		}
		bool operator==(_Self const &other) const{
			return (this->_p == other->_p);
		}
		bool operator!=(_Self const &other) const{
			return (this->_p != other->_p);
		}
		bool operator<(_Self const &other) const{
			return (this->_p > other->_p);
		}
		bool operator<=(_Self const &other) const{
			return (this->_p >= other->_p);
		}
		bool operator>(_Self const &other) const{
			return (this->_p < other->_p);
		}
		bool operator>=(_Self const &other) const{
			return (this->_p <= other->_p);
		}
};
}
#endif