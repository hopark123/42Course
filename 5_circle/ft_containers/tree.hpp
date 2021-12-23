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

		typedef	treeIterator<T, node >						iterator;
		typedef	treeIterator<const T, const node >			const_iterator;
		typedef reverse_iteartor<iterator>			reverse_iterator;
		typedef reverse_iteartor<const_iterator>	const_reverse_iterator;
	// private :
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
			this->_root->_color = 0;
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
				return (nullptr);
			bool left = this->_compare(target, node->_data);
			bool right = this->_compare(node->_data, target);
			if (!left && !right)
				return (node);
			else if (left)
				return (find_node(node->left, target));
			else // if (right)
				return (find_node(node->right, target));
				
		}

		void	rotate_right(node_ptr node, bool left) {
			(void)left;
			if (!node) {
				// std::cout << "Rrotate empty" << std::endl;
				return ;
			}
			if (!node->left)
				return ;
			if (node->parent) {
				if (this->_compare(node->parent->_data, node->_data))
					node->parent->right = node->left;
				else
					node->parent->left = node->left;
			}
			else
				this->_root = node->left;
			node->left->parent = node->parent;
			if (node->left->right)
				node->left->right->parent = node;
			node->parent = node->left;
			node->left = node->parent->right;
			node->parent->right = node;
		}
		void	rotate_left(node_ptr node, bool left)
		{
			(void)left;
			if (!node) {
				// std::cout << "Lrotate empty" << std::endl;
				return ;
			}
			if (!node->right)
				return ;
			if (node->parent) {
				if (this->_compare(node->parent->_data, node->_data))
					node->parent->right = node->right;
				else
					node->parent->left = node->right;
			}
			else
				this->_root = node->right;
			node->right->parent = node->parent;
			if (node->right->left)
				node->right->left->parent = node;
			node->parent = node->right;
			node->right = node->parent->left;
			node->parent->left = node;

		}


		void	insert_node(node_ptr node, node_ptr target) {
			/////////////////
			if (!node || !target)
				return ;

			if (this->_compare(target->_data, node->_data)) {
				if (node->left)
					return (this->insert_node(node->left, target));
				else
				{
					node->left = target;
					checkrb_insert(target);
				}
			}
			else {
				if (node->right)
					return (this->insert_node(node->right, target));
				else
				{
					node->right = target;
					checkrb_insert(target);
				}
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
			node_ptr	temp;
			if (!root || !node)
				return (nullptr);
			bool left = this->_compare(node->_data, root->_data);
			bool right = this->_compare(root->_data, node->_data);
			if (left)
			{
				temp = erase_node(root->left, node);
				root->left = temp;
				if (temp)
					temp->parent = root;
			}
			else if (right)
			{
			// std::cout << "erase node" << std::endl;
				temp = erase_node(root->right, node);
				root->right = temp;
				if (temp)
					temp->parent = root;
			}
			else if (!left && !right) {
				if (root->left && root->right) {
					node_ptr	candidate = root->left;
					while (candidate->right != nullptr)
						candidate = candidate->right;
					if (root->_color == 0)
					{
						candidate->_color = 0;
						root->_data.value_type::~value_type();
					}
					else
						root->_data.value_type::~value_type();
					new (&(root->_data)) value_type(candidate->_data);
					temp = erase_node(root->left, candidate);
					root->left = temp;
					if (temp)
						temp->parent = root;
				}
				else {
					node_ptr temp;
					temp = root;
					if (root->right == nullptr && root->left)
						root = root->left;
					else if (root->left == nullptr)
						root = root->right;
					else
						root = nullptr;
					if (temp->_color == 0)
						temp->_data.value_type::~value_type();
					else
						temp->_data.value_type::~value_type();
					this->_len--;
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

		bool	checkrb_insert(node_ptr node) {
			this->_root->_color = 0;
			if (!node->parent)
				return (false);
			if (node->parent->_color == 0)
				return (false);
			if (this->_compare(node->parent->parent->_data, node->parent->_data)) {
				if (node->parent->parent->left && node->parent->parent->left->_color == 1)
					this->recoloring(node);
				else
					this->restructuring(node, true);
			}
			else if (!this->_compare(node->parent->parent->_data, node->parent->_data)) {
				if (node->parent->parent->right && node->parent->parent->right->_color == 1)
					this->recoloring(node);
				else
					this->restructuring(node, false);
			}
			return (true);
		}
		
		bool	restructuring(node_ptr node, bool right) {
			if (right) {
				if (this->_compare(node->parent->_data, node->_data)) {
					if (node->parent->parent->parent) {
						if (this->_compare(node->parent->parent->parent->_data, node->parent->parent->_data))
							node->parent->parent->parent->right = node->parent;
						else
							node->parent->parent->parent->left = node->parent;
					}
					else
						this->_root = node->parent;
					node->parent->parent->right = node->parent->left;
					if (node->parent->parent->right)
						node->parent->parent->right->parent = node->parent->parent;
					node->parent->left = node->parent->parent;
					node->parent->parent = node->parent->parent->parent;
					node->parent->left->parent = node->parent;
					node->parent->_color = 0;
					node->parent->left->_color = 1;
				}
				else {
					if (node->parent->parent->parent) {
						if (this->_compare(node->parent->parent->parent->_data, node->parent->parent->_data))
							node->parent->parent->parent->left = node;
						else
							node->parent->parent->parent->right = node;
					}
					else
						this->_root = node;
					node_ptr	temp = node->parent->parent->parent;
					node->left = node->parent->parent;
					node->right = node->parent;
					node->parent->left = nullptr;
					node->parent->parent->right = nullptr;
					node->parent->parent->parent = node;
					node->parent->parent = node;
					node->parent = temp;
					node->_color = 0;
					node->left->_color = 1;
				}
			}
			else {
				if (!this->_compare(node->parent->_data, node->_data)) {
					if (node->parent->parent->parent) {
						if (this->_compare(node->parent->parent->parent->_data, node->parent->parent->_data))
							node->parent->parent->parent->right = node->parent;
						else
							node->parent->parent->parent->left = node->parent;
					}
					else
						this->_root = node->parent;
					node->parent->parent->left = node->parent->right;
					if (node->parent->parent->left)
						node->parent->parent->left->parent = node->parent->parent;
					node->parent->right = node->parent->parent;
					node->parent->parent = node->parent->parent->parent;
					node->parent->right->parent = node->parent;
					node->parent->_color = 0;
					node->parent->right->_color = 1;
				}
				else {
					if (node->parent->parent->parent) {
						if (this->_compare(node->parent->parent->parent->_data, node->parent->parent->_data))
							node->parent->parent->parent->right = node;
						else
							node->parent->parent->parent->left = node;
					}
					else
						this->_root = node;
					node_ptr	temp = node->parent->parent->parent;
					node->right = node->parent->parent;
					node->left = node->parent;
					node->parent->right = nullptr;
					node->parent->parent->left = nullptr;
					node->parent->parent->parent = node;
					node->parent->parent = node;
					node->parent = temp;
					node->_color = 0;
					node->right->_color = 1;
				}
			}
			return (true);
		}
		bool	recoloring(node_ptr node) {
			// std::cout << "recoloring " << node->_data.first << std::endl;
			if (!node->parent)
				return (false);
			if (!node->parent->parent)
				return (false);
			node->parent->parent->left->_color = 0;
			node->parent->parent->right->_color = 0;
			if (node->parent->parent)
			{
				node->parent->parent->_color = 1;
				checkrb_insert(node->parent->parent);
			}
			return false;
		}
		bool	checkrb_delete(node_ptr node, bool left) {
			// std::cout << "/in check rbdeleteA\\[" << node->_data.first<<"]" << left << std::endl;
			// print(this->_root);
			// std::cout << "\\in check rbdeleteB/" << std::endl;
			this->_root->_color = 0;
			if ((left && !node->right) || (!left && !node->left))
				return (true);
			if (left && node->right->_color == 1 && (node->right->right || node->right->left)) {
				rotate_left(node, true);
			}
			else if (!left && node->left->_color == 1  && (node->left->right || node->left->left)) {
				rotate_right(node, true);
			}
			node->_color = 1;
			if (node->parent)
				node->parent->_color = 0;
			// print(this->_root);
			if (left) {
				if (node->right&& node->right->right && node->right->right->_color == 1)
				{
					case1(node, left);
				}
				else if (node->left && node->left->_color == 1)
				{
					case2(node, left);
				}
				else
				{
					case3(node, left);
				}
			}
			else {
				if (node->left->right && node->left->right->_color == 1)
					case1(node, left);
				else if (node->left && node->left->_color == 1)
					case2(node, left);
				else
					case3(node, left);
			}
			return (true);
		}
		void	case1(node_ptr node, bool left) {
			// std::cout << "case1  [" << node->_data.first  << "]" << left << std::endl;
			if (left)
				rotate_right(node->right, true);
			else
				rotate_left(node->left, true); 
			// std::cout << "/case1 end\\" << std::endl;
			// print(this->_root);
			// std::cout << "\\case1 end/" << std::endl;
			case2(node, left);
		}
		void	case2(node_ptr node, bool left) {
			// std::cout << "case2 [" << node->_data.first << "]" << left << std::endl;
			if (left) {
				node->right->_color = node->_color;
				node->_color = 0;
				if (node->right->right)
					node->right->right->_color = 0;
				rotate_left(node, true); 
			}
			else {
				node->left->_color = node->_color;
				node->_color = 0;
				if (node->left->left)
					node->left->left->_color = 0;
				rotate_right(node, true);
			}

			// std::cout << "/case2 end\\" << std::endl;
			// print(this->_root);
			// std::cout << "\\case2 end/" << std::endl;

		}
		void	case3(node_ptr node, bool left) {
			// std::cout << "case3 [" << node->_data.first <<"]"<< left << std::endl;
			// print_one(node);
			node->_color = 0;
			if (left)
			{
				node->right->_color = 1;
			}
			else
				node->left->_color = 1;
			// std::cout << "/case3 end\\" << std::endl;
			// print(this->_root);
			// std::cout << "\\case3 end/" << std::endl;
		}

	public :
		tree(const Compare com) : _compare(com), _len(0) {this->make_bound();}
		tree(const _Self &other) : _compare(other._compare) {
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
			this->make_bound();
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
			if (this->_root == this->_end) {
				newNode->_color = 0;
				this->_root = newNode;
				this->_len++;
			}
			else {
				if (this->_end->parent)
					this->_end->parent->right = nullptr;
				this->insert_node(this->_root, newNode);
				checkrb_insert(newNode);
			}
			this->repair_tree();
			return (newNode);
		}
		node_ptr	insert(node_ptr hint, const_reference val) {
			(void) hint;
			node_ptr	newNode = new Node<value_type>(val);
			if (this->_root == this->_end)
			{
				newNode->_color = 0;
				this->_root = newNode;
				this->_len++;
			}
			else {
				if (this->_end->parent)
					this->_end->parent->right = nullptr;
				this->insert_node(this->_root, newNode);
				checkrb_insert(newNode);
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
			node_ptr	del_parent = node->parent;
			if (node == this->_root)
				del_parent = node;
			bool	left = this->_compare(node->_data, del_parent->_data);
			if (node->left)
			{
				node_ptr	candidate = node->left;
				while (candidate->right != nullptr)
					candidate = candidate->right;
				del_parent = candidate->parent;
				left = this->_compare(candidate->_data, del_parent->_data);
			}
			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			node_ptr next = this->erase_node(this->_root, node);
			this->_root = next;
			this->checkrb_delete(del_parent, left);
			// std::cout << "erase node" << std::endl;
			this->repair_tree();
			return (next);
		}
		template<typename TP>
		size_type	erase(TP &key) {
			node_ptr target = nullptr;
			size_type	cnt = 0;
			if (this->_end->parent)
				this->_end->parent->right = nullptr;
			while ((target = this->find_node(this->_root, key))) {
				node_ptr	del_parent = target->parent;
				this->_root = this->erase_node(this->_root, key);
				bool left;
				left = this->_compare(target->_data, target->parent->_data);
				this->checkrb_delete(del_parent, left);
				std::cout << "erase key" << std::endl;

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
			std::cout << this->_len<<"debug(" << node->_color << ")[" << node->_data.first << "][" << node->_data.second <<"]";
			if (node->left)
				std::cout << "\tleft" << node->left->_data.first;
			if (node->right)
				std::cout << "\tright" << node->right->_data.first;
			if (node->parent)
				std::cout << "\tparent" << node->parent->_data.first;
			std::cout << std::endl;
			print(node->right);
		}
		void		print_one(node_ptr node) {
			if (!node)
				return ;
			std::cout << this->_len<<"print_one(" << node->_color << ")[" << node->_data.first << "][" << node->_data.second <<"]";
			if (node->left)
				std::cout << "\tleft" << node->left->_data.first;
			if (node->right)
				std::cout << "\tright" << node->right->_data.first;
			if (node->parent)
				std::cout << "\tparent" << node->parent->_data.first;
			std::cout << "@@@@@@@@@@" << std::endl;
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



