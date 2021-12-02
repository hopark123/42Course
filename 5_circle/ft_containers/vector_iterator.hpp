#ifndef _Vector_ITERATOR_
# define _Vector_ITERATOR_

# include <iostream>
# include "ft_utils.hpp"
# include "vector.hpp"

namespace ft
{
template<typename T>
class vectorIterator {
	public :
		typedef T					value_type;
		typedef T&					reference;
		typedef T*					pointer;
		typedef std::ptrdiff_t		difference_type;
		typedef RandomAccessIteratorTag	iterator_category;

	private :
		pointer						_p;
		typedef	vectorIterator<T>	_Self;
	public :
		vectorIterator() : _p(NULL) {}
		vectorIterator(pointer p) : _p(p) {}
		template <typename U>
		vectorIterator(const vectorIterator<U> &it, typename ft::enable_if<!ft::is_integral<U>::value>::type* = 0) : _p(it.base()) {}
		vectorIterator(const _Self &other) : _p(other._p) {}
		~vectorIterator() {}
		operator vectorIterator<const T> () const { return (vectorIterator<const T>(this->_p)); } // const 치환
		template <typename U>
		_Self &operator=(const vectorIterator<U> &other) {
			if (*this != other)
				this->_p = other.base();
			return (*this);
		}
		reference	operator*(void) const {
			return (*(this->_p));
		}
		pointer	operator->(void) const{
			return (this->_p);
		}
		_Self &operator++(void){ // prefix increment
			++(this->_p);
			return (*this);
		}
		const _Self operator++(int){ // postfix increment
			_Self temp(*this);
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
		_Self &operator+=(difference_type value){
			(this->_p) += value;
			return (*this);
		}
		_Self &operator-=(difference_type value){
			(this->_p) -= value;
			return (*this);
		}
		_Self operator+(difference_type value) const{
			_Self temp(*this);
			// std::cout << "vetoer? +" << value << std::endl;
			temp += value;
			return (temp);
		}
		_Self operator-(difference_type value) const{
			// std::cout << "vetoer -" << std::endl;
			_Self temp(*this);
			temp -= value;
			return (temp);
		}
		reference operator[](difference_type value){
			return (*(this->_p + value));
		}
		difference_type operator-(const _Self &other) const {
			return (this->_p - other._p);
		}
		bool operator==(const _Self &other) const{
			return (this->_p == other._p);
		}
		bool operator!=(const _Self &other) const{
			return (this->_p != other._p);
		}
		bool operator<(const _Self &other) const{
			return (this->_p < other._p);
		}
		bool operator<=(const _Self &other) const{
			return (this->_p <= other._p);
		}
		bool operator>(const _Self &other) const{
			return (this->_p > other._p);
		}
		bool operator>=(const _Self &other) const{
			return (this->_p >= other._p);
		}

		pointer	base(void) const {
			return (this->_p);
		}
};
template <typename It1, typename It2>
bool operator==(const vectorIterator<It1>& it1, const vectorIterator<It2>& it2) {
	return (it1.base() == it2.base());
}
template <typename It1, typename It2>
bool operator>=(const vectorIterator<It1>& it1, const vectorIterator<It2>& it2) {
	return (it1.base() >= it2.base());
}
template <typename It1, typename It2>
bool operator>(const vectorIterator<It1>& it1, const vectorIterator<It2>& it2) {
	return (it1.base() > it2.base());
}
template <typename It1, typename It2>
bool operator<=(const vectorIterator<It1>& it1, const vectorIterator<It2>& it2) {
	return (it1.base() <= it2.base());
}
template <typename It1, typename It2>
bool operator<(const vectorIterator<It1>& it1, const vectorIterator<It2>& it2) {
	return (it1.base() < it2.base());
}
template <typename It1, typename It2>
bool operator!=(const vectorIterator<It1>& it1, const vectorIterator<It2>& it2) {
	return (it1.base() != it2.base());
}


template <typename It>
vectorIterator<It> operator+(typename vectorIterator<It>::difference_type n, const vectorIterator<It> &it) {
	return (vectorIterator<It>(it + n));
}
// template <typename It>
// vectorIterator<It> operator-(typename vectorIterator<It>::difference_type n, const vectorIterator<It> &it) {
// 	return (vectorIterator<It>(it - n));
// }
}
#endif


