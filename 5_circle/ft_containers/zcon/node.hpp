/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 17:00:43 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/07 20:55:13 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __NODE__
#define __NODE__

#include <iostream>

namespace ft {

	template <typename _T>
	struct node {
		typedef 	node*				pointer;
		typedef 	node&				reference;
		typedef		_T					value_type;

		size_t
		height;

		value_type*
		content_;

		pointer
		parent_;

		pointer
		left_;

		pointer
		right_;

		node(): height(0), parent_(NULL), left_(NULL), right_(NULL) {}

		void		increaseHeight	(void)		{	++height;	}
		void		decreaseHeight	(void)		{	--height;	}
		size_t		leftHeight		(void) 		{	return left_  ? left_->height  : 0;	}
		size_t		rightHeight		(void) 		{	return right_ ? right_->height : 0;	}
	};

	template <typename _T1, typename _T2>
	bool
	operator== (const typename ft::node<_T1>& _lhs, const typename ft::node<_T2>& _rhs) {
		return (_lhs.content_ == _rhs.content_);
	}

	template <typename _T1, typename _T2>
	bool
	operator!= (const typename ft::node<_T1>& _lhs, const typename ft::node<_T2>& _rhs) {
		return !(_lhs == _rhs);
	}

	template <typename _T1, typename _T2>
	bool
	operator< (const typename ft::node<_T1>& _lhs, const typename ft::node<_T2>& _rhs) {
		return (*_lhs.content_ < *_rhs.content_);
	}

	template <typename _T1, typename _T2>
	bool
	operator<= (const typename ft::node<_T1>& _lhs, const typename ft::node<_T2>& _rhs) {
		return !(_rhs < _lhs);
	}

	template <typename _T1, typename _T2>
	bool
	operator> (const typename ft::node<_T1>& _lhs, const typename ft::node<_T2>& _rhs) {
		return !(_lhs <= _rhs);
	}

	template <typename _T1, typename _T2>
	bool
	operator>= (const typename ft::node<_T1>& _lhs, const typename ft::node<_T2>& _rhs) {
		return !(_lhs < _rhs);
	}
}


#endif
