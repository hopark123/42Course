#ifndef _SET_
# define _SET_

# include "tree.hpp"
# include "ft_utils.hpp"
# include "Iterator_utils.hpp"

namespace ft
{
template < class T, class Compare = ft::less<T>, class Alloc = std::allocator<T> >
class set
{
	public :
		typedef T								key_type;
		typedef T								value_type;
		typedef Compare							key_compare;
		typedef Compare							value_compare;
		typedef Alloc							allocator_type;
		typedef	Node<const value_type>*				node_ptr;

		typedef T&								reference;
		typedef const T&						const_reference;
		typedef T*								pointer;
		typedef const T*						const_pointer;
		typedef typename tree<const value_type, value_compare>::iterator		iterator;
		typedef typename tree<const value_type, value_compare>::const_iterator		const_iterator;


		typedef reverse_iteartor<iterator>			reverse_iterator;
		typedef reverse_iteartor<const_iterator>	const_reverse_iterator;
		typedef std::ptrdiff_t					difference_type;
		typedef size_t							size_type;

	private :
		typedef tree<const value_type, value_compare>	_tree_type;
		typedef set<T, Compare>					_Self;
		_tree_type								_tree;

	public :
		set(const Compare &com = Compare()) : _tree(com) {}
		template <typename InputIt>
		set(InputIt first, InputIt last, const value_compare &com = value_compare()) : _tree(com) {
			this->insert(first, last);
		}
		set(const _Self &other) : _tree(other._tree) {
		}
		~set() {}
		const	_Self &operator=(const _Self &other) {
			this->_tree = other._tree;
			return (*this);
		}
		iterator begin() {
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

		bool	empty(void) const {
			return (this->_tree.is_empty());
		}
		size_t	size(void) const {
			return (this->_tree.get_size());
		}
		size_t	max_size(void) const {
			return (this->_tree.max_size());
		}
		
		pair<iterator, bool> insert(const value_type &val) {
			node_ptr	temp = this->_tree.find(val);
			if (temp)
				return (ft::make_pair(iterator(temp), false));
			temp = this->_tree.insert(val);
			return (ft::make_pair(iterator(temp), true));
		}
		iterator insert(iterator position, const value_type &val) {
			const node_ptr	temp = this->_tree.find(position.as_node(), val);
			if (temp)
				return (iterator(temp));
			return (iterator(this->_tree.insert(position.as_node(), val)));
		}
		template <class InputIt>
		void	insert(InputIt first, InputIt last) {
			while (first != last)
				this->insert(*(first++));
		}
		void	erase(iterator position) {
			this->_tree.erase(position.as_node());
		}

		size_type erase(const key_type &k) {
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
		void	swap(_Self &x) {
			ft::swap(this->_tree, x.tree);
		}
		void	clear() {
			this->_tree.clear();
		}
		key_compare key_comp() const {
			return (this->_tree._compare);
		}
		value_compare value_comp(void) const{
			return (this->_tree._compare);
		}

		iterator find(const key_type &k) {
			node_ptr find = this->_tree.find(k);
			if (find)
				return(iterator(find));
			return (this->end());
		}
		const_iterator find(const key_type &k) const {
			node_ptr find = this->_tree.find(k);
			if (find)
				return(const_iterator(find));
			return (this->end());
		}
		size_type	count(const key_type &k) const {
			if (this->find(k)!= this->end())
				return (1);
			return (0);
		}
		iterator lower_bound(const key_type &k) {
			iterator it = this->begin();
			while (it != this->end()) {
				if (!this->key_comp()(*it, k))
					return (iterator(it));
				it++;
			}
			return (this->end());
		}
		const_iterator lower_bound(const key_type &k)  const{
			const_iterator it = this->begin();
			while (it != this->end()) {
				if (!this->key_comp()(*it, k))
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

		pair<iterator, iterator> equal_range(const key_type &k) {
			return make_pair(lower_bound(k), upper_bound(k));
		}

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const {
			return make_pair(lower_bound(k), upper_bound(k));
		}


		void	print(void) {
		std::cout << "/===========" << "===========\\" << std::endl;
		this->_tree.print(this->_tree._root);
		std::cout << "\\======================/" << std::endl;
		return ;
		}
};
//todo opeartor
// template<typename Key, Compare compare>
// void	
}

#endif 