/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyuhkim <kyuhkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 13:45:30 by kyuhkim           #+#    #+#             */
/*   Updated: 2021/11/07 22:33:39 by kyuhkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __TREE__
#define __TREE__

#include "node.hpp"
#include "map_iterator.hpp"
#include "reverse_iterator.hpp"



namespace ft {

	enum ROTATE_TYPE {
		ROTATE_TYPE_LL = -2,
		ROTATE_TYPE_LR = -1,
		ROTATE_TYPE_NO = 0,
		ROTATE_TYPE_RL = 1,
		ROTATE_TYPE_RR = 2,
	};


	template <typename _K, typename _M, class _C, class _A>
	class map;

	template <typename _K, typename _M, class _C, class _A>
	struct tree {

		template <class, class, class, class> friend class map;

		public:
			typedef		bidirectional_iterator_tag						iterator_category;
			typedef		typename ft::pair<const _K, _M>					value_type;
			typedef		_C												key_compare;
			typedef		_A												allocator_type;
			typedef		value_type&										reference;
			typedef		value_type*										pointer;
			typedef		ptrdiff_t										difference_type;
			typedef		typename allocator_type::size_type				size_type;
			
		private:
			typedef		typename ft::node<value_type>					node;
			typedef		node*											node_pointer;
			typedef		node&											node_reference;
			typedef		typename ft::rebind<node>::alloc				node_allocator_type;
			typedef		typename ft::map_iterator<node, _C>				iterator;
			typedef		typename ft::const_map_iterator<node, _C>		const_iterator;
			typedef		typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef		typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;



			size_type
			size_;

			node_pointer
			currentNode_;

			node_pointer
			edgeNode_;

			key_compare
			compare;



			tree() {
				edgeNode_			= new node();
				edgeNode_->content_	= new value_type();
				edgeNode_->parent_	= NULL;
				edgeNode_->right_	= edgeNode_;
				edgeNode_->left_	= edgeNode_;
				currentNode_		= edgeNode_;

				size_				= 0;
			}



			size_type
			max_size(void) const {
				return node_allocator_type().max_size();
			}



			iterator
			topNode(void) {
				node_pointer topNode = currentNode_;

				if (size_ && topNode == edgeNode_) {
					topNode = edgeNode_->right_;
				}

				while (topNode->parent_ && topNode->parent_ != edgeNode_) {
					topNode = topNode->parent_;
				}

				return iterator(topNode);
			}

			const_iterator
			topNode(void) const {
				node_pointer topNode = currentNode_;

				if (size_ && topNode == edgeNode_) {
					topNode = edgeNode_->right_;
				}

				while (topNode->parent_ && topNode->parent_ != edgeNode_) {
					topNode = topNode->parent_;
				}

				return const_iterator(topNode);
			}



			iterator				getBegin			(void) 			{ return iterator		(edgeNode_->right_); 	}
			const_iterator			getConstBegin		(void) const 	{ return const_iterator	(edgeNode_->right_); 	}
			iterator				getEnd				(void) 			{ return iterator		(edgeNode_);			}
			const_iterator			getConstEnd			(void) const	{ return const_iterator	(edgeNode_);			}

			iterator				moreChildNode		(void) 			{ return iterator		(currentNode_).moreChildNode();		}
			const_iterator			moreChildNode		(void) const 	{ return const_iterator	(currentNode_).moreChildNode();		}
			iterator				lessChildNode		(void) 			{ return iterator		(currentNode_).lessChildNode();		}
			const_iterator			lessChildNode		(void) const 	{ return const_iterator	(currentNode_).lessChildNode();		}
			iterator				moreParentNode		(void) 			{ return iterator		(currentNode_).moreParentNode();	}
			const_iterator			moreParentNode		(void) const 	{ return const_iterator	(currentNode_).moreParentNode();	}
			iterator				lessParentNode		(void) 			{ return iterator		(currentNode_).lessParentNode();	}
			const_iterator			lessParentNode		(void) const 	{ return const_iterator	(currentNode_).lessParentNode();	}



			bool					isNull		(node_pointer _target) 	{ return (!_target || _target == edgeNode_);	}
			bool					isLeft		(node_pointer _node) 	{ return _node->parent_->left_ == _node;		}
			bool					isRight		(node_pointer _node) 	{ return _node->parent_->right_ == _node;		}



			void
			swap(node_pointer& _x, node_pointer& _y) {
				node_pointer px = _x->parent_;
				node_pointer py = _y->parent_;
				node_pointer rx = _x->right_;
				node_pointer ry = _y->right_;
				node_pointer lx = _x->left_;
				node_pointer ly = _y->left_;
				node t;

				if (px)	{
					if (isRight(_x))	{ px->right_ = _y; }
					if (isLeft(_x))		{ px->left_  = _y; }
				}
				if (py) {
					if (isRight(_y))	{ py->right_ = _x; }
					if (isLeft(_y))		{ py->left_  = _x; }
				}
				if (rx)					{ rx->parent_ = _y; }
				if (ry)					{ ry->parent_ = _x; }
				if (lx)					{ lx->parent_ = _y; }
				if (ly)					{ ly->parent_ = _x; }

				t.parent_	= _x->parent_;
				t.right_	= _x->right_;
				t.left_		= _x->left_;

				_x->parent_	= _y->parent_;
				_x->right_	= _y->right_;
				_x->left_	= _y->left_;

				_y->parent_	= t.parent_;
				_y->right_	= t.right_;
				_y->left_	= t.left_;
			}



			void
			erase(iterator& _iter) {
				if (_iter.node_ == edgeNode_) { exit(ERROR_MAP_CONTAINER_SIZE); }

				if (edgeNode_->right_ == _iter.node_ && edgeNode_->left_ == _iter.node_) {
					edgeNode_->right_ = edgeNode_;
					edgeNode_->left_ = edgeNode_;
					deleteNode(_iter.node_);
					return;
				}
				else if (edgeNode_->right_ == _iter.node_) {
					iterator next = iterator(_iter.node_).next();
					edgeNode_->right_ = next.node_;
				}
				else if (edgeNode_->left_ == _iter.node_) {
					iterator prev = iterator(_iter.node_).prev();
					edgeNode_->left_ = prev.node_;
				}

				exportNode(_iter.node_);
			}



			void
			eraseEdge(void) {
				if (!size_) { deleteNode(edgeNode_); }
				else		{ exit(ERROR_MAP_CONTAINER_SIZE); }
			}



			void
			exportNode(node_pointer& _node) {
				iterator next = iterator(_node).next();

				if (_node->right_ && _node->left_) {
					swap(_node, next.node_);
					exportNode(_node);
					return;
				}

				if (_node->right_ != _node->left_) {
					deliverSingleBranch(_node);
				}
				else {
					if (isLeft(_node))	{ _node->parent_->left_  = NULL; }
					if (isRight(_node))	{ _node->parent_->right_ = NULL; }
					deleteNode(_node);
				}
			}



			void
			deliverSingleBranch(node_pointer& _node) {
				if (_node->parent_ == edgeNode_) {
					if (_node->left_)	{ _node->left_->parent_  = edgeNode_; }
					else 				{ _node->right_->parent_ = edgeNode_; }
				}
				if (isLeft(_node)) {
					if (_node->left_) {
						_node->parent_->left_ = _node->left_;
						_node->left_->parent_ = _node->parent_;
					}
					else {
						_node->parent_->left_ = _node->right_;
						_node->right_->parent_ = _node->parent_;
					}
				}
				if (isRight(_node)) {
					if (_node->left_) {
						_node->parent_->right_ = _node->left_;
						_node->left_->parent_ = _node->parent_;
					}
					else {
						_node->parent_->right_ = _node->right_;
						_node->right_->parent_ = _node->parent_;
					}
				}
				deleteNode(_node);
			}



			void
			deleteNode(node_pointer& _target) {
				currentNode_ = edgeNode_->right_;

				if (_target != edgeNode_) { --size_; }
				delete _target->content_;
				delete _target;
			}



			template <typename _PK>
			typename ft::pair<iterator, bool>
			search(const _PK& _key) {
				ft::pair<iterator, bool> result(iterator(topNode()), true);
				if (result.first.node_ == edgeNode_)					{ result.second = false; return result; }

				while (result.first.node_ != edgeNode_) {
					if (compare(result.first->first, _key)) {
						if (result.first.node_->right_) 				{ result.first.node_ = result.first.node_->right_; }
						else 											{ result.second = false; break; }
					}
					else if (compare(_key, result.first->first)) {
						if (result.first.node_->left_)					{ result.first.node_ = result.first.node_->left_; }
						else											{ result.second = false; break;	}
					}
					else 												{ break; }
				}

				return result;
			}



			template <typename _PK>
			typename ft::pair<const_iterator, bool>
			constSearch(const _PK& _key) {
				ft::pair<const_iterator, bool> result(const_iterator(topNode()), true);
				if (result.first.node_ == edgeNode_)					{ result.second = false; return result; }

				while (result.first.node_ != edgeNode_) {
					if (compare(result.first->first, _key)) {
						if (result.first.node_->right_) 				{ result.first.node_ = result.first.node_->right_; }
						else 											{ result.second = false; break; }
					}
					else if (compare(_key, result.first->first)) {
						if (result.first.node_->left_)					{ result.first.node_ = result.first.node_->left_; }
						else											{ result.second = false; break;	}
					}
					else 												{ break; }
				}

				return result;
			}




			void
			insert(const iterator& _parent, const iterator& _child) {
				_child.node_->parent_ = _parent.node_;

				if (_parent.node_ == edgeNode_) {
					edgeNode_->right_  = _child.node_;
					edgeNode_->left_   = _child.node_;
				}
				else {
					if (compare(_parent->first, _child->first)) { _parent.node_->right_ = _child.node_; }
					else 										{ _parent.node_->left_  = _child.node_; }
					expandEdgeNode(_parent, _child);
				}
				currentNode_ = _child.node_;
				size_++;
				increaseHeight(_child.node_);
			}



			void
			increaseHeight(const node_pointer& _from) {
				if (_from == edgeNode_) {	return;		}
				
				ROTATE_TYPE rotationType = analyseRotateType(_from);
				if (rotationType) {
					rebalance(_from, rotationType);
				}
				else {
					if ((_from->leftHeight() != _from->rightHeight()) || (!_from->leftHeight() && !_from->rightHeight())) {
						_from->increaseHeight();
						increaseHeight(_from->parent_);
					}
				}
			}



			ROTATE_TYPE
			analyseRotateType(const node_pointer& _from) {
				if (1 + _from->leftHeight() < _from->rightHeight()) {
					if (_from->right_->leftHeight() < _from->right_->rightHeight())	{ return ROTATE_TYPE_RR; }
					else															{ return ROTATE_TYPE_RL; }
				}
				if (1 + _from->rightHeight() < _from->leftHeight()) {
					if (_from->left_->leftHeight() < _from->left_->rightHeight())	{ return ROTATE_TYPE_LR; }
					else															{ return ROTATE_TYPE_LL; }
				}
				return ROTATE_TYPE_NO;
			}


			int
			isHeightGapMoreThanTwo(const node_pointer& _from) {	// fix
				int gap = (_from->left_  ? _from->left_->height  : 0) - (_from->right_ ? _from->right_->height : 0);
				return gap > 1 ? 1 : gap < -1 ? -1 : 0;
			}



			void rebalance(const node_pointer& _where, const ROTATE_TYPE& rebalanceType) {
				switch (rebalanceType) {
					case ROTATE_TYPE_RR:
						_where->decreaseHeight();
						leftRotate(_where);
						break;
					case ROTATE_TYPE_LL:
						_where->decreaseHeight();
						rightRotate(_where);
						break;
					case ROTATE_TYPE_RL:
						_where->decreaseHeight();
						_where->right_->left_->increaseHeight();
						rightRotate(_where->right_);
						leftRotate(_where);
						break;
					case ROTATE_TYPE_LR:
						_where->decreaseHeight();
						_where->left_->right_->increaseHeight();
						leftRotate(_where->left_);
						rightRotate(_where);
						break;
					default:
						break;
				}
			}



			void
			rightRotate(const node_pointer& _where) {
				node_pointer parent	= _where->parent_;
				node_pointer child	= _where->left_;
				node_pointer self	= const_cast<node_pointer>(_where);

				self->left_ = child->right_;
				if (child->right_)			{ child->right_->parent_ = self; }

				self->parent_ = child;
				child->right_ = self;

				if (parent != edgeNode_) {
					if (parent->left_  == _where) { parent->left_  = child; }
					if (parent->right_ == _where) { parent->right_ = child; }
				}
				child->parent_ = parent;
			}



			void
			leftRotate(const node_pointer& _where) {
				node_pointer parent	= _where->parent_;
				node_pointer child	= _where->right_;
				node_pointer self	= const_cast<node_pointer>(_where);

				self->right_ = child->left_;
				if (child->left_)			{ child->left_->parent_ = self; }

				self->parent_ = child;
				child->left_ = self;

				if (parent != edgeNode_) {
					if (parent->left_  == _where) { parent->left_  = child; }
					if (parent->right_ == _where) { parent->right_ = child; }
				}
				child->parent_ = parent;
			}



			void
			expandEdgeNode(const iterator& _parent, const iterator& _child) {
				if (edgeNode_->right_ == _parent.node_  && !compare(_parent->first, _child->first)) {
					edgeNode_->right_ = _child.node_;
				}
				if (edgeNode_->left_ == _parent.node_  && !compare(_child->first, _parent->first)) {
					edgeNode_->left_ = _child.node_;
				}
			}



			template <typename _PV>
			iterator
			fakeInsert(iterator&, const _PV& _pair) {
				ft::pair<iterator, bool> fakeResult = search(_pair.first);

				if (fakeResult.second) { return fakeResult.first; }

				iterator fake = iterator(_pair.first, _pair.second);
				insert(fakeResult.first, fake);

				return fake;
			}
	};
}


#endif
