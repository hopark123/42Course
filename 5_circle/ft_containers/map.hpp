#ifndef _mAP_
# define _mAP_

# include <iostream>
# include "tree.hpp"
# include "ft_utils.hpp"
# include "Iterator_utils.hpp"

namespace ft
{
template < typename Key, typename T, typename Compare = ft::less<Key>, typename Alloc = std::allocator<ft::pair<const Key, T> > >
class map {
	public :
		typedef	Key											key_type;
		typedef	T											mapped_type;
		typedef	pair<const key_type, mapped_type>			value_type;
		typedef	Compare										key_compare;
		typedef	Alloc										allocator_type;
		typedef	Node<value_type>*							node_ptr;
		
		typedef	T&											refrence;
		typedef	const T&									const_reference;
		typedef	T*											pointer;
		typedef	const T*									const_pointer;
		


		typedef	std::ptrdiff_t								difference_type;
		typedef	size_t										size_type;
		class	value_compare {
			friend class map;
			public :
				key_compare		_com;
				value_compare(key_compare com = ft::less<Key>()) : _com(com) {
					this->_com = com;
				}
				value_compare(const value_compare &com) : _com(com._com) {}
				typedef bool			result_type;
				typedef value_type		first_argument_type;
				typedef	value_type		second_argument_type;
				bool operator() (const value_type& x, const value_type& y) const {
					return _com(x.first, y.first);
				}
				~value_compare(void) {}
		};
		
		typedef typename tree<value_type, value_compare>::iterator				iterator;
		typedef typename tree<value_type, value_compare>::const_iterator		const_iterator;
		typedef reverse_iteartor<iterator>			reverse_iterator;
		typedef reverse_iteartor<const_iterator>	const_reverse_iterator;

	private :
		typedef	tree<value_type, value_compare, Alloc>		tree_type;
		tree_type											_tree;
		typedef	map<Key, T, Compare, Alloc>					_Self;
	public :
		map(const key_compare &com = key_compare()) : _tree(value_compare(com)) {}
		template<typename InputIt>
		map(InputIt first, InputIt last, const key_compare &com = key_compare()) :  _tree(value_compare(com)) {
			this->insert(first, last);
		}
		map(const _Self &other) : _tree(other._tree) {}
		~map(void) {}
		const _Self &operator=(const _Self &other) {
			this->_tree = other._tree;
			return (*this);
		}
		
		iterator begin(void) {
			return (iterator(this->_tree.begin()));
		}
		const_iterator	begin(void) const {
			return (const_iterator(this->_tree.begin()));
		}
		iterator	end(void) {
			return (iterator(this->_tree.end()));
		}
		const_iterator	end(void) const {
			return (const_iterator(this->_tree.end()));
		}
		reverse_iterator rbegin(void) {
			return (reverse_iterator(this->_tree.rbegin()));
		}
		const_reverse_iterator	rbegin(void) const {
			return (const_reverse_iterator(this->_tree.rbegin()));
		}
		reverse_iterator	rend(void) {
			return (reverse_iterator(this->_tree.rend()));
		}
		const_reverse_iterator	rend(void) const {
			return (const_reverse_iterator(this->_tree.rend()));
		}
		bool empty(void) const {
			return (this->_tree.is_empty());
		}
		size_t	size(void) const {
			return (this->_tree.get_size());
		}
		size_t	max_size(void) const {
			return (this->_tree.max_size());
		}

		mapped_type	&operator[](const key_type target) {
			iterator	find = this->find(target);
			if (find != this->end())
				return ((find->second));
			return (this->_tree.insert(ft::make_pair(target, mapped_type()))->_data.second);
		}
		pair<iterator, bool> insert(const value_type &val) {
			node_ptr	temp = this->_tree.find(val);
			if (temp)
				return (ft::make_pair(iterator(temp), false));
			temp = this->_tree.insert(val);
			return (ft::make_pair(iterator(temp), true));
		}
		iterator	insert(iterator position, const value_type& val) {
			node_ptr	temp = this->_tree.find(position.as_node(), val);
			if (temp)
				return (iterator(temp));
			return (iterator(this->_tree.insert(position.as_node(), val)));
		}
		template <typename InputIt>
		void	insert(InputIt first, InputIt last) {
			while (first != last && first.operator->()){
				this->insert(*(first++));
			}
		}
		void	erase(iterator position) {
			this->_tree.erase(position.as_node());
		}
		size_type	erase(const key_type &k) {
			iterator	position = this->find(k);
			if (position == _tree.end())
				return (0);
			this->_tree.erase(position.as_node());
			return (1);
		}
		void	erase(iterator first, iterator last) {
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
		void	clear(void) {
			this->_tree.clear();
		}
		void	swap(_Self &other) {
			this->_tree.swap(other._tree);
		}
		key_compare	key_comp(void) const {
			return (this->_tree.key_compare()._com);
		}
		value_compare	value_comp(void) const {
			return (this->_tree.key_compare());
		}
		iterator	find (const key_type &k) {
			value_type	val = ft::make_pair(k, mapped_type());
			node_ptr	find = this->_tree.find(val);
			if (find)
				return (iterator(find));
			return (this->end());
		}
		const_iterator find (const key_type &k) const {
			value_type	val = ft::make_pair(k, mapped_type());
			node_ptr	find = this->_tree.find(val);
			if (find)
				return (const_iterator(find));
			return (this->end());
		}

		size_type	count(const key_type &k) const {
			if (this->find(k)!= this->end())
				return (1);
			return (0);
		}
		iterator lower_bound (const key_type& k) {
			iterator it = this->begin();
			while (it != this->end()) {
				if (!this->value_comp()(*it , ft::make_pair(k, mapped_type())))
					return (iterator(it));
				it++;
			}
			return (this->end());
		}
		const_iterator lower_bound (const key_type& k) const {
			const_iterator it = this->begin();
			while (it != this->end()) {
				if (!this->value_comp()(*it , ft::make_pair(k, mapped_type())))
					return (const_iterator(it));
				it++;
			}
			return (this->end());
		}
		iterator upper_bound (const key_type& k) {
			iterator it = this->begin();
			while (it != this->end()) {
				if (this->value_comp()(ft::make_pair(k, mapped_type()), *it))
					return (iterator(it));
				it++;
			}
			return (this->end());
		}
		const_iterator upper_bound (const key_type& k) const {
			const_iterator it = this->begin();
			while (it != this->end()) {
				if (this->value_comp()(ft::make_pair(k, mapped_type()), *it))
					return (const_iterator(it));
				it++;
			}
			return (this->end());
		}

		pair<iterator,iterator>	equal_range (const key_type& k) {
			return (pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		}
		pair<const_iterator,const_iterator>	equal_range (const key_type& k) const {
			return (pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		}

		void	print(void) {
			std::cout << "/==========="<< this->_tree._root->_data.first << "===========\\" << std::endl;
			this->_tree.print(this->_tree._root);
			std::cout << "\\======================/" << std::endl;
			return ;
		}
};

template <typename Key, typename T, typename Compare >
void swap(map<Key, T, Compare> &x, map<Key, T, Compare> &y) {
	x.swap(y);
}

template <typename Key, typename T, typename Compare >
bool operator==(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
	if (lhs.size() != rhs.size())
		return (false);
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}
template <typename Key, typename T, typename Compare >
bool operator!=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
	return (!(lhs == rhs));
}

template <typename Key, typename T, typename Compare >
bool operator<(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), lhs.value_comp()));
}

template <typename Key, typename T, typename Compare >
bool operator>=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
	return (!(lhs < rhs));
}

template <typename Key, typename T, typename Compare >
bool operator>(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
	return (rhs < lhs);
}

template <typename Key, typename T, typename Compare >
bool operator<=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs) {
	return (!(rhs < lhs));
}
}

#endif