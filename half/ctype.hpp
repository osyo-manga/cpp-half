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
#ifndef HALF_CTYPE_H
#define HALF_CTYPE_H

#include "./config.hpp"

namespace half{

template<typename Char>
inline
HALF_CONSTEXPR bool
isdigit(Char c){
	return Char('0') <= c && c <= Char('9');
}

template<typename Char>
inline
HALF_CONSTEXPR bool
isupper(Char c){
	return Char('A') <= c && c <= Char('Z');
}

template<typename Char>
inline
HALF_CONSTEXPR bool
islower(Char c){
	return Char('a') <= c && c <= Char('z');
}

template<typename Char>
inline
HALF_CONSTEXPR int
ctoi(Char c){
	return isdigit(c) ? c - Char('0')
		 : islower(c) ? 10 + (c - Char('a'))
		 : isupper(c) ? 10 + (c - Char('A'))
		 : Char(-1);
}


} // namespace half

#endif /* HALF_CTYPE_H */
