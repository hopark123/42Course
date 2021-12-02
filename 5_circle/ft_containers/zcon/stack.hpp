/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:13:51 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/29 16:45:51 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __STACK__
#define __STACK__

#include "vector.hpp"

namespace ft {

	template <class _T, class _Container = ft::vector<_T> >
	class stack {
		public:
			typedef		_Container									container_type;
			typedef		typename container_type::allocator_type		allocator_type;
			typedef		_T											value_type;
			typedef		typename allocator_type::difference_type	difference_type;
			typedef		typename allocator_type::pointer			pointer;
			typedef		typename allocator_type::const_pointer		const_pointer;
			typedef		typename allocator_type::reference			reference;
			typedef		typename allocator_type::const_reference	const_reference;
			typedef		size_t										size_type;

		protected:
			container_type	container;

		public:
			explicit stack (const container_type& _ctnr = container_type()) {
				container = _ctnr;
			}

			bool
			empty() const {
				return container.empty();
			}

			size_type
			size() const {
				return container.size();
			}

			value_type&
			top() {
				return *container.rbegin();
			}
			
			const value_type&
			top() const {
				return *container.rbegin();
			}

			void
			push (const value_type& _val) {
				container.push_back(_val);
			}

			void
			pop() {
				container.pop_back();
			}

		private:
			typedef		typename ft::vector_iterator<pointer>				iterator;
			typedef		typename ft::vector_iterator<const_pointer>			const_iterator;
			typedef		typename ft::reverse_iterator<pointer>				reverse_iterator;
			typedef		typename ft::reverse_iterator<const_pointer>		const_reverse_iterator;

			iterator				begin()				{ return NULL; }
			const_iterator			begin() const		{ return NULL; }
			iterator				end()				{ return NULL; }
			const_iterator			end() const			{ return NULL; }
			reverse_iterator		rbegin()			{ return NULL; }
			const_reverse_iterator	rbegin() const		{ return NULL; }
			reverse_iterator		rend()				{ return NULL; }
			const_reverse_iterator	rend() const		{ return NULL; }

			template<class _FA, class _FB> friend bool operator==(const stack<_FA, _FB>&, const stack<_FA, _FB>&);
			template<class _FA, class _FB> friend bool operator<(const stack<_FA, _FB>&, const stack<_FA, _FB>&);
	};

	template <class _T, class _Container>
	bool
	operator== (const stack<_T, _Container>& _lhs, const stack<_T, _Container>& _rhs) {
		return _lhs.container == _rhs.container;
	}

	template <class _T, class _Container>
	bool
	operator!= (const stack<_T, _Container>& _lhs, const stack<_T, _Container>& _rhs) {
		return !operator==(_lhs, _rhs);
	}

	template <class _T, class _Container>
	bool
	operator<  (const stack<_T, _Container>& _lhs, const stack<_T, _Container>& _rhs) {
		return _lhs.container < _rhs.container;
	}

	template <class _T, class _Container>
	bool
	operator>  (const stack<_T, _Container>& _lhs, const stack<_T, _Container>& _rhs) {
		return operator< (_rhs, _lhs);
	}

	template <class _T, class _Container>
	bool
	operator<= (const stack<_T, _Container>& _lhs, const stack<_T, _Container>& _rhs) {
		return !operator< (_rhs, _lhs);
	}

	template <class _T, class _Container>
	bool
	operator>= (const stack<_T, _Container>& _lhs, const stack<_T, _Container>& _rhs) {
		return !operator< (_lhs, _rhs);
	}
}

#endif
