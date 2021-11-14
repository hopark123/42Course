#ifndef _MAP_
# define _MAP_

#include <iostream>
#include "ft_stl.hpp"

namespace ft {
template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class Map{
	public :
		typedef	Key											key_type;
		typedef	T											mapped_type;
		typedef	Pair<const key_type, mapped_type>			value_type;
		typedef	Compare										key_compare;
		typedef	Alloc										allocator_type;
		typedef	Node<value_type>*										node_ptr;
		
		typedef	T&											refrence;
		typedef	const T&									const_reference;
		typedef	T*											pointer;
		typedef	const T*									const_pointer;
		

		typedef	TreeIterator<value_type>							iterator;
		typedef	TreeIterator<const value_type>					const_iterator;
		// typedef	TreeIterator<Key, T, Compare>		reverse_iterator;
		// typedef	TreeIterator<Key, const T, Compare>	const_reverse_iterator;

		typedef	std::ptrdiff_t								difference_type;
		typedef	size_t										size_type;
		
		class	value_compare {
			friend class Map;
			protected :
				key_compare		_com;
				value_compare(key_compare com) : _com(com) {};
			public :
				typedef bool	result_type;
				typedef value_type		first_argument_type;
				typedef	value_type		second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const
				{
					return _com(x.first, y.first);
				}
		};

	private :
		typedef	Tree<value_type, value_compare>			_tree_type;
		typedef	Map<Key, T, Compare>					_Self;
		_tree_type										_tree;
	public : 
		Map(const key_compare com = key_compare()) : _tree(value_compare(com)) {}
		template<typename InputIt>
		Map(InputIt first, InputIt last, const key_compare com = key_compare()) {
			this->insert(first, last);
		}
		Map(_Self const &other) : _tree(other._tree) {}
		~Map() {}
		_Self const &operator=(_Self const &other) {
			this->_tree = other._tree;
			return (*this);
		}
		
		iterator begin() {
			return (this->_tree.begin());
		}
		const_iterator begin() const {
			return (this->_tree.begin());
		}
		iterator end() {
			return (this->_tree.end());
		}
		const_iterator end() const {
			return (this->_tree.end());
		}
		bool	empty() const {
			return (this->_tree.is_empty());
		}
		size_t	size() const {
			return (this->_tree.get_size());
		}
		size_t	max_size() const {
			return (this->_tree.max_size());
		}

		mapped_type	&operator[](const key_type target) {
			node_ptr	find = this->_tree.find(target);
			if (find)
				return (find->_data.second);
			return (this->_tree.insert(make_pair(target, mapped_type()))->_data.second);
		}


		Pair<iterator,bool> insert (const value_type& val) {
			node_ptr	temp = this->_tree.find(val);
			if (temp)
				return (make_pair(iterator(temp), false));
			temp = this->_tree.insert(val);
			return (make_pair(iterator(temp), true));
		}
		iterator insert (iterator position, const value_type& val) {
			node_ptr	temp = this->_tree.find(position.as_node(), val);
			if (temp)
				return (iterator(temp));
			return (iterator(this->_tree.insert(position.as_node(), val)));
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last) {
			while (first != last)
				this->_insert(*first++);
		}
		void erase (iterator position) {
			this->_tree.erase(position.as_node());
		}
		size_type erase (const key_type& k) {
			size_type	cnt = this->_tree.erase(k);
			return (cnt);
		}
		void erase (iterator first, iterator last) {
			if (first == this->begin() && last == this->end())
				this->clear();
			else {
				iterator del;
				while (first != last) {
					del = first++;
					this->erase(del);
				}
			}
		}
		void swap (_Self &x) {
			swap(this->_tree, x._tree);
		}
		void	clear() {
			this->_tree.clear();
		}

		key_compare key_comp() const {
			return (this->_tree._compare);
		}
		value_compare value_comp(void) const{
			return (this->value_compare);
		};


		iterator find (const key_type& k) {
			node_ptr find = this->_tree.find(k);
			if (find)
				return (iterator(find));
			return (this->end());
		}
		const_iterator find (const key_type& k) const {
			node_ptr find = this->_tree.find(k);
			if (find)
				return (iterator(find));
			return (this->end());
		}

		size_type count (const key_type& k) const {
			return (this->_tree._len);
		}
		iterator lower_bound (const key_type& k) {
			iterator it = this->begin();
			while (it != this->end()) {
				if (!this->key_comp()(*it , k))
					return (iterator(it));
				it++;
			}
			return (this->end());
		}
		const_iterator lower_bound (const key_type& k) const {
			const_iterator it = this->begin();
			while (it != this->end()) {
				if (!this->key_comp()(*it , k))
					return (const_iterator(it));
				it++;
			}
			return (this->end());
		}
		iterator upper_bound (const key_type& k) {
			iterator it = this->begin();
			while (it != this->end()) {
				if (this->key_comp()(k, *it))
					return (iterator(it));
				it++;
			}
			return (this->end());
		}
		const_iterator upper_bound (const key_type& k) const {
			const_iterator it = this->begin();
			while (it != this->end()) {
				if (this->key_comp()(k, *it))
					return (const_iterator(it));
				it++;
			}
			return (this->end());
		}

		Pair<iterator,iterator>	equal_range (const key_type& k) {
			return (Pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		Pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {
			return (Pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		// allocator_type get_allocator() const {
		// 	return (this->)
		// }
};
}


#endif