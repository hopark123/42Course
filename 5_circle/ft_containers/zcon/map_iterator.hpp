/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 15:32:13 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/06 16:57:01 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MAP_ITERATOR__
#define __MAP_ITERATOR__

#include "iterator_utils.hpp"



namespace ft {

	template <typename _N, typename _C>
	struct const_map_iterator;
	
	template <typename _N, typename _C>
	struct map_iterator {

		public:
			typedef		bidirectional_iterator_tag					iterator_category;
			typedef		typename _N::value_type						value_type;
			typedef		typename value_type::first_arg_type			key_type;
			typedef		typename value_type::second_arg_type		mapped_type;
			typedef		value_type*									pointer;
			typedef		value_type&									reference;
			typedef		ptrdiff_t									difference_type;
			typedef		typename ft::rebind<value_type>::alloc		allocator_type;

		private:
			typedef		_C											key_compare;
			typedef		_N											node;
			typedef		node*										node_pointer;
			typedef		node&										node_reference;
			typedef		typename ft::rebind<node>::alloc			node_allocator_type;

			node_pointer
			node_;

			key_compare
			compare;



		public:	// change to private

			map_iterator() {}

			template <typename _K, typename _M>
			map_iterator(const _K& _key, const _M& _mapped) {
				node_ = new node();
				node_->content_ = new value_type(static_cast<const key_type>(_key), static_cast<mapped_type>(_mapped));
				node_->height = 0;
			}

			map_iterator(const node_pointer& _node_pointer, typename ft::enable_if<!ft::is_same<node_pointer, map_iterator>::value>::type* = 0) {
				node_ = _node_pointer;
			}

			map_iterator(const map_iterator& _iter) {
				*this = _iter;
			}

			map_iterator&
			operator= (const map_iterator& _iter) {
				node_ = _iter.node_;
				return *this;
			}

			pointer
			operator-> (void) const {
				return node_->content_;
			}

			reference
			operator* (void) {
				return *operator->();
			}

			map_iterator&
			operator++ (void) {
				next();
				return *this;
			}

			map_iterator
			operator++ (int) {
				map_iterator temp(*this);
				++(*this);
				return temp;
			}

			map_iterator&
			operator-- (void) {
				prev();
				return *this;
			}

			map_iterator
			operator-- (int) {
				map_iterator temp(*this);
				--(*this);
				return temp;
			}

		private:

			node
			base(void) const {
				return *node_;
			}

			node_pointer
			getNodePtr(void) const {
				return node_;
			}

			

			node_pointer
			next(void) {
				node_pointer snapshot = node_;
				moreChildNode();
				if (node_ == snapshot) {
					moreParentNode();
				}
				return node_;
			}

			node_pointer
			prev(void) {
				node_pointer snapshot = node_;
				lessChildNode();
				if (node_ == snapshot) {
					lessParentNode();
				}
				return node_;
			}

			node_pointer
			moreParentNode(void) {
				while (node_->parent_) {
					if (compare(node_->content_->first, node_->parent_->content_->first)) {
						node_ = node_->parent_;
						break;
					}
					node_ = node_->parent_;
				}
				return node_;
			}

			node_pointer
			lessParentNode(void) {
				while (node_->parent_) {
					if (compare(node_->parent_->content_->first, node_->content_->first)) {
						node_ = node_->parent_;
						break;
					}
					node_ = node_->parent_;
				}

				return node_;
			}

			node_pointer
			moreChildNode(void) {
				if (node_->right_ && node_ != node_->right_) {
					node_ = node_->right_;
					node_ = leftEndNode(node_);
				}

				return node_;
			}

			node_pointer
			lessChildNode(void) {
				if (node_->left_ && node_ != node_->left_) {
					node_ = node_->left_;
					node_ = rightEndNode(node_);
				}
				return node_;
			}

			node_pointer
			leftEndNode(node_pointer& _from) {
				while (_from->left_) {
					_from = _from->left_;
				}
				return _from;
			}

			node_pointer
			rightEndNode(node_pointer& _from) {
				while (_from->right_) { _from = _from->right_; }
				return _from;
			}

			template <class _I1, class _I2, class _KC> friend bool operator== (const map_iterator<_I1, _KC>&, const map_iterator<_I2, _KC>&);
			template <class _I1, class _I2, class _KC> friend bool operator== (const map_iterator<_I1, _KC>&, const const_map_iterator<_I2, _KC>&);
			template <class _I1, class _I2, class _KC> friend bool operator== (const const_map_iterator<_I1, _KC>&, const map_iterator<_I2, _KC>&);

			template <class _I1, class _I2, class _KC> friend bool operator<  (const map_iterator<_I1, _KC>&, const map_iterator<_I2, _KC>&);
			template <class _I1, class _I2, class _KC> friend bool operator<  (const const_map_iterator<_I1, _KC>&, const map_iterator<_I2, _KC>&);
			template <class _I1, class _I2, class _KC> friend bool operator<  (const map_iterator<_I1, _KC>&, const const_map_iterator<_I2, _KC>&);

			template<class, class, class, class> friend struct tree;
			template<class, class, class, class> friend class map;
			template<class, class> friend struct const_map_iterator;
	};







	template <typename _N, typename _C>
	struct const_map_iterator {

		public:
			typedef		bidirectional_iterator_tag					iterator_category;
			typedef		typename _N::value_type						value_type;
			typedef		typename value_type::first_arg_type			key_type;
			typedef		typename value_type::second_arg_type		mapped_type;
			typedef		const value_type*							pointer;
			typedef		const value_type&							reference;
			typedef		ptrdiff_t									difference_type;
			typedef		typename ft::rebind<value_type>::alloc		allocator_type;

		private:
			typedef		_C											key_compare;
			typedef		_N											node;
			typedef		node*										node_pointer;
			typedef		node&										node_reference;
			typedef		typename ft::rebind<node>::alloc			node_allocator_type;

			node_pointer
			node_;

			key_compare
			compare;



		public:

			const_map_iterator() {}

			template <typename _K, typename _M>
			const_map_iterator(const _K& _key, const _M& _mapped) {
				node_ = new node();
				node_->content_ = new value_type(static_cast<const key_type>(_key), static_cast<mapped_type>(_mapped));
				node_->height = 0;
			}

			const_map_iterator(const node_pointer& _node_pointer, typename ft::enable_if<!ft::is_same<node_pointer, const_map_iterator>::value>::type* = 0): node_(_node_pointer) {}

			const_map_iterator(const map_iterator<_N, _C>& _iter): node_(_iter.getNodePtr()), compare(_iter.compare) {}

			const_map_iterator(const const_map_iterator& _iter): node_(_iter.getNodePtr()), compare(_iter.compare) {}

			const_map_iterator&
			operator= (const const_map_iterator& _iter) {
				node_ = _iter.node_;
				return *this;
			}

			const_map_iterator&
			operator= (const map_iterator<_N, _C>& _iter) {
				node_ = _iter.node_;
				return *this;
			}

			pointer
			operator-> (void) const {
				return node_->content_;
			}

			reference
			operator* (void) const {
				return *operator->();
			}

			const_map_iterator&
			operator++ (void) {
				next();
				return *this;
			}

			const_map_iterator
			operator++ (int) {
				const_map_iterator temp(*this);
				++(*this);
				return temp;
			}

			const_map_iterator&
			operator-- (void) {
				prev();
				return *this;
			}

			const_map_iterator
			operator-- (int) {
				const_map_iterator temp(*this);
				--(*this);
				return temp;
			}

		private:

			node
			base(void) const {
				return *node_;
			}

			node_pointer
			getNodePtr(void) const {
				return node_;
			}

			

			node_pointer
			next(void) {
				node_pointer snapshot = node_;
				moreChildNode();
				if (node_ == snapshot) {
					moreParentNode();
				}
				return node_;
			}

			node_pointer
			prev(void) {
				node_pointer snapshot = node_;
				lessChildNode();
				if (node_ == snapshot) {
					lessParentNode();
				}
				return node_;
			}

			node_pointer
			moreParentNode(void) {
				while (node_->parent_) {
					if (compare(node_->content_->first, node_->parent_->content_->first)) {
						node_ = node_->parent_;
						break;
					}
					node_ = node_->parent_;
				}
				return node_;
			}

			node_pointer
			lessParentNode(void) {
				while (node_->parent_) {
					if (compare(node_->parent_->content_->first, node_->content_->first)) {
						node_ = node_->parent_;
						break;
					}
					node_ = node_->parent_;
				}

				return node_;
			}

			node_pointer
			moreChildNode(void) {
				if (node_->right_ && node_ != node_->right_) {
					node_ = node_->right_;
					node_ = leftEndNode(node_);
				}

				return node_;
			}

			node_pointer
			lessChildNode(void) {
				if (node_->left_ && node_ != node_->left_) {
					node_ = node_->left_;
					node_ = rightEndNode(node_);
				}
				return node_;
			}

			node_pointer
			leftEndNode(node_pointer& _from) {
				while (_from->left_) {
					_from = _from->left_;
				}
				return _from;
			}

			node_pointer
			rightEndNode(node_pointer& _from) {
				while (_from->right_) { _from = _from->right_; }
				return _from;
			}

			template <class _I1, class _I2, class _KC> friend bool operator== (const const_map_iterator<_I1, _KC>&, const const_map_iterator<_I2, _KC>&);
			template <class _I1, class _I2, class _KC> friend bool operator== (const const_map_iterator<_I1, _KC>&, const map_iterator<_I2, _KC>&);
			template <class _I1, class _I2, class _KC> friend bool operator== (const map_iterator<_I1, _KC>&, const const_map_iterator<_I2, _KC>&);

			template <class _I1, class _I2, class _KC> friend bool operator<  (const const_map_iterator<_I1, _KC>&, const const_map_iterator<_I2, _KC>&);
			template <class _I1, class _I2, class _KC> friend bool operator<  (const const_map_iterator<_I1, _KC>&, const map_iterator<_I2, _KC>&);
			template <class _I1, class _I2, class _KC> friend bool operator<  (const map_iterator<_I1, _KC>&, const const_map_iterator<_I2, _KC>&);


			template<class, class, class, class> friend struct tree;
			template<class, class, class, class> friend class map;
	};





	template <class _Iter1, class _Iter2, class _C>
	bool
	operator== (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return _it1.base() == _it2.base();
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator!= (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return !(_it1 == _it2);
	}





	template <class _Iter1, class _Iter2, class _C>
	bool
	operator== (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return _it1.base() == _it2.base();
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator!= (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return !(_it1 == _it2);
	}


	template <class _Iter1, class _Iter2, class _C>
	bool
	operator< (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return _it1.base() < _it2.base();
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator> (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return (_it2 < _it1);
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator<= (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return !(_it2 < _it1);
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator>= (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return !(_it1 < _it2);
	}



	template <class _Iter1, class _Iter2, class _C>
	bool
	operator< (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return _it1.base() < _it2.base();
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator> (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return (_it2 < _it1);
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator<= (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return !(_it2 < _it1);
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator>= (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return !(_it1 < _it2);
	}






	template <class _Iter1, class _Iter2, class _C>
	bool
	operator== (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return _it1.base() == _it2.base();
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator== (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return _it1.base() == _it2.base();
	}





	template <class _Iter1, class _Iter2, class _C>
	bool
	operator!= (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return !(_it1 == _it2);
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator!= (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return !(_it1 == _it2);
	}





	template <class _Iter1, class _Iter2, class _C>
	bool
	operator< (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return _it1.base() < _it2.base();
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator< (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return _it1.base() < _it2.base();
	}





	template <class _Iter1, class _Iter2, class _C>
	bool
	operator> (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return (_it2 < _it1);
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator> (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return (_it2 < _it1);
	}



	template <class _Iter1, class _Iter2, class _C>
	bool
	operator<= (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return !(_it2 < _it1);
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator<= (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return !(_it2 < _it1);
	}



	template <class _Iter1, class _Iter2, class _C>
	bool
	operator>= (const typename ft::const_map_iterator<_Iter1, _C>& _it1, const typename ft::map_iterator<_Iter2, _C>& _it2) {
		return !(_it1 < _it2);
	}

	template <class _Iter1, class _Iter2, class _C>
	bool
	operator>= (const typename ft::map_iterator<_Iter1, _C>& _it1, const typename ft::const_map_iterator<_Iter2, _C>& _it2) {
		return !(_it1 < _it2);
	}
}


#endif

