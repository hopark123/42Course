/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:49:38 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/03 20:16:15 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __REVERSE_ITERATOR__
#define __REVERSE_ITERATOR__

#include "iterator_utils.hpp"


namespace ft {
	
	template <class _Iter>
	class reverse_iterator {
		public:
			typedef		typename iterator_traits<_Iter>::iterator_category		iterator_category;
			typedef		typename iterator_traits<_Iter>::value_type				value_type;
			typedef		typename iterator_traits<_Iter>::difference_type		difference_type;
			typedef		typename iterator_traits<_Iter>::reference				reference;
			typedef		typename iterator_traits<_Iter>::pointer				pointer;

		protected:
			_Iter		current;
		
		public:
			reverse_iterator () : current(_Iter()) {}

			explicit reverse_iterator (_Iter _it) : current(_it) {}
			
			template <typename _U>
			reverse_iterator (const reverse_iterator<_U>& _it) : current(_it.base()) {}
			
			template <typename _U>
			reverse_iterator&
			operator= (const reverse_iterator<_U>& _it) {
				current = _it.base();
				return *this;
			}
			
			~reverse_iterator() {}

			_Iter
			base() const {
				return current;
			}
			
			reference
			operator*(void) const {
				_Iter temp = current;
				return *(--temp);
			}
			
			pointer
			operator-> (void) const {
				return &operator*();
			}

			reverse_iterator&
			operator++(void) {
				--current;
				return *this;
			}

			reverse_iterator
			operator++(int) {
				reverse_iterator temp(*this);
				--current;
				return temp;
			}

			reverse_iterator&
			operator--(void) {
				++current;
				return *this;
			}

			reverse_iterator
			operator--(int) {
				reverse_iterator temp(*this);
				++current;
				return temp;
			}

			reverse_iterator
			operator+ (difference_type _n) const {
				return reverse_iterator(current - _n);
			}

			reverse_iterator&
			operator+= (difference_type _n) {
				current -= _n;
				return *this;
			}

			reverse_iterator
			operator- (difference_type _n) const {
				return reverse_iterator(current + _n);
			}

			reverse_iterator&
			operator-= (difference_type _n) {
				current += _n;
				return *this;
			}

			reference
			operator[] (difference_type _n) const {
				return *(*this + _n);
			}
	};

	template <class _Iter1, class _Iter2>
	bool
	operator== (const reverse_iterator<_Iter1>& _it1, const reverse_iterator<_Iter2>& _it2) {
		return _it1.base() == _it2.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator!= (const reverse_iterator<_Iter1>& _it1, const reverse_iterator<_Iter2>& _it2) {
		return _it1.base() != _it2.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator< (const reverse_iterator<_Iter1>& _it1, const reverse_iterator<_Iter2>& _it2) {
		return _it1.base() > _it2.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator> (const reverse_iterator<_Iter1>& _it1, const reverse_iterator<_Iter2>& _it2) {
		return _it1.base() < _it2.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator>= (const reverse_iterator<_Iter1>& _it1, const reverse_iterator<_Iter2>& _it2) {
		return _it1.base() <= _it2.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator<= (const reverse_iterator<_Iter1>& _it1, const reverse_iterator<_Iter2>& _it2) {
		return _it1.base() >= _it2.base();
	}

	template <class _Iter1, class _Iter2>
	typename reverse_iterator<_Iter1>::difference_type
	operator- (const reverse_iterator<_Iter1>& _it1, const reverse_iterator<_Iter2>& _it2) {
		return _it2.base() - _it1.base();
	}

	template <class _Iter>
	reverse_iterator<_Iter>
	operator+ (typename reverse_iterator<_Iter>::difference_type _n, const reverse_iterator<_Iter>& _it) {
		return reverse_iterator<_Iter>(_it.base() - _n);
	}
}

#endif
