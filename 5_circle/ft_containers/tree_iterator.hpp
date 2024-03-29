#ifndef _TREE_ITERATOR_
# define _TREE_ITERATOR_

# include <iostream>
# include "ft_utils.hpp"


namespace ft
{
template <typename T, typename Node>
class treeIterator {
	public :
		typedef T				value_type;
		typedef T&				reference;
		typedef T*				pointer;
		typedef const T&		const_reference;
		typedef const T*		const_pointer;
		
		typedef Node			node_type;
		typedef Node*			node_ptr;
		typedef std::ptrdiff_t	difference_type;
		typedef RandomAccessIteratorTag	iterator_category;
	
	private :
		node_ptr				_p;
		typedef	treeIterator<T, Node>	_Self;
		
		void	prev(void) {
			if (this->_p->left) {
				this->_p = this->_p->left;
				while (this->_p->right)
					this->_p = this->_p->right;
			}
			else {
				node_ptr temp = this->_p;
				this->_p = this->_p->parent;
				while (this->_p->right !=temp) {
					temp = this->_p;
					this->_p = this->_p->parent;
				}
			}
		}
		void	next(void) {
			if (this->_p->right) {
				this->_p = this->_p->right;
				while (this->_p->left)
					this->_p = this->_p->left;
			}
			else {
				node_ptr	temp = this->_p;
				this->_p = this->_p->parent;
				while (this->_p->left != temp) {
					temp = this->_p;
					this->_p = this->_p->parent;
				}
			}
		}
	public :
		treeIterator(void) : _p(nullptr) {}
		treeIterator(node_ptr p) : _p(p) { }
		treeIterator(const _Self  &other) : _p(other._p) {}
		operator treeIterator<const T, const Node> () const {return (treeIterator<const T, const Node>(this->_p)); } // const 치환
		template <typename U, typename K>
		_Self &operator=(const treeIterator<U, K> &other) {
			if (*this != other)
				this->_p = other._p;
			return (*this);
		}
		virtual ~treeIterator(void) {}
		node_ptr	as_node(void){
			return (this->_p);
		}
		_Self	const &operator=(const _Self  &other) {
			this->_p = other._p;
			return (*this);
		}
		reference operator*(void) const {
			return (this->_p->_data);
		}
		pointer	operator->(void) const {
			return (&(this->_p->_data));
		}
		_Self	&operator++(void) {
			this->next();
			return (*this);
		}
		const _Self	operator++(int) {
			_Self	temp(*this);
			this->next();
			return (temp);
		}
		_Self	&operator--(void) {
			this->prev();
			return (*this);
		}
		const _Self	operator--(int) {
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
		_Self	operator+(int value) const {
			_Self	temp(*this);
			this +=value;
			return (temp);
		}
		_Self	&operator-=(int value) {
			this->_p += -value;
		}
		_Self	&operator-(int value) const {
			_Self	temp(*this);
			temp -= value;
			return (temp);
		}
		bool operator==(const _Self  &other) const {
			return (this->_p == other._p);
		}
		bool operator!=(const _Self  &other) const {
			return (this->_p != other._p);
		}
		bool operator<(const _Self  &other) const {
			return (this->_p < other._p);
		}
		bool operator<=(const _Self  &other) const {
			return (this->_p <= other._p);
		}
		bool operator>(const _Self  &other) const {
			return (this->_p > other._p);
		}
		bool operator>=(const _Self  &other) const {
			return (this->_p >= other._p);
		}

		node_ptr		base(void){
			return (this->_p);
		}
};

}
#endif