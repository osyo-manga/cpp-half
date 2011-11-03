//
// cpp-half-library
//
// Copyright (c) 2011 
// osyo-manga : http://d.hatena.ne.jp/osyo-manga/
// 
// Readme:
// https://github.com/osyo-manga/cpp-half/blob/master/README
//
// License:
// Boost Software License - Version 1.0
// <http://www.boost.org/LICENSE_1_0.txt>
//
#ifndef HALF_CSTDLIB_ITOA_H
#define HALF_CSTDLIB_ITOA_H

#include <limits>

#include "../config.hpp"
#include "../c_string.hpp"
#include "../detail/index_tuple.hpp"
#include "../ctype.hpp"

namespace half{

namespace detail{

template<typename T>
inline
HALF_CONSTEXPR char
itoc(T n){
	return 0 <= n && n <= 9 ? '0' + n
		: '\0';
}

template<typename Char, std::size_t N, std::size_t ...Indices>
inline
HALF_CONSTEXPR c_string<Char, N>
itoa_push_front_impl(Char const (&str)[N], index_tuple<Indices...>, Char c){
	return {{ c, str[Indices]..., '\0' }};
}

template<typename Char, std::size_t N>
inline
HALF_CONSTEXPR c_string<Char, N>
itoa_push_front(Char const (&str)[N], Char c){
	static_assert(true, "");
	return itoa_push_front_impl(str, typename index_range<0, N-2>::type(), c);
}

template<typename Char, std::size_t N>
inline
HALF_CONSTEXPR c_string<Char, N>
itoa_push_front(c_string<Char, N> const& str, Char c){
	return itoa_push_front(str.elems, c);
}

template<typename T, typename String>
inline
HALF_CONSTEXPR String
itoa_impl(T n, String const& str){
	return n == 0 ? str
		: itoa_impl(n/10, itoa_push_front(str, itoc(n%10)));
}

template<typename T, typename String>
inline
HALF_CONSTEXPR auto
itoa(T n, String const& str)->decltype(itoa_impl(n, str)){
	return n < 0 ? itoa_push_front(itoa_impl(n*-1, str), '-')
		 : itoa_impl(n, str);
}

template<typename T>
inline
HALF_CONSTEXPR c_string<char, std::numeric_limits<T>::digits10+3>
itoa(T n){
	return itoa(n, c_string<char, std::numeric_limits<T>::digits10+3>{{}});
}

}  // namespace detail

template<typename T, typename String>
inline
HALF_CONSTEXPR auto
itoa(T n, String const& str)->decltype(detail::itoa(n, str)){
	return detail::itoa(n, str);
}


template<typename T>
inline
HALF_CONSTEXPR c_string<char, std::numeric_limits<T>::digits10+3>
itoa(T n){
	return itoa(n, c_string<char, std::numeric_limits<T>::digits10+3>{{}});
}

} // namespace half

#endif /* HALF_CSTDLIB_ITOA_H */
