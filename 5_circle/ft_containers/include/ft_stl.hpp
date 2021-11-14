#ifndef _FT_STL_
# define _FT_STL_

namespace ft
{
template <typename T>
struct Node
{
	T		_data;
	Node*			parent;
	Node*			left;
	Node*			right;

	Node(const T& data = T()) : _data(data), parent(nullptr), left(nullptr), right(nullptr) {}
	Node(const Node &other) : _data(other._data), parent(nullptr), left(nullptr), right(nullptr) {}
};

//enable_if
template <bool, typename T = void>
struct enable_if {};

template <typename T>
struct enable_if<true, T> {
typedef T type;

};

//is_integral
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


//Pair
template < typename T1, typename T2 >
struct Pair {
	typedef T1		first_type;
	typedef T2		second_type;

	T1	first;
	T2	second;

	Pair() : first(), second() {}
	Pair (T1 const &x, T2 const &y) : first(x), second(y) {}

	template< typename U1, typename U2 >
	Pair (Pair<U1, U2> const &other) : first(other.first), second(other.second) {}
	Pair (Pair<T1, T2> const &other) : first(other.first), second(other.second) {}

	template< typename U1, typename U2 >
	Pair<T1, T2> &operator=(Pair<U1, U2> const &other) {
		this->first = other.first;
		this->second = other.second;
		return (*this);
	}
	Pair<T1, T2> &operator=(Pair<T1, T2> const &other) {
		this->first = other.first;
		this->second = other.second;
		return (*this);
	}
	~Pair() {}
};
template<typename T1, typename T2>
Pair<T1, T2> make_pair(T1 first, T2 second) {
	return (Pair<T1, T2>(first, second));
}

template <typename T>
struct less {
	bool operator() (T const &lhs, T const &rhs) const {
		return (lhs < rhs);
	}
};

//swap
template <typename T>
void swap (T &lhs, T &rhs) {
	T tmp(lhs);
	lhs = rhs;
	rhs = tmp;
}
}

#endif