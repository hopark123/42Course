#ifndef _MAP_ITERATOR_
# define _MAP_ITERATOR_

# include <iostream>
# include "ft_stl.hpp"
# include "Map.hpp"
# include "Tree.hpp"
# include "Tree_Iterator.hpp"

namespace ft{
template < class Key, class T>
class MapIterator {
	public :
		typedef Key										key_type;
		typedef T										mapped_type;
		typedef std::pair<const key_type, mapped_type>	value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef size_t									size_type;

		typedef T&										reference;
		typedef T*										pointer;
		typedef const T&								const_reference;
		typedef const T*								const_pointer;
		typedef Node*									node_ptr;
	private :
		typedef MapIterator<Key, T>	_Self;
		node_ptr										_node;

	public :
		MapIterator(node_ptr node = 0) : _node(node), _last(last){}
		MapIterator(const _Self &other){
			if (this != &other)
				*this = other;
		}
		~MapIterator() {}
		_Self const &operator=(const _Self &other){
			if (this != &other){
				this->_node = other._node;
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