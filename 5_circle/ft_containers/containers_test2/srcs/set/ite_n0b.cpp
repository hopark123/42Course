#include "common.hpp"

#define T1 int

int		main(void)
{
	std::set<int> st;

	std::set<int>::iterator ite = st.begin();
	*ite = 42; // < -- error as well ; T is always const, even with regular iterator
	return (0);
}
