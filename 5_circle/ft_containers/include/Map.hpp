#ifndef _MAP_
# define _MAP

#include <iostream>
#include "ft_stl.hpp"
#include "Map_Iterator.hpp"

namespace ft {
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class Map{
	public :
		typedef	Key											key_type;
		typedef	T											mapped_type;
		typedef	std::pair<const key_type, mapped_type>		value_type;
		typedef	Compare										key_compare;
		typedef	Alloc										allocator_type;
		
		typedef	T&											refrence;
		typedef	const T&									const_reference;
		typedef	T*											pointer;
		typedef	const T*									const_pointer;
		
		typedef	MapIterator<Key, T, Compare, Node>			iterator;
		typedef	MapIterator<Key, const T, Compare, Node>	const_iterator;
		typedef	MapRevIterator<Key, T, Compare, Node>		reverse_iterator;
		typedef	MapRevIterator<Key, const T, Compare, Node>	const_reverse_iterator;

		typedef	std::ptrdiff_t								difference_type;
		typedef	size_t										size_type;
		
		class	value_compare {
			friend class Map;
			protected :
				key_compare		_com;
				value_compare(key_compare com) : com(com) {};
			public :
				typedef bool	result_type;
				typedef value_tpye		first_argument_type;
				typedef	value_type		second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return _com(x.first, y.first);
				}
		}
	private :
		struct Node {
			std::pair<const Key, T>	content;
			Node*					parent;
			Node*					left;
			Node*					right;
		};

		Node*					_root;
		Node*					_last;
		key_compare				_com;
		size_type				_size;

};

}



#endif