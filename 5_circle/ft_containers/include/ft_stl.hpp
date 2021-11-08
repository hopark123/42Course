#ifndef _FT_STL_
# define _FT_STL_

namespace ft
{
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
}

#endif