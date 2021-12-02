/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:46:49 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/30 17:28:07 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __VECTOR__
#define __VECTOR__

#include "Vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include <cstring>

namespace ft {
	
	template <typename _T, class _Alloc = std::allocator<_T> >
	class vector {
		
		public:
			typedef		_Alloc													allocator_type;
			typedef		_T														value_type;
			typedef		typename allocator_type::difference_type				difference_type;
			typedef		typename allocator_type::pointer						pointer;
			typedef		typename allocator_type::const_pointer					const_pointer;
			typedef		typename allocator_type::reference						reference;
			typedef		typename allocator_type::const_reference				const_reference;
			typedef		size_t													size_type;
			typedef		typename ft::vector_iterator<pointer>					iterator;
			typedef		typename ft::vector_iterator<const_pointer>				const_iterator;
			typedef		typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef		typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		protected:
			pointer			current_;
			size_type		size_;
			size_type		cap_;

		public:
			explicit vector (const allocator_type& _alloc = allocator_type()) {
				setContainer (0, _alloc);
			}
			
			explicit vector (size_type _n, const value_type& _val = value_type(), const allocator_type& _alloc = allocator_type()) {
				setContainer (_n, _alloc);
				while (_n--) {
					push_back (_val);
				}
			}

			template <class _InputIterator>
			vector (_InputIterator _first, _InputIterator _last, const allocator_type& _alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<_InputIterator>::value>::type* = 0) {
				difference_type distance = ft::distance(_first, _last);

				setContainer (distance, _alloc);
				for (; distance--;) { push_back(*_first++); }
			}
			
			vector (const vector& _x) { *this = _x; }

			vector&
			operator= (const vector& _x) {
				// const_iterator iter = _x.begin ();
				
				setContainer (_x.capacity ());
				memmove(current_, _x.current_, _x.size() * sizeof(_T));
				size_ = _x.size();
				// while (iter != _x.end ()) {		push_back (*iter++);	}
				
				return (*this);
			}

			~vector () { clear (); }



/* define : Iterators */

			iterator
			begin (void) {
				return iterator(current_);
			}

			const_iterator
			begin (void) const {
				return const_iterator (current_);
			}

			iterator
			end (void) {
				return iterator (current_ + size_);
			}

			const_iterator
			end (void) const {
				return const_iterator (current_ + size_);
			}

			reverse_iterator
			rbegin (void) {
				return reverse_iterator (end());
			}

			const_reverse_iterator
			rbegin (void) const {
				return const_reverse_iterator (end());
			}

			reverse_iterator
			rend (void) {
				return reverse_iterator (begin());
			}

			const_reverse_iterator
			rend (void) const {
				return const_reverse_iterator (begin());
			}




/* define : Capacity */

			size_type
			size (void) const {
				return size_;
			}

			size_type
			max_size (void) const {
				return allocator_type().max_size();
			}

			void
			resize (size_type _n, value_type _val = value_type()) {
				expand (_n);
				while (size () < _n) {
					push_back (_val);
				}
				while (_n < size ()) {
					pop_back ();
				}
			}

			size_type
			capacity (void) const {
				return cap_;
			}

			bool
			empty (void) const {
				return (begin () == end ());
			}

			void
			reserve (size_type _n) {
				expand (_n);
			}




/* define : Element access */

			reference
			operator[] (size_type _n) {
				return current_[_n];
			}

			const_reference
			operator[] (size_type _n) const {
				return current_[_n];
			}

			reference
			at (size_type _n) {
				if (_n < size ()) {
					return operator[](_n);
				}
				throw(std::out_of_range("vector"));
			}

			const_reference
			at (size_type _n) const {
				if (_n < size ()) {
					return operator[](_n);
				}
				throw(std::out_of_range("vector"));
			}

			reference
			front (void) {
				return operator[](0);
			}

			const_reference
			front (void) const {
				return operator[](0);
			}

			reference
			back (void) {
				return operator[](size() - 1);
			}

			const_reference
			back (void) const {
				return operator[](size() - 1);
			}




/* define : Modifiers */

			template <class _InputIterator>
			void
			assign (_InputIterator _first, _InputIterator _last, typename ft::enable_if<!ft::is_integral<_InputIterator>::value>::type* = 0) {
				clear();
				setContainer(ft::distance(_first, _last));

				while(_first != _last) {
					push_back(*_first++);
				}
			}

			void
			assign (size_type _n, const value_type& _val) {
				clear();
				setContainer(_n);

				while (_n--) {
					push_back(_val);
				}
			}

			void
			push_back (const value_type& _val) {
				expand(size() + 1);
				allocator_type().construct(current_ + size_, _val);
				++size_;
			}

			void
			pop_back (void) {
				--size_;
				allocator_type().destroy(const_cast<pointer>(current_ + size_));
			}

			iterator
			insert (iterator _position, const value_type& _val) {
				size_type 			offset 	= expand(size_ + 1);
				reverse_iterator 	from	= rbegin();
				reverse_iterator	to		= rbegin() - 1;

				size_ += 1;
				_position += offset;

				for (int i = 0; from.base() != _position; i++) {
					*to++ = *from++;
				}
				*_position = _val;
				
				return _position;
			}

			void
			insert (iterator _position, size_type _n, const value_type& _val) {
				size_type 			offset 	= expand(size_ + _n);
				reverse_iterator 	from	= rbegin();
				reverse_iterator	to		= rbegin() - _n;

				size_ += _n;
				_position += offset;

				for (int i = 0; from.base() != _position; i++) {
					*to++ = *from++;
				}
				while (_n--) {
					*_position++ = _val;
				}
			}

			template <class _InputIterator>
			void
			insert (iterator _position, _InputIterator _first, _InputIterator _last, typename ft::enable_if<!ft::is_integral<_InputIterator>::value>::type* = 0) {
				difference_type distance = ft::distance(_first, _last);
				size_type newSize = (size() + distance) < capacity() ? capacity() : (size() + distance);
				vector newvector (false, newSize);
				iterator iter = begin();

				while (iter != _position) {
					newvector.push_back(*iter++);
				}
				while (_first != _last) {
					newvector.push_back(*_first++);
				}
				while (iter != end()) {
					newvector.push_back(*iter++);
				}

				swap (newvector);
			}

			iterator
			erase (iterator _position) {
				iterator iter = begin();
				
				while (iter != _position) {
					++iter;
				}
				while ((iter + 1) != end ()) {
					swapElement(iter, iter + 1);
					iter++;
				}
				pop_back();
				
				return _position;
			}

			iterator
			erase (iterator _first, iterator _last) {
				iterator iter = begin();
				iterator backup = _first;
				difference_type offset = ft::distance(_first, _last);

				while (iter != _first) {
					iter++;
				}
				while ((iter + offset) != end()) {
					swapElement(iter, iter + offset);
					iter++;
				}
				while (offset--) {
					pop_back();
				}
				
				return backup;
			}

			void
			swap (vector& _x) {
				pointer tempCurrent = const_cast<pointer>(&*_x.begin());
				size_type tempSize = _x.size ();
				size_type tempCap = _x.capacity ();

				_x.current_ = current_;
				_x.size_ 	= size_;
				_x.cap_ 	= cap_;

				current_ 	= tempCurrent;
				size_ 		= tempSize;
				cap_ 		= tempCap;
			}

			void
			clear (void) {
				if (!empty())
				{
					while (begin() != end()) {
						pop_back();
					}
					allocator_type().deallocate(&*begin(), capacity());
					cap_ = 0;
				}
			}




/* define : Allocator */

			allocator_type
			get_allocator(void) const {
				return allocator_type();
			}






		private:

			explicit vector (bool _fill, size_type _n, const value_type& _val = value_type(), const allocator_type& _alloc = allocator_type()) {
				setContainer (_n, _alloc);
				
				if (_fill) {
					while (_n--) {
						push_back (_val);
					}
				}
			}
 

			void
			setContainer (size_type _n, const allocator_type& _alloc = allocator_type()) {
				try {
					allocator_type alloc = _alloc;
					current_ = _n ? alloc.allocate(_n) : 0;
					size_ = 0;
					cap_ = _n;
				}
				catch (...) {
					exit(ERROR_ALLOCATE_FAIL);
				}

			}

			size_type
			expand(size_type _n) {
				size_type offset = 0;

				if (capacity () < _n) {
					try {
						size_type newSize = capacity () * 2 < _n ? _n : capacity () * 2;
						size_type index = 0;
						value_type* newCurrent = allocator_type().allocate(newSize);

						offset = newCurrent - current_;
						while (index < size_) {
							*(newCurrent + index) = *(current_ + index);
							index++;
						}
						allocator_type().deallocate(current_, size_);
						current_ = newCurrent;
						cap_ = newSize;
					}
					catch (...) {
						exit(ERROR_ALLOCATE_FAIL);
					}
				}
				return offset;
			}

			void
			swapElement (iterator _iterator, value_type& _target) {
				value_type temp = _target;

				_target = *_iterator;
				*_iterator = temp;
			}

			void
			swapElement (value_type& _target, iterator _iterator) {
				value_type temp = _target;

				_target = *_iterator;
				*_iterator = temp;
			}

			void
			swapElement (iterator _iter0, iterator _iter1) {
				value_type temp = *_iter0;

				*_iter0 = *_iter1;
				*_iter1 = temp;
			}
	};

	template <typename _T, class _Alloc>
	bool
	operator== (const vector <_T, _Alloc>& _lhs, const vector <_T, _Alloc>& _rhs) {
		return ft::lexicographical_compare_equal (_lhs.begin (), _lhs.end (), _rhs.begin(), _rhs.end());
	}

	template <typename _T, class _Alloc>
	bool
	operator!= (const vector <_T, _Alloc>& _lhs, const vector <_T, _Alloc>& _rhs) {
		return !(_lhs == _rhs);
	}

	template <typename _T, class _Alloc>
	bool
	operator< (const vector <_T, _Alloc>& _lhs, const vector <_T, _Alloc>& _rhs) {
		return ft::lexicographical_compare_less (_lhs.begin (), _lhs.end (), _rhs.begin (), _rhs.end ());
	}

	template <typename _T, class _Alloc>
	bool
	operator<= (const vector <_T, _Alloc>& _lhs, const vector <_T, _Alloc>& _rhs) {
		return !(_rhs < _lhs);
	}

	template <typename _T, class _Alloc>
	bool
	operator> (const vector <_T, _Alloc>& _lhs, const vector <_T, _Alloc>& _rhs) {
		return (_rhs < _lhs);
	}

	template <typename _T, class _Alloc>
	bool
	operator>= (const vector <_T, _Alloc>& _lhs, const vector <_T, _Alloc>& _rhs) {
		return !(_lhs < _rhs);
	}

	template <typename _T, class _Alloc>
	void
	swap (vector <_T, _Alloc>& _x, vector <_T, _Alloc>& _y) {
		_x.swap(_y);
	}
}

#endif
