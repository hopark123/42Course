#ifndef _UTILS_
# define _UTILS_

# include "Iterator_utils.hpp"

namespace ft
{

// Node
template <typename T>
struct Node
{
	T		_data;
	Node	*parent;
	Node	*left;
	Node	*right;

	Node(const T& data = T()) : _data(data), parent(nullptr), left(nullptr), right(nullptr) {}
	Node(const Node &other) : _data(other._data), parent(nullptr), left(nullptr), right(nullptr) {}
};

// enable_if
template <bool, typename T = void>
struct enable_if {};
template <typename T>
struct enable_if<true, T>
{
	typedef T type;
};

// is_intergral
template <typename T>
struct is_integral { static const bool value = false; };
template <>
struct is_integral<bool> { static const bool value = true; };
template <>
struct is_integral<char> { static const bool value = true; };
template <>
struct is_integral<short> { static const bool value = true; };
template <>
struct is_integral<int> { static const bool value = true; };
template <>
struct is_integral<long> { static const bool value = true; };
template <>
struct is_integral<long long> { static const bool value = true; };
template <>
struct is_integral<unsigned char> { static const bool value = true; };
template <>
struct is_integral<unsigned short> { static const bool value = true; };
template <>
struct is_integral<unsigned int> { static const bool value = true; };
template <>
struct is_integral<unsigned long> { static const bool value = true; };
template <>
struct is_integral<unsigned long long> { static const bool value = true; };


// pair
template <typename T1, typename T2>
struct pair {
	typedef T1		first_type;
	typedef T2		second_type;

	T1 first;
	T2 second;

	pair() : first(), second() {}
	pair (T1 const &x, T2 const &y) : first(x), second(y) {}

	pair (pair<T1, T2> const &other) : first(other.first), second(other.second) {}
	template< typename U1, typename U2>
	pair (pair<U1, U2> const &other) : first(other.first), second(other.second) {}

	pair<T1, T2> &operator=(pair<T1, T2> const &other) {
		this->first = other.first;
		this->second = other.second;
		return (*this);
	}
	template< typename U1, typename U2>
	pair<T1, T2> &operator=(pair<U1, U2> const &other) {
		this->first = other.first;
		this->second = other.second;
		return (*this);
	}
	~pair() {}
};
template <typename T1, typename T2>
bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return (lhs.first < rhs.first && lhs.second < rhs.second);
}

template <typename T1, typename T2>
bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return (!(lhs == rhs));
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return (!(lhs > rhs));
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs) {
	return (rhs < lhs);
}

template<typename T1, typename T2>
pair<T1, T2> make_pair(T1 first, T2 second) {
	return (pair<T1, T2>(first, second));
}


// less
template <typename T>
struct less {
	bool operator() (T const &lhs, T const &rhs) const {
		return (lhs < rhs);
	}
};

// swap
template <typename T>
void swap (T &lhs, T &rhs) {
	// std::cout << "swap A" << std::endl;
	T tmp(lhs);
	// std::cout << "swap B" << std::endl;
	lhs = rhs;
	rhs = tmp;

}
//lexicographical_compare

template<class It1, class It2>
bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2)
{
	for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
		if (*first1 < *first2) return true;
		if (*first2 < *first1) return false;
	}
	return (first1 == last1) && (first2 != last2);
}

template<class It1, class It2, class Compare>
bool lexicographical_compare(It1 first1, It1 last1, It2 first2, It2 last2, Compare comp)
{
	for ( ; (first1 != last1) && (first2 != last2); ++first1, ++first2 ) {
		if (comp(*first1,*first2))
			return true;
		if (comp(*first2,*first1))
			return false;
		if (comp._com(first1->second, first2->second))
		{
			// std::cout<<"\n[" << first1->first << first1->second <<"][ " << first2->second << "aa" << std::endl;
			return true;
		}
		if(comp._com(first2->second, first1->second))
		{
			// std::cout << "\nbb" << std::endl;
			return false;
		}
			// std::cout<<"\n[" << first1->first << first1->second <<"][ " << first2->second << "aa" << std::endl;
		
	}
	return ((first1 == last1) && (first2 != last2));
}

// equal
template <typename It1, typename It2>
bool equal(It1 first1, It1 last1, It2 first2)
{
	for (; first1 != last1; ++first1, ++first2)
		if (*first1 != *first2)
			return (false);
	return (true);
}

template <typename T>
bool equal(T x1,T x2)
{
	if (x1 != x2)
		return (false);
	return (true);
}


// distance
template <typename It>
typename IteratorTraits<It>::difference_type distance(It first, It last)
{
	typename IteratorTraits<It>::difference_type dist = 0;
	for (; first != last; ++first)
		dist++;
	return (dist);
}

}

#endif
