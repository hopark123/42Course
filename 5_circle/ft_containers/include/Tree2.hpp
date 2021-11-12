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
			value_type _value;
			Node *parent;
			Node *left;
			Node *right;

			Node() : _value(0), parent(nullptr), left(nullptr), right(nullptr) {}
			Node(const_reference value = value_type()) : _value(value), parent(nullptr), left(nullptr), right(nullptr){}
			Node(const Node &other) :_value(other.value), parent(nullptr), left(nullptr), right(nullptr) {}
		};
		typedef Node*		node_ptr;

	protected :
		node_ptr	_root;
		node_ptr	_begin;
		node_ptr	_end;
		Compare		_compare;

		void	unbounded_node(node_ptr	node){
			if (!node)
				return ;
			node->parent = nullptr;
			node->left = nullptr;
			node->right = nullptr;
		}
		void	make_bound(void) {
			this->_begin = new Node();
			this->_root = this->_begin;
			this->_end = this->_root;
		}
		void	repair_bound(void) {
			node_ptr tmp = this->_root;
			while (tmp->left)
				tmp = tmp->left;
			this->_begin = tmp;
			tmp = this->_root;
			while (tmp->right)
				tmp = tmp->right;
			tmp->right = this->_end;
			this->_end->parent = tmp;
		}

		node_ptr	find_node(value_type const &val, node_ptr node) {
			if (node == this->_end || !node)
				return (nullptr);
			bool com_left = this->_compare(val, node->_value);
			bool com_right = this->_compare(node->_value, val);
			if (!com_left && !com_right)
				return (node);
			if (com_left)
				return (find_node(val, node->left));
			return (this->find_node(val, node->right));
		}
		void		insert_node(node_ptr node, node_ptr new_node){
			if (this->_compare(new_node->_value, node->_value)){
				if (node->left){
					this->insert_node(node->left, new_node);
					return ;
				}
				else
					node->left = new_node;
			}
			else{
				if (node->right){
					this->insert_node(node->right, new_node);
					return ;
				}
				else
					node->right = new_node;
			}
			new_node->parent = node;
		}
		void	copy_node(node_ptr *dest, node_ptr src, node_ptr end) {
			if (!src)
				return ;
			*dest = new Node(src);
			if (src->left){
				copy_node(&(*dest)->left, src->left, end);
				(*dest)->left->parent = *dest;
			}
			if (src->right && src->right != end){
				copy_node(&(*dest)->right, src->right, end);
				(*dest)->right->parent = *dest;
			}
		}
		node_ptr	erase_node(node_ptr node, node_ptr) {
			if (!node)
				return (node);
			node_ptr ret = node;
			if (!node->left && !node->right) {
				if (node == this->_root){
					this->_root = this->_begin = this->_end;
					this->unbounded_node(this->_end);
				}
				if (node->parent){
					if (node->parent->left == node)
						node->parent->left = nullptr;
					else
						node->parent->right = nullptr;
				}
				ret = node->parent;
				delete node;
			}
			else if (!node->left) {
				if (node->parent) {
					if (node->parent->left == node)
						node->parent->left = node->right;
					else
						node->parent->right = node->right;
				}
				node->right->parent = node->parent;
				if (node == this->_root)
					this->_root = node->right;
			}
			else if (!node->right) {
				if (node->parent) {
					if (node->parent->left == node)
						node->parent->left = node->left;
					else
						node->parent->right = node->left;
				}
				node->left->parent = node->parent;
				if (node == this->_root)
					this->_root = node->left;
			}
			else {
				node_ptr tmp = node->right;
				while (tmp && tmp->left != nullptr)
					tmp = tmp->left;
				if (node->parent) {
					if (node->parent->left == node)
						node->parent->left == tmp;
					else
						node->parent->right = tmp;
				}
				tmp->parent = node->parent;
				node->_value.value_type::~value_type();
				new(&(node->_value)) value_type(tmp->_value);
				// if (node == this->_root)
				// 	this->_root = node; // ???????
				node->right = erase_node(node->right);
				ret = node;
			}
			return (ret);
		}
		void	distory_node(node_ptr node) {
			if (!node || node == this->_end)
				return ;
			distory_node(node->right);
			distory_node(node->left);
			delete node;
		}

	public :
		Tree(): _root(nullptr) {
			this->make_bound();
		}
		Tree(Compare const &comp) : _root(nullptr), _compare(comp) {
			this->make_bound();
		}
		Tree(Tree const &other) {
			if (this != other)
				*this = other;
		}
		virtual ~Tree(){
			this->make_empty();
			delete this->_end;
		}
		Tree	&operator=(const Tree &other){
			if (this != other){
				if (this->_root != this->_end)
					this->make_empty();
				this->_compare = other._compare;
				this->copy(other);
				return (*this);
			}
		}

		void	copy(const Tree &other){
			if (other._root == other._end)
				return ;
			this->_root = new Node(*other._root);
			if (other._root->left){
				this->copy_node(&this->_root->left, other._root->left, other._end);
				this->_root->left->parent = this->_root;
			}
			if (other._root->right){
				this->copy_node(&this->_root->right, other._root->right, other._end);
				this->_root->right->parent = this->_root;
			}
			this->repair_bound();
		}
		node_ptr	insert(const_reference val){
			node_ptr	new_node = new Node(val);
			if (this->_root == this->_end)
				this->_root = new_node;
			else {
				if (this->_end->parent)
					this->_end->parent->right = nullptr;
				this->insert_node(this->_root, new_node);
			}
			this->repair_bound();
			return (new_node);
		}
		node_ptr	insert(node_ptr hint, const_reference val){
			if (!hint || this->_root == this->_end || \
				(hint->parent && (this->_compare(val, hint->parent->_value) || this->_compare(hint->parent->_value, val))))
				return (this->insert(val));
			node_ptr	new_node = new Node(val);
			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			this->insert_node(hint, new_node);
			this->repair_bound();
			return (new_node);
		}

		node_ptr	find(const value_type &val){
			return (this->find_node(val, this->_root));
		}
		node_ptr	find(node_ptr hint, const value_type &val){
			if (!hint)
				return (this->find_node(val, this->_root));
			if (!this->_compare(hint->val, val) && !this->_compare(val, hint->val))
				return (!hint);
			return (find_node(val, hint));
		}
		
		size_type	erase(value_type const &key){
			node_ptr	node = nullptr;
			size_type	total = 0;

			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			while ((node == this->find(key))){
				this->erase_node(node);
				total++;
			}
			this->repair_bound();
			return (total);
		}

		Compare	key_compare(void) const{
			return (this->_compare);
		}
		node_ptr	begin(void) const{
			return (this->_begin);
		}
		node_ptr	end(void) const{
			return (this->_end);
		}
		void	make_empty(void){
			this->distory_node(this->_root);
			this->_end->parent = nullptr;
			this->_end->left = nullptr;
			this->_end->right = nullptr;
			this->_begin = this->_root = this->_end;
		}
		// void	swap(Tree &other){

		// }


		void	print(node_ptr Node)
		{
			print(Node->left);
			std::cout << Node->_value << std::endl;
			print(Node->right);
		}
};
}

#endif