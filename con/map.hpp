/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:09:15 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/07 22:35:38 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MAP__

#include "tree.hpp"

namespace ft {

	template <typename _K, typename _M, class _C = std::less<_K>, class _A = std::allocator<typename ft::pair<const _K, _M> > >
	class map {
		
		public:
			typedef		_K												key_type;
			typedef		_M												mapped_type;
			typedef		typename ft::pair<const key_type, mapped_type>	value_type;
			typedef		_C												key_compare;
			typedef		_A												allocator_type;
			typedef		typename allocator_type::reference				reference;
			typedef		typename allocator_type::const_reference		const_reference;
			typedef		typename allocator_type::pointer				pointer;
			typedef		typename allocator_type::const_pointer			const_pointer;
			typedef		typename allocator_type::size_type				size_type;
			typedef		typename allocator_type::difference_type		difference_type;
			typedef		typename ft::node<value_type>					node;
			typedef		node*											node_pointer;
			typedef		node&											node_reference;
			typedef		typename ft::map_iterator<node, _C>				iterator;
			typedef		typename ft::const_map_iterator<node, _C>		const_iterator;
			typedef		typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef		typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		private:
			typedef		typename ft::tree<_K, _M, _C, _A>				tree_type;
			typedef		tree_type*										tree_pointer_type;
			typedef		tree_type&										tree_reference_type;




			class
			value_compare {
				protected:
					key_compare comp;
					value_compare (key_compare _c): comp(_c) {}
				public:

					value_compare() {}
					value_compare(const value_compare& _x): comp(_x.comp) {}
					~value_compare() {}

					value_compare&
					operator=(const value_compare& _x) {
						comp = _x.comp;
						return *this;
					}
					
					bool
					operator() (const value_type& _v1, const value_type& _v2) const {
						return comp(_v1.first, _v2.first);
					}
			};

		private:

			tree_pointer_type
			root_;

			key_compare
			key_compare_;

			value_compare
			value_compare_;

			allocator_type
			alloc_;

		public:
			explicit map (const key_compare& _comp = key_compare(), const allocator_type& _alloc = allocator_type()): key_compare_(_comp), alloc_(_alloc) { root_ = new tree<_K, _M, key_compare, allocator_type>(); }

			template <class _Iter>
			map (_Iter _first, _Iter _last, const key_compare& _comp = key_compare(), const allocator_type& _alloc = allocator_type()): key_compare_(_comp), alloc_(_alloc) {
				root_ = new tree<_K, _M, _C, _A>();
				insert(_first, _last);
			}

			map (const map& _x) {
				root_ = new tree<_K, _M, _C, _A>();
				*this = _x;
			}

			map&
			operator= (const map& _src) {
				clear();
				insert(_src.begin(), _src.end());
				return *this;
			}

			~map() {
				clear();
				root_->eraseEdge();
				delete root_;
			}





/* define : Iterators */
			iterator 					begin		(void) 				{ return iterator					(root_->getBegin()); 		}
			const_iterator				begin		(void) const 		{ return const_iterator				(root_->getConstBegin()); 	}
			iterator 					end			(void)				{ return iterator					(root_->getEnd()); 			}
			const_iterator 				end			(void) const 		{ return const_iterator				(root_->getConstEnd()); 	}
			reverse_iterator			rbegin		(void) 				{ return reverse_iterator			(end()); 					}
			const_reverse_iterator		rbegin		(void) const		{ return const_reverse_iterator		(end()); 					}
			reverse_iterator			rend		(void)				{ return reverse_iterator			(begin()); 					}
			const_reverse_iterator		rend		(void) const		{ return const_reverse_iterator		(begin()); 					}



			key_compare					key_comp	() const			{ return key_compare	(); 	}
			value_compare				value_comp	() const			{ return value_compare	();		}


/* define : Capacity */
			bool						empty		(void) const		{ return !root_->size_; 		}
			size_type					size		(void) const		{ return root_->size_; 			}
			size_type					max_size	(void) const		{ return root_->max_size(); 	}





/* define : Element access */
			mapped_type& operator[] (const key_type& _key) {
				typename ft::pair<iterator, bool> result = root_->search(_key);

				if (!result.second) {
					iterator temp = iterator(_key, _M());
					root_->insert(result.first, temp);
					return temp->second;
				}
				return result.first->second;
			}





/* define : Modifiers */
			template <typename _PV>
			typename ft::pair<iterator, bool>
			insert(const _PV& _pair) {
				typename ft::pair<iterator, bool> result = root_->search(_pair.first);

				if (!result.second) {
					iterator newIter = iterator(_pair.first, _pair.second);
					root_->insert(result.first, newIter);
					result.first = newIter;
				}
				result.second = !result.second;

				return result;
			}



			template <typename _PV>
			iterator
			insert (iterator _position, const _PV& _val, typename ft::enable_if<!ft::is_same<iterator, _PV>::value>::type* = 0) {
				return root_->fakeInsert(_position, _val);
			}



			template <class InputIterator>
			void
			insert (InputIterator _first, InputIterator _last) {
				ft::pair<iterator, bool> search;
				
				for (;_first != _last; _first++) {
					search = root_->search(_first->first);
					if (!search.second) {	root_->insert(search.first, iterator(_first->first, _first->second));	}
// showTree();
				}
			}



			void
			erase (iterator _position) 				{ root_->erase(_position); }



			size_type
			erase (const key_type& _k) {
				ft::pair<iterator, bool> searchResult = root_->search(_k);
				
				if (searchResult.second) {
					erase(searchResult.first);
				}

				return searchResult.second;
			}

			void
			erase (iterator _first, iterator _last) {
				for (;_first != _last;) {	erase(_first++);	}
			}

			void
			swap (map& _x) {
				tree_pointer_type temp;

				temp = _x.root_;
				_x.root_ = root_;
				root_ = temp;
			}
			
			void clear(void) {
				iterator e = end();
				iterator b = begin();

				for (;b != e;) {
					erase(b);
					b = begin();
				}
			}



/* define: Operations*/
      		iterator
			find (const key_type& _k) {
				ft::pair<iterator, bool> search = root_->search(_k);
				
				if (!search.second) {
					search.first = end();
				}
				
				return search.first;
			}



			const_iterator
			find (const key_type& _k) const {
				ft::pair<const_iterator, bool> search = root_->constSearch(_k);
				
				if (!search.second) {
					search.first = end();
				}
				
				return search.first;
			}



			size_type
			count (const key_type& _k) const {
				ft::pair<iterator, bool> search = root_->search(_k);
				return search.second;
			}



      		iterator
			lower_bound (const key_type& _k) {
				ft::pair<iterator, bool> search = root_->search(_k);
				
				if (!search.second) {
					if (key_compare()(search.first->first, _k)) {	search.first.moreParentNode();	}
				}

				return search.first;
			}

			const_iterator
			lower_bound (const key_type& _k) const {
				ft::pair<const_iterator, bool> search = root_->constSearch(_k);
				
				if (!search.second) {
					if (key_compare()(search.first->first, _k)) {	search.first.moreParentNode();	}
				}

				return search.first;
			}



			iterator
			upper_bound (const key_type& _k) {
				ft::pair<iterator, bool> search = root_->search(_k);
				
				if (!search.second) {
					if (key_compare()(search.first->first, _k)) {	search.first.moreParentNode();	}
				}
				else {
					search.first.next();
				}

				return search.first;
			}

			const_iterator
			upper_bound (const key_type& _k) const {
				ft::pair<const_iterator, bool> search = root_->constSearch(_k);
				
				if (!search.second) {
					if (key_compare()(search.first->first, _k)) {	search.first.moreParentNode();	}
				}
				else {	search.first.next();	}

				return search.first;
			}



			typename ft::pair<iterator,iterator>
			equal_range (const key_type& _k) {	return ft::pair<iterator, iterator>(lower_bound(_k), upper_bound(_k));	}

			typename ft::pair<const_iterator,const_iterator>
			equal_range (const key_type& _k) const {	return ft::pair<const_iterator, const_iterator>(lower_bound(_k), upper_bound(_k));	}





/* define : Allocator */
			allocator_type		get_allocator		(void) const		{ return allocator_type(); }
	



/* define : op */
			template <typename _NK, typename _NM, class _NC, class _NA>
			bool
			operator ==(const map<_NK, _NM, _NC, _NA>& _map) const {
				if (size() == _map.size()) {
					const_iterator i1 = begin();
					const_iterator i2 = _map.begin();
					const_iterator ie = end();

					for (; i1 != ie;) {
						if (*i1 != *i2) { return false; }
						++i1;
						++i2;
					}
					return true;
				}
				return false;
			}

			template <typename _NK, typename _NM, class _NC, class _NA>
			bool
			operator !=(const map<_NK, _NM, _NC, _NA>& _map) const {
				return !operator==(_map);
			}

			template <typename _NK, typename _NM, class _NC, class _NA>
			bool
			operator <(const map<_NK, _NM, _NC, _NA>& _map) const {
				const_iterator i1 = begin();
				const_iterator i2 = _map.begin();
				const_iterator ie1 = end();
				const_iterator ie2 = _map.end();

				if (size() < _map.size()) {
					for (; i1 != ie1;) {
						if (i1 < i2) { return true; }
						if (i2 < i1) { return false; }
						++i1; ++i2;
					}
					return true;
				}
				else {
					for (; i2 != ie2;) {
						if (i1 < i2) { return true; }
						if (i2 < i1) { return false; }
						++i1; ++i2;
					}
					return false;
				}
				
				return false;
			}

			template <typename _NK, typename _NM, class _NC, class _NA>
			bool
			operator >(const map<_NK, _NM, _NC, _NA>& _map) const {
				const_iterator i1 = begin();
				const_iterator i2 = _map.begin();
				const_iterator ie1 = end();
				const_iterator ie2 = _map.end();

				if (_map.size() < size()) {
					for (; i1 != ie1;) {
						if (i2 < i1) { return true; }
						if (i1 < i2) { return false; }
						++i1; ++i2;
					}
					return true;
				}
				else {
					for (; i2 != ie2;) {
						if (i2 < i1) { return true; }
						if (i1 < i2) { return false; }
						++i1; ++i2;
					}
					return false;
				}
				
				return false;
			}

			template <typename _NK, typename _NM, class _NC, class _NA>
			bool
			operator <=(const map<_NK, _NM, _NC, _NA>& _map) const {
				return !operator>(_map);
			}

			template <typename _NK, typename _NM, class _NC, class _NA>
			bool
			operator >=(const map<_NK, _NM, _NC, _NA>& _map) const {
				return !operator<(_map);
			}

		private:
			void showTree(void) {
				node_pointer top = root_->topNode().getNodePtr();
				showNode(top);
			}

			void showNode(node_pointer _node) {
				std::cout << "height = " << _node->height << ", key = " << _node->content_->first << 
				", l = " << (_node->left_ ? _node->left_->content_->first : 0) <<
				", p = " << _node->parent_->content_->first <<
				", r = " << (_node->right_ ? _node->right_->content_->first : 0) <<
				std::endl;
				if (_node->left_) 	{		showNode(_node->left_);		}
				if (_node->right_) 	{		showNode(_node->right_);	}
			}
	};
}


#endif
