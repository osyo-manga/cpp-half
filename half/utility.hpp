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
#ifndef HALF_UTILITY_H
#define HALF_UTILITY_H

namespace half{


template<typename T>
HALF_CONSTEXPR typename std::add_rvalue_reference<T>::type
forward(typename std::remove_reference<T>::type& x){
	return static_cast<T&&>(x);
};

template<typename T>
void
forward(typename std::remove_reference<T>::type&& x) =delete;

template<typename T>
HALF_CONSTEXPR typename std::add_rvalue_reference<T>::type
declval();


} // namespace half

#endif /* HALF_UTILITY_H */
