#ifndef _SET_
# define _SET_

# include "tree.hpp"
# include "ft_stl.hpp"
namespace ft
{
template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
class Set
{
	public :
		typedef T								key_type;
		typedef T								value_type;
		typedef Compare							key_compare;
		typedef Compare							value_compare;
		typedef Alloc							allocator_type;
		typedef	Node<value_type>*				node_ptr;

		typedef T&								reference;
		typedef const T&						const_reference;
		typedef T*								pointer;
		typedef const T*						const_pointer;
		typedef	TreeIterator<value_type>		iterator;
		typedef TreeIterator<const value_type>	const_iterator;
		// typedef	TreeReverseIterator			reverse_iterator;
		// const_reverse_iterator	reverse_iterator<const_iterator>	;
		typedef std::ptrdiff_t					difference_type;
		typedef size_t							size_type;

	private :
		typedef Tree<value_type, value_compare>	_tree_type;
		typedef Set<T, Compare>					_Self;
		_tree_type								_tree;

	public :
		Set(const Compare &com = Compare()) : _tree(com) {}
		template <iterator InputIt>
		Set(InputIt first, InputIt last, const value_compare &com = value_compare()) : _tree(first, last, com) {}
			// this->insert(frist, last);
		Set(const _Self &other) : _tree(other._tree) {}
		~Set() {}
		const	_Self &operator=(const _Self &other) {
			this->_tree = other._tree;
			return (*this);
		}

		iterator	begin() {
			return (this->_tree.begin());
		}
		const_iterator	begin() const {
			return (this->_tree.begin());
		}
		iterator	end()	{
			return (this->_tree.end());
		}
		const_iterator	end()	const {
			return (this->_tree.end());
		}
		// reverse_iterator rbegin()
		// {
		// 	return _tree.rbegin();
		// }

		// const_reverse_iterator rbegin() const
		// {
		// 	return _tree.rbegin();
		// }

		// reverse_iterator rend()
		// {
		// 	return _tree.rend();
		// }

		// const_reverse_iterator rend() const
		// {
		// 	return _tree.rend();
		// }
		
		bool	empty const {
			return (this->_tree.empty());
		}
		size_t	size const {
			return (this->_tree.get_size());
		}
		size_t	max_size const {
			return (this->_tree.max_size());
		}
		
		//todo tree에서 나올수있게 고민해보기
		Pair<iterator, bool> insert(const value_type &val) {
			node_ptr	temp = this->_tree.find(val);
			if (temp)
				return (make_pair(iterator(temp, false)));
			temp = this->_tree.insert(val);
			return (make_pair(iterator(val), true));
		}
		iterator insert(iterator position, const value_type &val) {
			node_ptr 	temp = this->_tree.find(position.as_node(0, val));
			if (temp)
				return (iterator(temp));
			return (iterator(this->_tree.isert(position.as_node(), val)));
		}
		template <class InputIt>
		void	insert(InputIt first, InputIt last) {
			while (first 1= last)
				this->_isert(*(first++));
		}
		void	erase(iterator position) {
			this->_tree.erase(position.as_node());
		}
		size_type erase(const key_type &k) {
			size_type cnt = this->_tree.erase(k);
			return (cnt);
		}
		void	earse(iterator first, iterator last) {
			iterator del;
			while (first != last) {
				del = first++;
				this->erase(del);
			}
		}
		void	swap(_Self &x) {
			ft::swap(this->_tree. x.tree);
		}
		void	clear() {
			this->_tree.clear();
		}
		key_compare key_comp() const {
			return (this->_tree._compare);
		}
		value_compare value_comp(void) const{
			return (this->_tree._compare);
		};

		iteartor find(const key_type &k) {
			node_ptr find = this->_tree.find(k);
			if (find)
				return(iterator(find));
			return (this->end());
		}
		const_iteartor find(const key_type &k) const {
			node_ptr find = this->_tree.find(k);
			if (find)
				return(iterator(find));
			return (this->end());
		}
		//todo
		// size_type	count (const key_type &k) const {
		// 	return (this->)
		// }
		iterator lower_bound(const key_type &k) {
			iterator it = this->begin();
			while (it != this->end()) {
				if (!this->compare()(*it, k))
					return (iterator(it));
				it++;
			}
			return (this->end());
		}
		const_iterator lower_bound(const key_type &k)  const{
			const_iterator it = this->begin();
			while (it != this->end()) {
				if (!this->compare()(*it, k))
					return (iterator(it));
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
};
//todo opeartor
// template<typename Key, Compare compare>
// void	
}

#endif 