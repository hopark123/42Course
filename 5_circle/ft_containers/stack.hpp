#ifndef _STACK_
# define _STACK_
# include "vector.hpp"

namespace ft
{
template <class T, class Container = ft::vector<T> >
class stack
{
	public :
	typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

	private :
		typedef	stack<T, Container>	_Self;
		container_type				_con;
	
	public :
		stack(const container_type &con = container_type()) : _con(con) {}
		stack(const _Self &other) {
			if (*this != other)
				*this = other;
		}
		_Self &operator=(const _Self &other) {
			this->_con = other._con;
		}
		~stack() {}

		bool	empty(void) const {
			return (this->_con.empty());
		}
		size_type	size(void) const {
			return (this->_con.size());
		}
		value_type	&type(void) {
			return (this->_con.back());
		}
		const value_type	&top(void) const {
			return (this->_con.back());
		}
		void	push(const value_type &val) {
			return (this->_con.push_back(val));
		}
		void	pop(void) {
			return (this->_con.pop_back());
		}
	private:
			template <class A, class container>
			friend bool	operator==(const stack<A, container> &lhs, const stack<A, container> &rhs);
			template <class A, class container>
			friend bool	operator!=(const stack<A, container> &lhs, const stack<A, container> &rhs);
			template <class A, class container>
			friend bool	operator<(const stack<A, container> &lhs, const stack<A, container> &rhs);
			template <class A, class container>
			friend bool	operator<=(const stack<A, container> &lhs, const stack<A, container> &rhs);
			template <class A, class container>
			friend bool	operator>(const stack<A, container> &lhs, const stack<A, container> &rhs);
			template <class A, class container>
			friend bool	operator>=(const stack<A, container> &lhs, const stack<A, container> &rhs);
};
template <class T, class Container>
bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (lhs._con == rhs._con);
};
template <class T, class Container>
bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (lhs._con != rhs._con);
};
template <class T, class Container>
bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (lhs._con > rhs._con);
};
template <class T, class Container>
bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (lhs._con < rhs._con);
};
template <class T, class Container>
bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (lhs._con >= rhs._con);
};
template <class T, class Container>
bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
{
	return (lhs._con <= rhs._con);
};
}

#endif