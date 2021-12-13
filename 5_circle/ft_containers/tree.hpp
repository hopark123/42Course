#ifndef _TREE_
# define _TREE_

# include "tree_iterator.hpp"
# include <iostream>
# include "ft_utils.hpp"

namespace ft
{
template <typename T, class Compare = ft::less<T>, typename Alloc = std::allocator<T> >
class tree {
	public :
		typedef T							value_type;
		typedef size_t						size_type;
		typedef ptrdiff_t					difference_type;
		typedef T&							reference;
		typedef T*							pointer;
		typedef const T&					const_reference;
		typedef const T*					const_pointer;
		typedef Alloc						alloc_type;
		typedef	Node<T>						node;
		typedef	Node<T>*					node_ptr;

		typedef	treeIterator<T, node>						iterator;
		typedef	treeIterator<const T, const node>			const_iterator;
		typedef reverse_iteartor<iterator>			reverse_iterator;
		typedef reverse_iteartor<const_iterator>	const_reverse_iterator;
	public :
		node_ptr									_root;
		node_ptr									_begin;
		node_ptr									_end;	// dummpy node
		Compare										_compare;
		size_type									_len;
		typedef	tree<T, Compare>					_Self;

		void	iosolate(node_ptr node) {
			if (!node)
				return ;
			node->parent = nullptr;
			node->left = nullptr;
			node->right = nullptr;
		}
		void	make_bound(void) {
			this->_root = new Node<value_type>();
			this->_begin = this->_root;
			this->_end = this->_root;
		}
		void	repair_tree(void) {
			node_ptr	temp = this->_root;
			while (temp->left)
				temp = temp->left;
			this->_begin = temp;
			temp = this->_root;
			while (temp->right)
				temp = temp->right;
			temp->right = this->_end;
			this->_end->parent = temp;

		}
		template< typename TP>
		node_ptr	find_node(node_ptr node, const TP &target) const 	{
			if (node == this->end().as_node() || !node)
			{
				return (nullptr);
			}
			bool left = this->_compare(target, node->_data);
			bool right = this->_compare(node->_data, target);
			if (!left && !right)
				return (node);
			else if (left)
				return (find_node(node->left, target));
			else // if (right)
				return (find_node(node->right, target));
				
		}
		void	insert_node(node_ptr node, node_ptr target) {
			if (!node || !target)
				return ;
			if (this->_compare(target->_data, node->_data)) {
				if (node->left)
					return (this->insert_node(node->left, target));
				else
					node->left = target;
			}
			else {
				if (node->right)
					return (this->insert_node(node->right, target));
				else
					node->right = target;
			}
			this->_len++;
			target->parent = node;
			return ;
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
				return (nullptr);
			bool left = this->_compare(node->_data, root->_data);
			bool right = this->_compare(root->_data, node->_data);
			if (left)
				root->left = erase_node(root->left, node);
			else if (right)
				root->right = erase_node(root->right, node);
			else if (!left && !right) {
				if (root->left && root->right) {
					node_ptr	candidate = root->left;
					while (candidate->right != nullptr)
						candidate = candidate->right;
					root->_data.value_type::~value_type();
					new (&(root->_data)) value_type(candidate->_data);
					root->left = erase_node(root->left, candidate);
				}
				else {
					
					node_ptr temp;
					temp = root;
					if (root->right == nullptr && root->left)
					{
std::cout << "=============================kkkq" << std::endl;
						root = root->left;
					}
					else if (root->left == nullptr)
					{
std::cout << "=============================kkkw" << std::endl;

						root = root->right;
					}
					else
					{
std::cout << "=============================kkek" << std::endl;

						root = nullptr;
					}
					temp->_data.value_type::~value_type();
					// delte temp;
					// temp::~value_type();

					this->_len--;
					// root = nullptr;
				}
				return (root);
			}
			return (root);
		}
		void	distory_node(node_ptr node) {
			if (!node)
				return ;
			if (node == this->_end)
				return ;
			distory_node(node->left);
			distory_node(node->right);
			delete node;
		}


	public :
		tree(const Compare com) : _compare(com), _len(0) {this->make_bound();}
		tree(const _Self &other) : _compare(other._compare) {
			// if (*this != other)
			*this = other;
			
		}
		virtual ~tree(void) {
			this->clear();
			delete this->_end;
		}
		template <typename U, typename K>
		_Self &operator=(const tree<U, K> &other) {
			if (*this != other) {
				if (this->_root != this->_end)
					this->clear();
				this->_compare = other._compare;
				this->copy(other);
				return (*this);
			}
		}
		const _Self	&operator=(const _Self &other) {
			// if (*this != other) {
				if (this->_root != this->_end)
					this->clear();
				this->copy(other);
				this->repair_tree();
				return (*this);
			// }
		}

		void	copy(const _Self &other) {
			this->_compare = other._compare;
			if (other._root == other.end_node())
				return ;
			this->_root = new Node<value_type>(*(other._root));
			if (other._root->left) {
				this->copy_node(&(this->_root->left), other._root->left, other.end_node());
				this->_root->left->parent = this->_root;
			}
			if (other._root->right) {
				this->copy_node(&(this->_root->right), other._root->right, other.end_node());
				this->_root->right->parent = this->_root;
			}
			this->_len = other._len;
			this->repair_tree();
		}

		node_ptr	insert(const_reference val) {
			node_ptr	newNode = new Node<value_type>(val);
			if (this->_root == this->_end)
			{
				this->_root = newNode;
				this->_len++;
			}
			else {
				if (this->_end->parent)
					this->_end->parent->right = nullptr;
				this->insert_node(this->_root, newNode);
			}
			this->repair_tree();
			return (newNode);
		}
		node_ptr	insert(node_ptr hint, const_reference val) {
			(void) hint;
			node_ptr	newNode = new Node<value_type>(val);
			if (this->_root == this->_end)
			{
				this->_root = newNode;
				this->_len++;
			}
			else {
				if (this->_end->parent)
				this->_end->parent->right = nullptr;
				this->insert_node(this->_root, newNode);
			}
			this->repair_tree();
			return (newNode);
		}

		template<typename TP>
		node_ptr	find(const TP &key) const {
			return (this->find_node(this->_root, key));
		}
		template<typename TP>
		node_ptr	find(node_ptr hint, TP const &key) {
			if (!hint)
				return (this->find(key));
			else
				return (this->find_node(hint, key));
		}
		node_ptr	erase(node_ptr node) {
			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			node_ptr next = this->erase_node(this->_root, node);
			this->_root = next;
			// std::cout << "erase end" << std::endl;
			this->repair_tree();
			// std::cout << "erase end#" << std::endl;
			return (next);
		}
		template<typename TP>
		size_type	erase(TP &key) {
			node_ptr target = nullptr;
			size_type	cnt = 0;
			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			while ((target = this->find_node(this->_root, key))) {
				this->_root = this->erase_node(this->_root, key);
				cnt++;
			}
			this->repair_tree();
			return(cnt);
		}
		const Compare &key_compare(void) const {
			return (this->_compare);
		}
		void	clear(void) {
			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			// print(this->_root);
			this->distory_node(this->_root);
			this->_end->parent = nullptr;
			this->_end->left = nullptr;
			this->_end->right = nullptr;
			this->_begin = this->_end;
			this->_root = this->_end;
			this->_len = 0;
		}
		void	swap(_Self &other) {
			ft::swap(this->_root, other._root);
			ft::swap(this->_begin, other._begin);
			ft::swap(this->_end, other._end);
			ft::swap(this->_compare, other._compare);
			ft::swap(this->_len, other._len);
		}
		node_ptr	begin_node(void) const {
			return (this->_begin);
		}
		node_ptr	end_node(void) const {
			return (this->_end);
		}

		iterator	begin(void) {
			return (iterator(this->_begin));
		}
		const_iterator	begin(void) const {
			return (const_iterator(this->_begin));
		}
		iterator	end(void) {
			return (iterator(this->_end));
		}
		const_iterator	end(void) const {
			return (const_iterator(this->_end));
		}
		reverse_iterator	rbegin(void) {
			return (reverse_iterator(this->_end));
		}
		const_iterator	rbegin(void) const {
			return (const_reverse_iterator(this->_end));
		}
		reverse_iterator	rend(void) {
			return (reverse_iterator(this->_begin));
		}
		const_iterator	rend(void) const {
			return (revserseconst_iterator(this->_begin));
		}
		bool	is_empty(void) const {
			return (this->_len == 0);
		}
		size_type	get_size(void) const {
			return (this->_len);
		}
		size_type	max_size(void) const {
			return (std::numeric_limits<difference_type>::max() / ((sizeof(value_type)) + sizeof(pointer)));
		}


		void		print(node_ptr node) {
			if (!node)
				return ;
			print(node->left);
			std::cout << "debug [" << node->_data.first << "][" << node->_data.second <<"]"<< std::endl;
			print(node->right);

		}
};

// template<typename T, typename C>
// bool operator==(const tree<T, C> &lhs, const tree<T, C>  &rhs) {
// 	if (lhs.get_size() != rhs.get_size())
// 		return (false);
// 	return equal(lhs.begin(), lhs.end(), rhs.begin());
// }
// template<typename T, typename C>
// bool operator!=(const tree<T, C> &lhs, const tree<T, C> &rhs) {
// 	return (!(lhs == rhs));
// }


// template <typename T>
// void swap(tree<T> &lhs, tree<T> &rhs){
// 	rhs.swap(lhs);
// }
}

#endif



