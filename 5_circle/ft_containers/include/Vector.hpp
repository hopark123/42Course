#ifndef _VECTOR_
# define _VECTOR_

# include <iostream>
# include "ft_stl.hpp"
# include "Vector_Iterator.hpp"

namespace ft {
template<typename T, class Alloc = std::allocator<T> >
class Vector {
	public :
		typedef T							value_type;
		typedef Alloc						allocator_type;
		typedef std::ptrdiff_t				difference_type;
		typedef size_t						size_type;

		typedef T&							reference;
		typedef T*							pointer;
		typedef const T&					const_reference;
		typedef const T*					const_pointer;

		typedef VectorIterator<T>			iterator;
		typedef VectorIterator<const T>		const_iterator;
		typedef VectorRevIterator<T>		reverse_iterator;
		typedef VectorRevIterator<const T>	const_reverse_iterator;
	
	private :
		typedef Vector<T>					_Self;
		pointer								_arr;
		size_type							_len;
		size_type							_cap;


	public :
		Vector() : _arr(NULL), _len(0), _cap(0) {}
		Vector(size_type n, const_reference &value = value_type()) : _arr(NULL), _len(0), _cap(0){
			this->insert(begin(), n, value);
		}
		Vector(iterator first, iterator last) : _arr(NULL), _len(0), _cap(0){
			this->insert(this->begin(), first, last);
		}
		Vector(const _Self &other) : _arr(NULL), _len(0), _cap(0){
			this->insert(this->begin(), other.begin(), other.end());
		}
		~Vector(){
			this->clear();
		}
		_Self const &operator=(const _Self &other){
			this->clear();
			this->insert(this->begin(), other.begin(), other.end());
		}

		iterator	begin(void){
			return (iterator(this->_arr));
		}
		const_iterator	begin(void) const{
			return (iterator(this->_arr));
		}
		iterator	end(void){
			return (iterator(this->_arr + this->_len));
		}
		const_iterator	end(void) const{
			return (iterator(this->_arr + this->len));
		}

		reverse_iterator	rbegin(void){
			return (reverse_iterator(this->_arr + this->_len));
		}
		const_reverse_iterator	rbegin(void) const{
			return (reverse_iterator(this->_arr + this->_len));
		}
		reverse_iterator	rend(void){
			return (reverse_iterator(this->_arr));
		}
		const_reverse_iterator	rend(void) const{
			return (reverse_iterator(this->ptr));
		}

		size_type	size(void) const{
			return (this->_len);
		}
		size_type	max_size(void) const{
			return (std::numeric_limits<difference_type>::max() / sizeof(T));
		}
		void	resize(size_type n, value_type value = value_type()){
			if (n > this->_cap)
				this->reserve(n);
			else if (n >= this->_len)
				this->insert(this->end(), n - this->_len, value);
			else
				this->erase(this->begin() + n, end());
		}
		size_type	capacity(void) const{
			return (this->_cap);
		}
		bool	empty(void){
			return (this->_len == 0);
		}
		

		void		reserve(size_type n){
			if (n > max_size())
				throw std::length_error("vector");
			else if (n <= this->_cap)
				return ;
			
			std::allocator<value_type> alloc;

			value_type *new_arr = alloc.allocate(n);
			for (int i = 0; i < this->_len; i ++)
			{
				alloc.construct(&new_arr[i], this->_arr[i]);
				alloc.destroy(&(this->_arr[i]));
			}
			alloc.deallocate(this->_arr, this->_cap);
			this->_arr = new_arr;
			this->_cap = n;
		}

		reference	operator[](size_type pos){
			return (this->_arr[pos]);
		}
		const_reference	operator[](size_type pos) const{
			return (this->arr[pos]);
		}
		reference	at(size_type pos){
			if (pos >= this->_cap)
				throw std::out_of_range("vector");
			return (this->_arr[pos]);
		}
		reference	front(void){
			return (this->_arr[0]);
		}
		const_reference	front(void) const{
			return (this->_arr[0]);
		}
		reference	back(void){
			return (this->_arr[this->len - 1]);
		}
		const_reference	back(void) const{
			return (this->_arr[this->len - 1]);
		}

		template<typename InputIt>
		void	assign(InputIt first, InputIt last){
			this->clear();
			this->insert(this->begin(), first, last);
		}
		void	assign(size_type n, const value_type value = value_type()){
			this->insert(this->begin(), n, value);
		}
		void	push_back(const value_type &value){
			insert(this->end(), value);
		}
		void	pop_back(void){
			erase(this->end() - 1);
		}
		iterator	insert(iterator pos, const value_type &value){
			insert(pos, 1, value);
			return (++pos);
		}
		void	insert(iterator pos, size_type n, const value_type &value){
			if (!n)
				return ;
			size_type	index = pos - this->_arr;
			this->reserve(this->_len + n);
			std::allocator<value_type>	alloc;
			for (difference_type i = this->_len; i >= (difference_type)index; i--)
			{
				alloc.construct(&(this->_arr[i + n]), this->_arr[i]);
				alloc.destroy(&(this->_arr[i]));

			}
			for (difference_type i = index; i < index + n; i++){
				alloc.construct(&(this->_arr[i]), value);
			}
			this->_len += n;
		}
		template<typename InputIt>
		void	insert(iterator pos, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value> ::type* = 0){
			
			difference_type	index = pos - this->_arr;
			difference_type	n = last - first;
			if (!n)
				return ;
			this->reserve(this->_len + n);
			std::allocator<value_type>	alloc;
			for (difference_type i = this->_len - 1; i >= index; --i)
			{
				alloc.construct(&(this->_arr[i + n]), this->_arr[i]);
				alloc.destroy(&(this->_arr[i]));
			}
			for (InputIt it = first; it != last; it++)
				alloc.construct(&(this->_arr[index++]), it);
			this->_len += n;
		}
		iterator	erase(iterator pos){
			return (erase(pos, pos + 1));
		}
		iterator	erase(iterator first, iterator last){
			difference_type n = last - first;
			if (n <= 0)
				return last;
			difference_type index = first - this->_arr;
			std::allocator<value_type> alloc;
			for (difference_type i = index; i < index + n; i++)
				alloc.destroy(&this->_arr[i]);
			for (difference_type i = index + n; i < this->_len; i++){
				alloc.construct(&this->_arr[i - n], this->_arr[i]);
				alloc.destroy(&this->_arr[i]);
			}
			this->_len -= n;
		return (first);
		}
		void	swap(_Self &other){
			std::swap(this->_arr, other._arr);
			std::swap(this->_len, other._len);
			std::swap(this->_cap, other._cap);
		}
		void	clear(void){
			this->erase(this->begin(), this->end());
		}
};
template<typename T>
bool operator==(Vector<T> const &lhs, Vector<T> const &rhs){
	if (lhs.size() != rhs.size())
		return (false);
	for (size_t i = 0; i < lhs.size(); i ++)
	{
		if (lhs[i] != rhs[i])
			return (false);
	}
	return (true);
}
template<typename T>
bool operator!=(Vector<T> const &lhs, Vector<T> const &rhs){
	return (!(lhs == rhs));
}

// template<typename T>
// bool operator==(Vector<T> const &lhs, Vector<T> const &rhs){
// }
}

#endif