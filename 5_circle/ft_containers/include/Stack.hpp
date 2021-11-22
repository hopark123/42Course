#ifndef _STACK_
# define _STACK_
# include "vector.hpp"

namespace ft
{
template <class T, class Container = ft::Vector<T> >
class Stack
{
	public :
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private :
		typedef	Stack<T, Container>	_Self;
		container_type				_con;
	
	public :
		Stack(const container_type	&con = container_type()) : _con(con) {}
		Stack(const _Self &other) {
			if (*this != other)
				*this = other;
		}
		_Self	&operator=(const _Self &other) {
			this->_con = other._con;
		}
		~Stack() {}

		bool empty() const {
			return (this->_con.empty());
		}
		size_type	size() const {
			return (this->_con.size());
		}
		value_type	&top() {
			return (this->_con.back());
		}
		const value_type	&top() const {
			return (this->_con.back());
		}
		void	push(const value_type &val) {
			return (this->_con.push_back(val));
		}
		void	pop() {
			return (this->_con.pop_back);
		}


		private:
			template <class A, class Container>
			friend bool	operator==(const Stack<A, Container> &lhs, const Stack<A, Container> &rhs);
			template <class A, class Container>
			friend bool	operator!=(const Stack<A, Container> &lhs, const Stack<A, Container> &rhs);
			template <class A, class Container>
			friend bool	operator<(const Stack<A, Container> &lhs, const Stack<A, Container> &rhs);
			template <class A, class Container>
			friend bool	operator<=(const Stack<A, Container> &lhs, const Stack<A, Container> &rhs);
			template <class A, class Container>
			friend bool	operator>(const Stack<A, Container> &lhs, const Stack<A, Container> &rhs);
			template <class A, class Container>
			friend bool	operator>=(const Stack<A, Container> &lhs, const Stack<A, Container> &rhs);
};
template <class T, class Container>
bool operator==(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (lhs.c == rhs.c);
};
template <class T, class Container>
bool operator!=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (lhs.c != rhs.c);
};
template <class T, class Container>
bool operator>(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (lhs.c > rhs.c);
};
template <class T, class Container>
bool operator<(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (lhs.c < rhs.c);
};
template <class T, class Container>
bool operator>=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (lhs.c >= rhs.c);
};
template <class T, class Container>
bool operator<=(const Stack<T, Container> &lhs, const Stack<T, Container> &rhs)
{
	return (lhs.c <= rhs.c);
};
}

#endif