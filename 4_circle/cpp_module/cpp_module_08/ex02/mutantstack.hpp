#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template<typename T>
class MutantStack: public std::stack<T>
{
public:
	MutantStack();
	MutantStack(MutantStack<T> const &other);
	virtual ~MutantStack();

	typedef typename std::stack<T>::container_type::iterator	iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	MutantStack<T> &operator=(const MutantStack<T>	&other);

	iterator	begin(void);
	const_iterator	begin(void) const;
	reverse_iterator	rbegin(void);
	const_reverse_iterator	rbegin(void) const;
	iterator	end(void);
	const_iterator	end(void) const;
	reverse_iterator	rend(void);
	const_reverse_iterator	rend(void) const;
};

#include "mutantstack.cpp"

#endif