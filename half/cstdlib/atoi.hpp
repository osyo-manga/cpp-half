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
#ifndef HALF_CSTDLIB_ATOI_H
#define HALF_CSTDLIB_ATOI_H

#include "../ctype.hpp"

namespace half{

namespace detail{

template<typename Char>
inline
HALF_CONSTEXPR int
ctoi(Char c){
	return Char('0') <= c && c <= Char('9')
		? c - Char('0')
		: -1;
}

template<typename Char>
inline
HALF_CONSTEXPR Char const*
atoi_remove_space(Char const* s){
	return s[0] != Char(' ') ? s
		 : atoi_remove_space(s+1);
}

template<typename Char>
inline
HALF_CONSTEXPR int
atoi_impl(Char const* s, int sum){
	return ctoi(s[0]) == -1 ? sum
		 : atoi_impl(s + 1, sum * 10 + ctoi(s[0]));
}

template<typename Char>
inline
HALF_CONSTEXPR int
atoi_sign(Char const* s){
	return s[0] == Char('-')
		? -atoi_impl(s + 1, 0)
		:  atoi_impl(s, 0);
}

template<typename Char>
inline
HALF_CONSTEXPR int
atoi(Char const* s){
	return atoi_sign(atoi_remove_space(s));
}

}  // namespace detail

template<typename Char>
inline
HALF_CONSTEXPR int
atoi(Char const* s){
	return detail::atoi(s);
}

} // namespace half

#endif /* HALF_CSTDLIB_ATOI_H */
