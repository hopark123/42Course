/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjpark <hjpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 20:46:32 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/29 13:53:24 by hjpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ITERATOR_TRAITS__
#define __ITERATOR_TRAITS__

#include <memory>
#include <iostream>
#include "type_traits.hpp"

namespace ft {

/* define: iterator tags */
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	typedef input_iterator_tag			II;
	typedef output_iterator_tag			OI;
	typedef forward_iterator_tag		FI;
	typedef bidirectional_iterator_tag	BI;
	typedef random_access_iterator_tag	RI;


/* define: iterator traits */
	template <typename _Iterator>
	struct iterator_traits {
		typedef typename _Iterator::iterator_category	iterator_category;
		typedef typename _Iterator::value_type			value_type;
		typedef typename _Iterator::difference_type		difference_type;
		typedef typename _Iterator::reference			reference;
		typedef typename _Iterator::pointer				pointer;
		typedef typename _Iterator::const_reference		const_reference;
		typedef typename _Iterator::const_pointer		const_pointer;

	};

	template <typename _T>
	struct iterator_traits <_T*> {
		typedef		random_access_iterator_tag				iterator_category;
		typedef		_T										value_type;
		typedef		ptrdiff_t								difference_type;
		typedef		_T*										pointer;
		typedef		_T&										reference;
	};

/* define: node iterator traits */
	template <typename _N>
	struct node_iterator_traits  {
		typedef		bidirectional_iterator_tag				iterator_category;
		typedef		typename _N::pair						value_type;
		typedef		ptrdiff_t								difference_type;
		typedef		value_type*								pointer;
		typedef		value_type&								reference;
	};

	template <typename _N>
	struct node_iterator_traits <_N*>  {
		typedef		bidirectional_iterator_tag				iterator_category;
		typedef		typename _N::pair						value_type;
		typedef		ptrdiff_t								difference_type;
		typedef		value_type*								pointer;
		typedef		value_type&								reference;
	};


}


#endif
