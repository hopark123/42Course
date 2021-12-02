/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_utils.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 00:41:05 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/29 12:39:30 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ITERATOR_UTILS__
#define __ITERATOR_UTILS__

#include "error_define.hpp"
#include "iterator_traits.hpp"
#include <iostream>
#include <typeinfo>

namespace ft {

	template <class _InputIt1, class _InputIt2>
	bool
	lexicographical_compare_equal (_InputIt1 _first1, _InputIt1 _last1, _InputIt2 _first2, _InputIt2 _last2 ) {
		while ((_first1 != _last1) && (_first2 != _last2)) {
			if (*_first1++ != *_first2++) {
				return false;
			}
    	}
		return (_first1 == _last1) && (_first2 == _last2);
	}

	template< class _InputIt1, class _InputIt2, class _Compare >
	bool
	lexicographical_compare_equal (_InputIt1 _first1, _InputIt1 _last1, _InputIt2 _first2, _InputIt2 _last2, _Compare _comp ) {
		while ((_first1 != _last1) && (_first2 != _last2)) {
			if (!_comp(*_first1++, *_first2++)) {
				return false;
			}
		}
		return (_first1 == _last1) && (_first2 == _last2);
	}

	template <class _InputIt1, class _InputIt2>
	bool
	lexicographical_compare_less (_InputIt1 _first1, _InputIt1 _last1, _InputIt2 _first2, _InputIt2 _last2 ) {
		while ((_first1 != _last1) && (_first2 != _last2)) {
			if (*_first1 < *_first2) return true;
			if (*_first2 < *_first1) return false;
			_first1++, _first2++;
    	}
		return (_first1 == _last1) && (_first2 != _last2);
	}

	template< class _InputIt1, class _InputIt2, class _Compare >
	bool
	lexicographical_compare_less (_InputIt1 _first1, _InputIt1 _last1, _InputIt2 _first2, _InputIt2 _last2, _Compare _comp ) {
		while ((_first1 != _last1) && (_first2 != _last2)) {
			if (_comp(*_first1, *_first2)) return true;
			if (_comp(*_first2, *_first1)) return false;
			_first1++, _first2++;
		}
		return (_first1 == _last1) && (_first2 != _last2);
	}

	template <typename _T>
	typename iterator_traits<_T>::difference_type
	__distance (_T _first, _T _last, II) {
		typename iterator_traits<_T>::difference_type distance = 0;
		while (_first != _last) { ++_first, ++distance; }
		return distance;
	}

	template <typename _T>
	typename iterator_traits<_T>::difference_type
	__distance (_T _first, _T _last, RI) {
		return &*_last - &*_first;
	}
	
	template <typename _T>
	typename iterator_traits<_T>::difference_type
	distance (_T _first, _T _last) {
		return __distance(_first, _last, typename iterator_traits<_T>::iterator_category());
	}

	template <typename _T1, typename _T2>
	typename iterator_traits<_T1>::difference_type
	__distance2 (_T1 _first, _T2 _last, II, II) {
		typename iterator_traits<_T1>::difference_type distance = 0;
		while (_first != _last) { ++_first, ++distance; }
		return distance;
	}

	template <typename _T1, typename _T2>
	typename iterator_traits<_T1>::difference_type
	__distance2 (_T1 _first, _T2 _last, RI, RI) {
		return &*_last - &*_first;
	}
	
	template <typename _T1, typename _T2>
	typename iterator_traits<_T1>::difference_type
	distance2 (_T1 _first, _T2 _last) {
		return __distance2(_first, _last, typename iterator_traits<_T1>::iterator_category(), typename iterator_traits<_T2>::iterator_category());
	}

	/* ++ and -- is need to define. to bidirectional */
	/* random access is safe anyway */
	// template <typename _T>
	// void next (_T& _t) { advance(_t, 1); }

	// template <typename _T>
	// void prev (_T& _t) { advance(_t, -1); }

	// template <typename _T>
	// void rnext (_T& _t) { prev(_t); }

	// template <typename _T>
	// void rprev (_T& _t) { next(_t); }

	template <typename _T1, typename _T2>
	struct pair;

	template <typename _T1, typename _T2>
	typename ft::pair<_T1, _T2>
	make_pair(_T1 _first, _T2 _second) {
		return typename ft::pair<_T1, _T2>(_first, _second);
	}

	template <typename _T1, typename _T2>
	struct pair {
		_T1 first;
		_T2 second;

		typedef _T1 first_arg_type;
		typedef _T2 second_arg_type;

		pair<_T1, _T2>(): first(), second() {}
		
		pair<_T1, _T2>(const _T1& _first, const _T2& _second): first(_first), second(_second) {}
		
		pair<_T1, _T2>(const pair<_T1, _T2>& _pair, typename ft::enable_if<!ft::is_integral<ft::pair<_T1, _T2> >::value>::type* = 0): first(_pair.first), second(_pair.second) {}

		pair<_T1, _T2>& operator= (const typename ft::pair<_T1, _T2>& _pair) {
			first  = _pair.first;
			second = _pair.second;
			return *this;
		}

		~pair() {}

	};


	template <typename _U, typename _V>
	bool
	operator== (const typename ft::pair<_U, _V>& _lhs, const typename ft::pair<_U, _V>& _rhs) {
		return ((_lhs.first == _rhs.first) && (_lhs.second == _rhs.second));
	}

	template <typename _U, typename _V>
	bool
	operator!= (const typename ft::pair<_U, _V>& _lhs, const typename ft::pair<_U, _V>& _rhs) {
		return !(_lhs == _rhs);
	}

	template <typename _U, typename _V>
	bool
	operator< (const typename ft::pair<_U, _V>& _lhs, const typename ft::pair<_U, _V>& _rhs) {
		if (_lhs.first == _rhs.first) { return _lhs.second < _rhs.second; }
		return _lhs.first < _rhs.first;
	}

	template <typename _U, typename _V>
	bool
	operator> (const typename ft::pair<_U, _V>& _lhs, const typename ft::pair<_U, _V>& _rhs) {
		return (_rhs < _lhs);
	}

	template <typename _U, typename _V>
	bool
	operator>= (const typename ft::pair<_U, _V>& _lhs, const typename ft::pair<_U, _V>& _rhs) {
		return !(_lhs < _rhs);
	}

	template <typename _U, typename _V>
	bool
	operator<= (const typename ft::pair<_U, _V>& _lhs, const typename ft::pair<_U, _V>& _rhs) {
		return !(_rhs < _lhs);
	}

}

#endif
