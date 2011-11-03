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
#ifndef HALF_STRING_H
#define HALF_STRING_H

#include "./config.hpp"
#include "./detail/index_tuple.hpp"

namespace half{

template<typename Char, std::size_t N>
struct c_string{
	Char elems[N ? N : 1];
	HALF_CONSTEXPR Char operator [](std::size_t n){
		return elems[n];
	}
	HALF_CONSTEXPR Char const* c_str() const{
		return &elems[0];
	}
};


template<typename Char, std::size_t N, std::size_t ...Indices>
constexpr c_string<Char, N>
make_c_string_impl(Char const (&str)[N], detail::index_tuple<Indices...>){
	return {{ str[Indices]... }};
}

template<typename Char, std::size_t N>
constexpr c_string<Char, N>
make_c_string(Char const (&str)[N]){
	return make_c_string_impl(str, typename detail::index_range<0, N>::type());
}

template<typename Char, std::size_t N, std::size_t ...Indices>
constexpr c_string<Char, N+1>
push_back_impl(Char const (&str)[N], detail::index_tuple<Indices...>, Char c){
	return {{ str[Indices]..., c, '\0' }};
}

template<typename Char, std::size_t N>
constexpr c_string<Char, N+1>
push_back(Char const (&str)[N], Char c){
	return push_back_impl(str, typename detail::index_range<0, N-1>::type(), c);
}

template<typename Char, std::size_t N>
constexpr c_string<Char, N+1>
push_back(c_string<Char, N> const& str, Char c){
	return push_back(str.elems, c);
}


} // namespace half

#endif /* HALF_STRING_H */
