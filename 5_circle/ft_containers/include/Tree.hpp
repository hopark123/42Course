#ifndef _TREE_
# define _TREE_

#include <iostream>
#include "Tree_Iterator.hpp"

namespace ft
{
template < typename T, class Compare = std::less<T> >
class Tree
{
	public :
		typedef T			value_type;
		typedef size_t		size_type;
		typedef ptrdiff_t	difference_type;
		typedef T&			reference;
		typedef T*			pointer;
		typedef const T&	const_reference;
		typedef const T*	const_pointer;

		typedef	Node<T>*		node_ptr;

		typedef	TreeIterator<T>				iterator;
		typedef	TreeIterator<const T>		const_iterator;

	// todo
	protected :
	// public :
		node_ptr	_root;
		node_ptr	_begin;
		node_ptr	_end;	// dummpy node
		Compare		_compare;
		size_type	_len;
		typedef	Tree<T, Compare>	_Self;
	
		void		iosolate(node_ptr node) {
			if (!node)
				return ;
			node->parent = nullptr;
			node->left = nullptr;
			node->right = nullptr;
		}
		void		make_bound(void) {
			this->_root = new Node<value_type>();
			this->_begin = this->_root;
			this->_end = this->_root;
		}
		void		repair_tree(void) {
			node_ptr	tmp = this->_root;
			while (tmp->left)
				tmp = tmp->left;
			this->_begin = tmp;
			tmp = this->_root;
			while (tmp->right)
				tmp = tmp->right;
			tmp->right = this->_end;
			this->_end->parent = tmp;
		}

		node_ptr	find_node(node_ptr node, const value_type &target) {
			if (node == this->end().as_node() || !node)
				return (nullptr);
			bool left = this->_compare(target, node->_data);
			bool right = this->_compare(node->_data, target);
			if (!left && !right)
				return (node);
			else if (left)
				return (find_node(node->left, target));
			else //  if (right)
				return (find_node(node->right, target));
		}
		void	insert_node(node_ptr node, node_ptr target) {
			if (!node || !target)
				return ;
			if (this->_compare(target->_data, node->_data)){
				if (node->left)
					return (this->insert_node(node->left, target));
				else
					node->left = target;
			}
			else{
				if (node->right)
					return (this->insert_node(node->right, target));
				else
					node->right = target;
			}
			target->parent = node;
			this->_len++;
		}
		void	copy_node(node_ptr *dest, node_ptr target, node_ptr end) {
			if (!target)
				return ;
			*dest = new Node<value_type>(*target);
			if (target->left) {
				copy_node(&((*dest)->left), target->left, end);
				(*dest)->left->parent = (*dest);
			}
			if (target->right && target->right != end) {
				copy_node(&((*dest)->right), target->right, end);
				(*dest)->right->parent = (*dest);
			}
		}
		node_ptr	erase_node(node_ptr root, node_ptr node) {
			if (!root || !node)
			{
				return (nullptr);
			}
			bool left = this->_compare(node->_data, root->_data);
			bool right = this->_compare(root->_data, node->_data);
			if (left)
				root->left = erase_node(root->left, node);
			else if (right) // right
				root->right = erase_node(root->right, node);
			else if (!left && !right) {  // find root == node
				if (root->left && root->right) {
					node_ptr	candidate = root->left;
					while (candidate->right != nullptr)
						candidate = candidate->right;
					root->_data.value_type::~value_type();
					new (&(root->_data)) value_type(candidate->_data);
					root->left = erase_node(root->left, candidate);
				}
				else {
					node_ptr	tmp;
					tmp = root;
					if (root->right == nullptr)
					{
						root = root->left;
					}
					else if (root->left == nullptr)
					{
						root = root->right;
					}
					tmp->_data.value_type::~value_type();
				}
			}
			this->_len--;
			return (root);
		}
		void	distory_node(node_ptr node) {
			if (!node || node == this->_end)
				return ;
			distory_node(node->left);
			distory_node(node->right);
			delete node;
		}
	public :
		Tree() : _len(0) {
			this->make_bound();
		}
		Tree(Compare const &comp = Compare()) : _compare(comp), _len(0) {
			this->make_bound();
		}
		Tree(const _Self &other) {
			if (*this != other)
				*this = other;
		}
		virtual	~Tree() {
			this->clear();
			delete this->_end;
		}
		_Self	&operator=(const _Self &other) {
			if (this != other) {
				if (this->_root != this->_end)
					this->clear();
				this->_compare = other.compare;
				this->_copy(other);
				return (*this);
			}
		}
		void	copy(const _Self &other) {
			if (other._root == other.end)
				return ;
			this->_root = new Node<value_type>(*(other._root));
			if (other._root->left) {
				copy_node (&*this->_root->left, other._root->left, other._end);
				this->_root->left->parent = this->_root;
			}
			if (other._root->right) {
				copy_node (&*this->_root->right, other._root->right, other._end);
				this->_root->right->parent = this->_root;
			}
			this->_len = other._len;
			this->repair_tree();
		}

		node_ptr	insert(const_reference val){
			node_ptr newNode = new Node<value_type>(val);
			if (this->_root == this->_end)
				this->_root = newNode;
			else {
				if (this->_end->parent)
					this->_end->parent->right = nullptr;
				this->insert_node(this->_root, newNode);
			}
			this->repair_tree();
			return (newNode);
		}
		node_ptr	insert(node_ptr hint, const_reference val) {
			node_ptr newNode = new Node<value_type>(val);
			this->insert_node(hint, newNode);
		}

		template<typename TP> //일단 뭐든지 다 받겠다
		node_ptr	find(TP const &target) {
			return (this->find_node(this->_root, target));
		}
		template<typename TP> //일단 뭐든지 다 받겠다
		node_ptr	find(node_ptr hint, TP const &target) {
			if (!hint)
				return (this->find(target));
			else 
				return(this->find_node(hint, target));
		}
		node_ptr	erase(node_ptr node) {
			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			node_ptr next = this->erase_node(this->_root, node);
			this->repair_tree();
			return (next);
		}
		template<typename TP>
		size_type	erase(TP const &key) {
			node_ptr target = nullptr;
			size_type	cnt = 0;
			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			while ((target = this->find_node(key))) {
				this->erase_node(key);
				cnt++;
			}
			this->repair_tree();
			return (cnt);
		}
		
		Compare	key_compare(void) {
			return (this->_compare);
		}
		// node_ptr	begin(void) const {
		// 	return (this->_begin);
		// }
		// node_ptr	end(void) const {
		// 	return (this->end);
		// }

		void	clear(void) {
			this->distory_node(this->_root);
			this->_end->parent = nullptr;
			this->_end->left = nullptr;
			this->_end->right = nullptr;
			this->_begin = this->_end;
			this->_root = this->_end;
			this->_len = 0;
		}

		// void swap()  todo

		iterator	begin(void) {
			return (iterator(this->_root));
		}
		const_iterator	begin(void) const {
			return (iterator(this->_root));
		}

		// [const] rbegin
		iterator	end(void) {
			return (iterator(this->_end));
		}
		const_iterator	end(void) const {
			return (iterator(this->_end));
		}
		// [const] rend

		bool	is_empty() {
			return (this->_len == 0);
		}
		size_t	get_size() {
			return (this->_len);
		}
		size_t	max_size() {
			return (std::numeric_limits<difference_type>::max() / sizeof(value_type));
		}
		void	print(node_ptr node)
		{
			if (!node)
				return ;
			print(node->left);
			// if (node->left)
			// 	std::cout << node->left->_data << "|";
			std::cout << node->_data;
			// if (node->right)
			// 	std::cout << "|" << node->right->_data;
			std::cout << std::endl;
			print(node->right);

		}
};
}

#endif