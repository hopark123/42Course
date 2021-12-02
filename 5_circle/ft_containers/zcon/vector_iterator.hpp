/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 03:58:11 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/29 21:12:54 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#ifndef __VECTOR_ITERATOR__
#define __VECTOR_ITERATOR__

#include "iterator_utils.hpp"


namespace ft {

	template <typename _T>
	class vector_iterator {

		public:
			typedef		typename iterator_traits<_T>::iterator_category	iterator_category;
			typedef		typename iterator_traits<_T>::value_type		value_type;
			typedef		typename iterator_traits<_T>::difference_type	difference_type;
			typedef		typename iterator_traits<_T>::pointer			pointer;
			typedef		typename iterator_traits<_T>::reference			reference;


		protected:
			_T
			current;

		public:
			vector_iterator (): current(_T()) {}

			explicit vector_iterator (_T _t): current(_t) {}
			
			template <typename _U>
			vector_iterator (const vector_iterator<_U>& _it, typename ft::enable_if<!ft::is_integral<_U>::value>::type* = 0) : current(_it.base()) {}

			template <typename _U>
			vector_iterator&
			operator= (const vector_iterator<_U>& _it) {
				current = _it.base();
				return *this;
			}
			
			~vector_iterator () {}



			_T
			base(void) const {
				return current;
			}

			reference
			operator* (void) const {
				return *current;
			}

			pointer
			operator-> (void) const {
				return current;
			}

			vector_iterator&
			operator++ (void) {
				++current;
				return *this;
			}

			vector_iterator
			operator++ (int) {
				vector_iterator temp(*this);
				++(*this);
				return temp;
			}

			vector_iterator&
			operator-- (void) {
				--current;
				return *this;
			}

			vector_iterator
			operator-- (int) {
				vector_iterator temp(*this);
				--(*this);
				return temp;
			}

			vector_iterator
			operator+ (difference_type _n) const {
				vector_iterator temp(*this);
				temp += _n;
				return temp;
			}

			vector_iterator
			operator+= (difference_type _n) {
				current += _n;
				return *this;
			}

			vector_iterator
			operator- (difference_type _n) const {
				vector_iterator temp(*this);
				temp -= _n;
				return temp;
			}

			vector_iterator
			operator-= (difference_type _n) {
				current -= _n;
				return *this;
			}

			reference
			operator[] (difference_type _n) const {
				return current[_n];
			}
	};
	
	template <class _Iter1, class _Iter2>
	bool
	operator== (const vector_iterator<_Iter1>& _it1, const vector_iterator<_Iter2>& _it2) {
		return _it1.base() == _it2.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator< (const vector_iterator<_Iter1>& _it1, const vector_iterator<_Iter2>& _it2) {
		return _it1.base() < _it2.base();
	}

	template <class _Iter1, class _Iter2>
	bool
	operator!= (const vector_iterator<_Iter1>& _it1, const vector_iterator<_Iter2>& _it2) {
		return !(_it1 == _it2);
	}

	template <class _Iter1, class _Iter2>
	bool
	operator> (const vector_iterator<_Iter1>& _it1, const vector_iterator<_Iter2>& _it2) {
		return _it2 < _it1;
	}

	template <class _Iter1, class _Iter2>
	bool
	operator>= (const vector_iterator<_Iter1>& _it1, const vector_iterator<_Iter2>& _it2) {
		return !(_it1 < _it2);
	}

	template <class _Iter1, class _Iter2>
	bool
	operator<= (const vector_iterator<_Iter1>& _it1, const vector_iterator<_Iter2>& _it2) {
		return !(_it2 < _it1);
	}

	template <class _T>
	bool
	operator!= (const vector_iterator<_T>& _it1, const vector_iterator<_T>& _it2) {
		return !(_it1 == _it2);
	}

	template <class _T>
	bool
	operator> (const vector_iterator<_T>& _it1, const vector_iterator<_T>& _it2) {
		return _it2 < _it1;
	}

	template <class _T>
	bool
	operator>= (const vector_iterator<_T>& _it1, const vector_iterator<_T>& _it2) {
		return !(_it1 < _it2);
	}

	template <class _T>
	bool
	operator<= (const vector_iterator<_T>& _it1, const vector_iterator<_T>& _it2) {
		return !(_it2 < _it1);
	}

	template <class _Iter1, class _Iter2>
	typename vector_iterator<_Iter1>::difference_type
	operator- (const vector_iterator<_Iter1>& _it1, const vector_iterator<_Iter2>& _it2) {
		return _it1.base() - _it2.base();
	}

	template <class _Iter>
	vector_iterator<_Iter>
	operator+ (typename vector_iterator<_Iter>::difference_type _n, const vector_iterator<_Iter>& _it) {
		return vector_iterator<_Iter>(_it.base() + _n);
	}
}

#endif
