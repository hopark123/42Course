#ifndef _Vector_
# define _Vector_

# include <iostream>
# include "ft_utils.hpp"
# include "Iterator_utils.hpp"
# include "vector_iterator.hpp"

namespace ft
{
template<typename T, class Alloc = std::allocator<T> >
class vector {
	public :
		typedef T							value_type;
		typedef Alloc						allocator_type;
		typedef std::ptrdiff_t				difference_type;
		typedef size_t						size_type;

		typedef T&							reference;
		typedef T*							pointer;
		typedef const T&					const_reference;
		typedef const T*					const_pointer;

		typedef vectorIterator<T>					iterator;
		typedef vectorIterator<const T>				const_iterator;
		typedef reverse_iteartor<iterator>			reverse_iterator;
		typedef reverse_iteartor<const_iterator>	const_reverse_iterator;
	
	private :
		typedef vector<T>					_Self;
		pointer								_arr;
		size_type							_len;
		size_type							_cap;

	public :
		vector() : _arr(NULL), _len(0), _cap(0) {}
		vector(size_type n, const_reference &value = value_type()) : _arr(NULL), _len(0), _cap(0) {
			this->insert(this->begin(), n, value);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last) : _arr(NULL), _len(0), _cap(0) {
			this->insert(this->begin(), first, last);
		}
		vector(const _Self &other) : _arr(NULL), _len(0), _cap(0) {
			this->insert(this->begin(), other.begin(), other.end());
		}
		~vector() {
			this->clear();
		}
		const _Self &operator=(const _Self &other) {
			this->clear();
			this->insert(this->begin(), other.begin(), other.end());
			return (*this);
		}

		iterator begin(void) {
			return (iterator(this->_arr));
		}
		const_iterator begin(void) const {
			return (const_iterator(this->_arr));
		}
		iterator end(void) {
			return (iterator(this->_arr + this->_len));
		}
		const_iterator end(void) const {
			return (const_iterator(this->_arr + this->_len));
		}
		reverse_iterator	rbegin(void) {
			// std::cout << "this->end : " << *(this->end()) << *(this->end() - 1)<<std::endl;
			return (reverse_iterator(this->end()));
		}
		const_reverse_iterator	rbegin(void) const{
			return (const_reverse_iterator(this->end()));
		}
		reverse_iterator rend(void) {
			return (reverse_iterator(this->_arr));
		}
		const_reverse_iterator rend(void) const {
			return (const_reverse_iterator(this->_arr));
		}

		size_type	size(void) const {
			return (this->_len);
		}
		size_type	max_size(void) const {
			return (allocator_type().max_size());
		}
		void	resize(size_type n, value_type value = value_type()) {
			this->_cap = n;
			if (n > this->_cap)
				this->reserve(n);
			else if (n >= this->_len)
			{
				this->insert(this->end(), n -this->_len, value);
			}
			else
				this->erase(this->begin() + n, end());
		}
		size_type	capacity(void) const {
			return (this->_cap);
		}
		bool	empty(void) const {
			return (this->_len == 0);
		}
		void	reserve(size_type n) {
			if (n > max_size())
				throw std::length_error("vector");
			else if (n <= this->_cap)
				return ;
			std::allocator<value_type> alloc;
			alloc.allocate(n);
			pointer new_arr = alloc.allocate(n);

			for (size_type i = 0; i < this->_len; i ++) {
				alloc.construct(&new_arr[i], this->_arr[i]);
				alloc.destroy(&(this->_arr[i]));
			}
			alloc.deallocate(this->_arr, this->_cap);
			this->_arr = new_arr;
			this->_cap = n;
		}

		reference	operator[](size_type pos) {
			return (this->_arr[pos]);
		}
		const_reference	operator[](size_type pos) const {
			return (this->_arr[pos]);
		}
		reference	at(size_type pos) {
			if (pos >= this->_cap)
				throw std::out_of_range("vector");
			return (this->_arr[pos]);
		}
		const_reference	at(size_type pos) const{
			if (pos >= this->_cap)
				throw std::out_of_range("vector");
			return (this->_arr[pos]);
		}
		reference	front(void) {
			return (this->_arr[0]);
		}
		const_reference	front(void) const {
			return (this->_arr[0]);
		}
		reference	back(void) {
			return (this->_arr[this->_len - 1]);
		}
		const_reference	back(void) const {
			return (this->_arr[this->_len - 1]);
		}

		template<typename InputIt>
		void	assign(InputIt first, InputIt last) {
			this->clear();
			this->insert(this->begin(), first, last);
		}
		void	assign(size_type n, const value_type value=value_type()) {
			this->insert(this->begin(), n, value);
		}
		void	push_back(const value_type &value) {
			insert(this->end(), value);
		}
		void	pop_back(void) {
			erase(this->end() - 1);
		}
		// iterator	insert(iterator pos, const value_type &value) {
		// 	insert (pos, 1, value);
		// 	return (pos);
		// }
		iterator	insert(iterator pos, const value_type &value) {
			size_type	index = pos - this->_arr;
			this->reserve(this->_len + 1);
			std::allocator<value_type> alloc;
			for (difference_type i = this->_len - 1; i >= (difference_type)index; i--) {
				alloc.construct(&(this->_arr[i + 1]), this->_arr[i]);
				alloc.destroy(&(this->_arr[i]));
			}
			alloc.construct(&(this->_arr[index]), value);
			// *pos = value;
			pos = iterator(&this->_arr[index]);
			this->_len += 1;
			return (pos);
		}
		void	insert(iterator pos, size_type n, const value_type &value) {
			size_type	index = pos - this->_arr;
			if (!n)
				return ;
			this->reserve(this->_len + n);
			std::allocator<value_type> alloc;
			for (difference_type i = this->_len - 1; i >= (difference_type)index; i--) {
				alloc.construct(&(this->_arr[i + n]), this->_arr[i]);
				alloc.destroy(&(this->_arr[i]));
			}
			for (size_type i = (size_type)index; i < (size_type)index + n; i++) {
				alloc.construct(&(this->_arr[i]), value);
				// if (pos.base() != NULL && n == 1)
					// pos[i - index] = value;
			}
			this->_len += n;
		}
		template<typename InputIt>
		void	insert(iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value> :: type* = 0) {
			size_type	index = pos - this->_arr;
			difference_type n = ft::distance(first, last);
			if (!n)
				return ;
			this->reserve(this->_len + n);
			std::allocator<value_type> alloc;
			for (difference_type i = this->_len - 1; i >= (difference_type)index; --i) {
				alloc.construct(&(this->_arr[i + n]), this->_arr[i]);
				alloc.destroy(&(this->_arr[i]));
			}
			for (InputIt it = first; it != last; it++)
				alloc.construct(&(this->_arr[index++]), *it);
			this->_len += n;
		}
		iterator erase(iterator pos) {
			return (erase(pos, pos + 1));
		}
		iterator erase(iterator first, iterator last) {
			difference_type n = ft::distance(first, last);
			if (n <= 0)
				return (last);
			difference_type index = first - this->_arr;
			std::allocator<value_type> alloc;
			for (difference_type i = index; i < index + n; i++)
				alloc.destroy(&(this->_arr[i]));
			for (difference_type i = index + n ; i < (difference_type)this->_len; i++) {
				alloc.construct(&(this->_arr[i - n]), this->_arr[i]);
				alloc.destroy(&(this->_arr[i]));
			}
			this->_len -= n;
			return (first);
		}
		void	swap(_Self &other) {
			ft::swap(this->_arr, other._arr);
			ft::swap(this->_len, other._len);
			ft::swap(this->_cap, other._cap);
		}
		void	clear(void) {
			this->erase(this->begin(), this->end());
		}
		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}
		void	debug(void) {
			size_t i = 0;
			for (; i < this->_len; i ++)
				std::cout << "[" << this->_arr[i] << "]";
			for (; i < this->_cap; i++)
				std::cout << "[x]";
			std::cout << "end" << std::endl;;

		}
};
template<typename T>
bool operator==(vector<T> const &lhs, vector<T> const &rhs) {
	if (lhs.size() != rhs.size() || lhs.capacity() != lhs.capacity())
		return (false);
	return equal(lhs.begin(), lhs.end(), rhs.begin());
}
template<typename T>
bool operator!=(vector<T> const &lhs, vector<T> const &rhs) {
	return (!(lhs == rhs));
}
template <typename T>
bool operator<(const vector<T> &lhs, const vector<T> &rhs){
	return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
template <typename T>
bool operator<=(const vector<T> &lhs, const vector<T> &rhs){
	return !(lhs > rhs);
}
template <typename T>
bool operator>(const vector<T> &lhs, const vector<T> &rhs){
	return rhs < lhs;
}
template <typename T>
bool operator>=(const vector<T> &lhs, const vector<T> &rhs){
	return !(lhs < rhs);
}

template <typename T>
void swap(vector<T> &lhs, vector<T> &rhs){
	rhs.swap(lhs);
}
}

#endif