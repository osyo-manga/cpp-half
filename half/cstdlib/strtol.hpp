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
#ifndef HALF_CSTDLIB_STRTOL_H
#define HALF_CSTDLIB_STRTOL_H

#include "../config.hpp"
#include "../ctype.hpp"
#include <cstdlib>

namespace half{

namespace detail{

template<typename Char>
inline
HALF_CONSTEXPR long
strtol_impl(Char const* s, long radix, long sign, long tmp){
	return ctoi(s[0]) == -1 || ctoi(s[0]) >= radix
			? tmp
		: tmp > (LONG_MAX - ctoi(s[0]) - sign) / radix
			? (sign ? LONG_MIN : LONG_MAX)
		: s[1] == Char('\0')
			? tmp * radix + ctoi(s[0])
		: strtol_impl(s + 1, radix, sign, tmp * radix + ctoi(s[0]));
}

template<typename Char>
inline
HALF_CONSTEXPR long
strtol_prefix(Char const* s, long radix, long sign){
	return s[0] != Char('0') ? strtol_impl(s, radix == 0 ? 10 : radix, sign, 0)
		 : s[1] == Char('x') || s[1] == Char('X')
		 		? strtol_impl(s + 2, radix == 0 ? 16 : radix, sign, 0)
		 : strtol_impl(s + 1, radix == 0 ? 8 : radix, sign, 0);
}

template<typename Char>
inline
HALF_CONSTEXPR long
strtol_sign(Char const* s, long radix){
	return s[0] == Char('-') ? -strtol_prefix(s+1, radix, 1)
		 : s[0] == Char('+') ?  strtol_prefix(s+1, radix, 0)
		 : strtol_prefix(s, radix, 0);
}

template<typename Char>
inline
HALF_CONSTEXPR long
strtol_removespace(Char const* s, long radix){
	return s[0] == Char(' ') ? strtol_removespace(s+1, radix)
		 : strtol_sign(s, radix);
}

template<typename Char>
inline
HALF_CONSTEXPR long
strtol(Char const* s, long radix){
	return strtol_removespace(s, radix);
}

template<typename Char>
inline
HALF_CONSTEXPR long
strtol(Char const* s, Char** endptr, long radix){
	return endptr == NULL
		? strtol(s, radix)
		: std::strtol(s, endptr, radix);
}

}  // namespace detail


template<typename Char>
inline
HALF_CONSTEXPR long
strtol(Char const* s, long radix){
	return detail::strtol(s, radix);
}

template<typename Char>
inline
HALF_CONSTEXPR long
strtol(Char const* s, Char** endptr, long radix){
	return detail::strtol(s, endptr, radix);
}



} // namespace half

#endif /* HALF_CSTDLIB_STRTOL_H */
