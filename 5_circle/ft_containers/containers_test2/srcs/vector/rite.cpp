#include "common.hpp"

#define TESTED_TYPE int

// int		main(void)
// {
// 	const int size = 5;
// 	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);
// 	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator kt(it);


// 	for (int i = 0; i < size; ++i)
// 		vct[i] = (i + 1) * 5;
// 	for (int i = 0; i < size; i++)
// 		std::cout << i << "[" << vct._arr[i] << "]" << std::endl;
// 	printSize(vct);
// 	std::cout << "*it_[" << *it_ << "] it*[" << *(it) << "] it.base()[" << *(it.base()) <<"]" << *kt << std::endl;

// 	std::cout << (it_ == it.base()) << std::endl;
// 	std::cout << (it_ == (it + 3).base()) << std::endl;

// 	std::cout << *(it.base() + 1) << std::endl;
// 	std::cout << *(it) << std::endl;
// 	std::cout << *(it - 3).base() << std::endl;
// 	it -= 3;
// 	std::cout << *it.base() << std::endl;

// 	std::cout << "TEST OFFSET" << std::endl;
// 	std::cout << *(it) << std::endl;
// 	std::cout << *(it).base() << std::endl;
// 	std::cout << *(it - 0) << std::endl;
// 	std::cout << *(it - 0).base() << std::endl;
// 	std::cout << *(it - 1).base() << std::endl;




// 	std::cout << "=====================================================" << std::endl;

// 	std::vector<int> vvt(size);
// 	std::vector<int>::iterator vt_ = vvt.begin();
// 	std::vector<int>::reverse_iterator vt(vt_);

// 	std::vector<int>::reverse_iterator kkt(vt);


// 	for (int i = 0; i < size; ++i)
// 		vvt[i] = (i + 1) * 5;
// 	printSize(vct);
// 	std::cout << "*vt_[" << *vt_ << "] vt*[" << *(vt) << "] vt.base()[" << *(vt.base()) << "]" << *kkt<< std::endl;

// 	std::cout << (vt_ == vt.base()) << std::endl;
// 	std::cout << (vt_ == (vt + 3).base()) << std::endl;

// 	std::cout << *(vt.base() + 1) << std::endl;
// 	std::cout << *(vt) << std::endl;
// 	std::cout << *(vt - 3).base() << std::endl;
// 	vt -= 3;
// 	std::cout << *vt.base() << std::endl;

// 	std::cout << "TEST OFFSET" << std::endl;

// 	std::cout << *(vt) << std::endl;
// 	std::cout << *(vt).base() << std::endl;
// 	std::cout << *(vt - 0) << std::endl;
// 	std::cout << *(vt - 0).base() << std::endl;
// 	std::cout << *(vt - 1).base() << std::endl;

// 	return (0);
// }


int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::iterator it_ = vct.begin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it(it_);

	for (int i = 0; i < size; ++i)
		vct[i] = (i + 1) * 5;
	printSize(vct);

	std::cout << (it_ == it.base()) << std::endl;
	std::cout << (it_ == (it + 3).base()) << std::endl;

	std::cout << *(it.base() + 1) << std::endl;
	std::cout << *(it - 3) << std::endl;
	std::cout << *(it - 3).base() << std::endl;
	it -= 3;
	std::cout << *it.base() << std::endl;

	std::cout << "TEST OFFSET" << std::endl;
	std::cout << *(it) << std::endl;
	std::cout << *(it).base() << std::endl;
	std::cout << *(it - 0) << std::endl;
	std::cout << *(it - 0).base() << std::endl;
	std::cout << *(it - 1).base() << std::endl;

	return (0);
}