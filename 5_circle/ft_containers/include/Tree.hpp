#ifndef _TREE_
# define _TREE_

#include <iostream>

namespace ft
{
template < typename T, class Compare = std::less<T> >
class Tree
{
	public :
		typedef T			value_type;
		typedef size_t		size_type;
		typedef T&			reference;
		typedef T*			pointer;
		typedef const T&	const_reference;
		typedef const T*	const_pointer;
		struct Node
		{
			value_type		_data;
			Node*			parent;
			Node*			left;
			Node*			right;

			Node(const_reference data = value_type()) : _data(data), parent(nullptr), left(nullptr), right(nullptr) {}
			Node(const Node &other) : _data(other._data), parent(nullptr), left(nullptr), right(nullptr) {}
		};
		typedef	Node*		node_ptr;
	// protected : //todo
	public :
		node_ptr	_root;
		node_ptr	_begin;
		node_ptr	_end;	// dummpy node
		Compare		_compare;
	
		void		iosolate(node_ptr node) {
			if (!node)
				return ;
			node->parent = nullptr;
			node->left = nullptr;
			node->right = nullptr;
		}
		void		make_bound(void) {
			this->_root = new Node();
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
			this->_end->parent = tmp->right;
		}

		node_ptr	find_node(node_ptr node, value_type &target) {
			if (node == this->end || !node)
				return (nullptr);
			bool left = this->_compare(target, node->_data);
			bool right = this->_compare(node->_data, target);
			if (!left && !right)
				return (node);
			else if (left)
				return (find_node(target, node->left));
			else //  if (right)
				return (find_node(target, node->right));
		}
		void	insert_node(node_ptr node, node_ptr target) {
			if (!node || !traget)
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
		}
		void	copy_node(node_ptr *dest, node_ptr target, node_ptr end) {
			if (!target)
				return ;
			*dest = new Node(*target);
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
		Tree() {
			make_bound();
		}
		Tree(Compare const &comp) : this->_compare(comp){
			make_bound();
		}
		Tree(Tree const &other) {
			if (*this != other)
				*this = other;
		}
		virtual	Tree() {
			this->make_empty();
			delete this->_end;
		}
		Tree	&operator=(const Tree &other) {
			if (this != other) {
				if (this->_root != this->_end)
					this->make_empty()
				this->_compare = other.compare;
				this->_copy(other);
				return (*this);
			}
		}
		void	copy(const Tree &other) {
			if (other._root == other.end)
				return ;
			this->_root = new Node(*(other._root));
			if (other._root->left) {
				copy_node (&*this->_root->left, other._root->left, other._end);
				this->_root->left->parent = this->_root;
			}
			if (other._root->right) {
				copy_node (&*this->_root->right, other._root->right, other._end);
				this->_root->right->parent = this->_root;
			}
			this->repair_tree();
		}

		node_ptr	insert(const_reference val){
			node_ptr newNode = new Node(val);
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
			node_ptr newNode = new Node(val);
			this->insert_node(hint, newNode);
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