#ifndef _MAP_ITERATOR_
# define _MAP_ITERATOR_

# include <iostream>
# include "ft_stl.hpp"
# include "Map.hpp"


namespace ft{
template < class Key, class T, class Compare, typename Node, bool B >
class MapIterator {
	public :
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef std::pair<const key_type, mapped_type>	value_type;
		typedef Compare									key_compare;
		typedef std::ptrdiff_t							difference_type;
		typedef size_t									size_type;

		typedef T&										reference;
		typedef T*										pointer;
		typedef const T&								const_reference;
		typedef const T*								const_pointer;
		typedef Node*									node_ptr;
	private :
		typedef MapIterator<Key, T, Compare, Node, B>	_Self;
		node_ptr										_node;
		node_ptr										_last;
		key_compare										_com;

	public :
		MapIterator(node_ptr node = 0, node_ptr last = 0; const key_compare& com = key_compare()) : _node(node), _last(last), _com(com) {}
		MapIterator(const _Self &other){
			if (this != &other)
				*this = other;
		}
		~MapIterator() {}
		_Self const &operator=(const _Self &other){
			if (this != &other){
				this->_node = other._node;
				this->_last = other._last;
				this->_com = other._com;
			}
			return (*this);
		}
		node_ptr	getNode() const {
			return this->_node;
		}
		node_ptr	getLast() const {
			return this->_last;
		}
		key_compare	getCom() const {
			return this->_com;
		}

		reference	&operator*(void) {
			return (this->_node->content);
		}
		const_reference	&operator*(void) const {
			return (this->_node->content);
		}
		pointer		&operator->(void) {
				return (&(this->node->content));
		}
		const_pointer	&operator->(void) const{
			return (&(this->node->content));
		}
		_Self &operator++(void) {

		}
};
}

#endif