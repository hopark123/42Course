#ifndef _ITERATOR_TRAITS_
# define _ITERATOR_TRAITS_

# include "ft_utils.hpp"
# include <iostream>
# include "ft_utils.hpp"

//todo enable
namespace ft 
{
// struct pair{
// };

// Iterator tags
struct InputIteratorTag {};
struct OutputIteratorTag {};
struct ForwardIteratorTag : public InputIteratorTag {};
struct BidirectionalIteratorTag : public ForwardIteratorTag {};
struct RandomAccessIteratorTag : public BidirectionalIteratorTag {};


// Iterators_traits
template <typename It>
struct IteratorTraits {
	typedef typename It::difference_type	difference_type;
	typedef typename It::value_type			value_type;
	typedef typename It::pointer			pointer;
	typedef typename It::reference			reference;
	typedef typename It::iterator_category	iterator_category;
};

template <typename T>
struct IteratorTraits<T*> {
	typedef std::ptrdiff_t	differnece_type;
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef RandomAccessIteratorTag	iterator_category;
};

template <typename T>
struct IteratorTraits<const T*> {
	typedef std::ptrdiff_t	differnece_type;
	typedef T				value_type;
	typedef T*				pointer;
	typedef T&				reference;
	typedef RandomAccessIteratorTag	iterator_category;
};

// reverse_iteartor
template<typename It>
class reverse_iteartor {
	public :
		typedef It												iterator_type;
		typedef typename IteratorTraits<It>::difference_type	difference_type;
		typedef typename IteratorTraits<It>::value_type			value_type;
		typedef typename IteratorTraits<It>::reference			reference;
		typedef typename IteratorTraits<It>::pointer			pointer;
		typedef typename IteratorTraits<It>::iterator_category	iterator_category;
	private :
		It									_base;
		typedef reverse_iteartor<It>		_Self;
	
	public :
		reverse_iteartor() : _base(nullptr) {};
		reverse_iteartor(It base) : _base(base) {}
		reverse_iteartor(const _Self &other) : _base(other._base) {}
		template <typename U>
		reverse_iteartor(const reverse_iteartor<U> &it, typename std::enable_if<!std::is_integral<U>::value>::type* = 0) : _base(it.base()) {}
		~reverse_iteartor() {}
		operator reverse_iteartor<const It> () const { return (reverse_iteartor<const It>(this->_base)); } // const 치환
		template <typename U>
		_Self &operator=(const reverse_iteartor<U> &other) {
			if (*this != other)
				this->_base = other.base();
			return (*this);
		}
		_Self &operator=(const _Self &other) {
			if (*this != other)
				this->_base = other._base;
			return (*this);
		}
		reference	operator*(void) const {
			It temp = this->base();
				return *(--temp);
		}
		pointer	operator->(void) {
			return (&operator*());
		}
		_Self &operator++(void) {
			--(this->_base);
			return (*this);
		}
		_Self const operator++(int) {
			_Self res(this->_base);
			--(this->_base);
			return (res);
		}
		_Self &operator--(void) {
			++(this->_base);
			return (*this);
		}
		_Self const operator--(int) {
			_Self res(this->_base);
			++(this->_base);
			return (res);
		}
		_Self &operator+=(difference_type value) {
			this->_base -= value;
			return (*this);
		}
		_Self &operator-=(difference_type value) {
			this->_base += value;
			return (*this);
		}
		_Self operator+(difference_type value) const{
			_Self temp(*this);
			temp += value;
			return (temp);
		}
		_Self operator-(difference_type value) const{
			_Self temp(*this);
			temp -= value;
			return (temp);
		}
		reference operator[](difference_type value) {
			return (*(this->_base - value));
		}
		difference_type operator-(_Self const &other) const {
			return (other._base - this->_base);
		}
		bool operator==(_Self const &other) const{
			return (this->_base == other._base);
		}
		bool operator!=(_Self const &other) const{
			return (this->_base != other._base);
		}
		bool operator<(_Self const &other) const{
			return (this->_base > other._base);
		}
		bool operator<=(_Self const &other) const{
			return (this->_base >= other._base);
		}
		bool operator>(_Self const &other) const{
			return (this->_base < other._base);
		}
		bool operator>=(_Self const &other) const{
			return (this->_base <= other._base);
		}
		It base(void) const {
			return (this->_base);
		}
};

template <typename It1, typename It2>
bool operator==(const reverse_iteartor<It1>& it1, const reverse_iteartor<It2>& it2) {
	return (it1.base() == it2.base());
}
template <typename It1, typename It2>
bool operator!=(const reverse_iteartor<It1>& it1, const reverse_iteartor<It2>& it2) {
	return (it1.base() != it2.base());
}
template <typename It1, typename It2>
bool operator>=(const reverse_iteartor<It1>& it1, const reverse_iteartor<It2>& it2) {
	return (it1.base() <= it2.base());
}
template <typename It1, typename It2>
bool operator>(const reverse_iteartor<It1>& it1, const reverse_iteartor<It2>& it2) {
	return (it1.base() < it2.base());
}
template <typename It1, typename It2>
bool operator<=(const reverse_iteartor<It1>& it1, const reverse_iteartor<It2>& it2) {
	return (it1.base() >= it2.base());
}
template <typename It1, typename It2>
bool operator<(const reverse_iteartor<It1>& it1, const reverse_iteartor<It2>& it2) {
	return (it1.base() > it2.base());
}


template <typename It>
reverse_iteartor<It> operator+(typename reverse_iteartor<It>::difference_type n, const reverse_iteartor<It> &it) {
	return (reverse_iteartor<It>(it + n));
}
// template <typename It>
// reverse_iteartor<It> operator-(typename reverse_iteartor<It>::difference_type n, const reverse_iteartor<It> &it) {
// 	return (reverse_iteartor<It>(it - n));
// }


}
#endif