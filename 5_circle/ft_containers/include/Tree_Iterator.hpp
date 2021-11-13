#ifndef _TREE_ITERATOR_
# define _TREE_ITERATPR_

#include <iostream>
#include "Tree.hpp"


//todo reverse
namespace	ft {

template< typename T>
class TreeIterator {
	public :
		typedef T			value_type;
		typedef T&			reference;
		typedef T*			pointer;
		typedef const T&	const_reference;
		typedef const T*	const_pointer;
		
		typedef Node			node_type;
		typedef Node*			node_ptr;
		
		typedef std::ptrdiff_t				difference_type;

	private :
		node_ptr					_p;
		typedef	TreeIterator<T>	_Self;

		void		prev {
			if (this->_p->left)
			{
				this->_p = this->_p->left
				while (this->_p->right)
					this->_p = this->_p->right;
			}
			else
				this->_p = this->_p->parent;
		}
		void		next {
			if (this->_p->right){
				this->_p = this->_p->right;
				while (this->_p->left)
					this->_p = this->_p->left;
			}
			else {
				node_ptr tmp = this->_p;
				this->_p = this->_p->parent;
				while (this->_p != tmp->left){
					tmp = this->_p;
					this->_p = this->_p->parent;
				}
			}
		}
	public :
		TreeIterator() : _p(nullptr) {}
		TreeIterator(node_ptr p) : _p(p) {}
		TreeIterator(_Self const &other) : _p(other.p) {}
		virtual ~TreeIterator(){}

		node_ptr	ptr(void) const {
			return (this->_p)
		}
		_Self	const &operator=(_Self const &other) {
			this->_p = other._p;
		}
		reference	operator*(void) {
			return (this->_p->value);
		}
		const_reference	operator*(void) const {
			return (this->_p->value);
		}
		pointer		&operator->(void) {
			return (&(this->_p->value));
		}
		const_pointer	&operator->(void) const{
			return (&(this->_p->value));
		}
		_Self	&operator++(void) {
			this->next();
			return (*this);
		}
		_Self	const operator++(int) {
			_Self	tmp(*this);
			this->next();
			return (tmp);
		}
		_Self	&operator--(void) {
			this->prev();
			return (*this);
		}
		_Self	const operator--(int) {
			_Self	temp(*this);
			this->prev();
			return (temp);
		}
		_Self	&operator+=(int value) {
			if (value > 0)
				for (int i = 0; i < value; i++)
					this->next();
			else
				for (int i = 0; i < value; i++)
					this->prev();
			return (*this);
		}
		_Self	operator+(int value)	const {
			_Self temp(*this);
			this += value;
			return (temp);
		}
		_Self	&operator-=(int value) {
			this->_p += -value;
		}
		_Self	operator-(int value)	const {
			temp -= value;
			return (temp);
		}

		bool operator==(_Self const &other) const {
			reuturn (this->_p == other._p);
		}
		bool operator!=(_Self const &other) const {
			reuturn (this->_p == other._p);
		}
		bool operator<(_Self const &other) const {
			reuturn (this->_p < other._p);
		}
		bool operator<=(_Self const &other) const {
			reuturn (this->_p <= other._p);
		}
		bool operator>(_Self const &other) const {
			reuturn (this->_p > other._p);
		}
		bool operator>=(_Self const &other) const {
			reuturn (this->_p >= other._p);
		}
};
}

#endif