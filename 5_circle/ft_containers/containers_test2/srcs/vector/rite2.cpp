#include "common.hpp"

#define TESTED_TYPE int

// int		main(void)
// {
// 	const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// std::cout << "=======================A" << std::endl;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
// std::cout << "=======================B" << std::endl;

// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

// 	for (int i = 0; i < size; ++i)
// 		it[i] = (size - i) * 5;
// for (int i = 0; i < size; i++)
// 	std::cout << i << "[" << vct._arr[i] << "]" << std::endl;
// 	std::cout << "it[" <<*it << *vct.rbegin() << *(vct.end()- 1) << std::endl;
// 	std::cout << "vctend[" << *(vct.end() - 1) <<"]"<< std::endl;

// 	it = it + 5;
// 	std::cout << "it " <<*it << std::endl;
// 	it = 1 + it;
// 	std::cout << "it " <<*it << std::endl;

// 	it = it - 4;
// 	std::cout << "it " <<*it << std::endl;

// 	std::cout << *(it += 2) << std::endl;
// 	std::cout << *(it -= 1) << std::endl;

// 	*(it -= 2) = 42;
// 	*(it += 2) = 21;

// 	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

// 	std::cout << "(it == const_it): " << (ite == it) << std::endl;
// 	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
// 	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

// 	printSize(vct, true);



// std::cout << "=======================" << std::endl;
// 	std::vector<int> vv(size);
// 	std::vector<int>::reverse_iterator vt = vv.rbegin();
// 	std::vector<int>::const_reverse_iterator vte = vv.rbegin();

// 	for (int i = 0; i < size; ++i)
// 		vt[i] = (size - i) * 5;

// 	std::cout << "vt " <<*vt << *vv.rbegin() << *(vv.end()- 1) << std::endl;
// 	std::cout << *(vv.end() - 1) << std::endl;

// 	vt = vt + 5;
// 	std::cout << "vt " <<*vt << std::endl;

// 	vt = 1 + vt;
// 	std::cout << "vt " <<*vt << std::endl;

// 	vt = vt - 4;
// 	std::cout << "vt " <<*vt << std::endl;
	
// 	std::cout << *(vt += 2) << std::endl;
// 	std::cout << *(vt -= 1) << std::endl;

// 	*(vt -= 2) = 42;
// 	*(vt += 2) = 21;

// 	std::cout << "const_ite +=/-=: " << *(vte += 2) << " | " << *(vte -= 2) << std::endl;

// 	std::cout << "(vt == const_it): " << (vte == vt) << std::endl;
// 	std::cout << "(const_ite - vt): " << (vte - vt) << std::endl;
// 	std::cout << "(vte + 3 == vt): " << (vte + 3 == vt) << std::endl;

// 	return (0);
// }


int main()
{
		const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;
;
	// std::cout << "it " <<*it << std::endl;
	it = it + 5;
	// std::cout << "it " <<*it << std::endl;
	it = 1 + it;
	// std::cout << "it " <<*it << std::endl;

	it = it - 4;
	// std::cout << "it " <<*it << std::endl;

	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printSize(vct, true);
}