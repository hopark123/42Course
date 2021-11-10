/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:48:07 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/03 21:16:18 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __TYPE_TRAITS__
#define __TYPE_TRAITS__

namespace ft {
	
/* define: enable if */
	template <bool _B, typename _T = void>
	struct
	enable_if					{};

	template <typename _T>
	struct
	enable_if<true, _T>			{ typedef _T type; };

/* define: is integral */
	template <typename _T>
	struct
	is_integral					{ const static bool value = false; };

	template <>
	struct
	is_integral<int> 			{ const static bool value = true; };

/* define: is constant */
	template <typename _T>
	struct
	is_constant					{ const static bool value = false; };
	
	template <typename _T>
	struct
	is_constant <const _T>		{ const static bool value = true; };

/* define: remove const */
	template <typename _T>
	struct
	remove_const				{ typedef _T type; };

	template <typename _T>
	struct
	remove_const<const _T>		{ typedef _T type; };

/* define: attach const */
	template <typename _T>
	struct
	attach_const				{ typedef const _T type; };

	template <typename _T>
	struct
	attach_const <const _T>		{ typedef const _T type; };

/* define: to const */
	template <typename _T>
	struct 
	to_const 					{ typedef const _T type; };

	template <typename _T>
	struct 
	to_const <const _T>			{ typedef const _T type; };

/* define: choice type */
	template <bool _B, typename _T1, typename _T2>
	struct
	which_type					{ typedef _T2 type; };

	template <typename _T1, typename _T2>
	struct
	which_type<true, _T1, _T2>	{ typedef _T1 type; };

/* define: is same */
	template <typename _T1, typename _T2>
	struct
	is_same						{ const static bool value = false; };

	template <typename _T>
	struct
	is_same <_T, _T>			{ const static bool value = true; };

/* define: is same */
	template <typename _T1, typename _T2>
	struct
	enable_put							{ const static bool value = true; };

	template <typename _Lvalue, typename _Rvalue>
	struct
	enable_put <const _Lvalue, _Rvalue> { const static bool value = false; };

/* define: rebind */
	template <class _T>
	struct
	rebind						{ typedef std::allocator<_T> alloc; };
}




#endif
