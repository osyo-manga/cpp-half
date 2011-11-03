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
#ifndef HALF_TUPLE_H
#define HALF_TUPLE_H

#include "./config.hpp"

namespace half{

namespace detail{

template<typename ...Args>
struct tuple_impl;

template<typename T, typename ...Args>
struct tuple_impl<T, Args...> : tuple_impl<Args...>{
	typedef tuple_impl<Args...> base_type;
	constexpr tuple_impl(T t, Args... args) : base_type(args...), value(t){}
	T value;
};

template<>
struct tuple_impl<>{};


template<std::size_t Index, typename ...Args>
struct tuple_element_impl;

template<std::size_t Index, typename T, typename ...Args>
struct tuple_element_impl<Index, T, Args...>
	:  tuple_element_impl<Index - 1, Args...>{};

template<typename T, typename ...Args>
struct tuple_element_impl<0, T, Args...>{
	typedef T type;
};


}  // namespace detail


template<typename ...Args>
struct tuple : detail::tuple_impl<Args...>{
	typedef detail::tuple_impl<Args...> base_type;
	HALF_CONSTEXPR tuple(Args... args) : base_type(args...){}
};

template<std::size_t Index, typename Tuple>
struct tuple_element;

template<std::size_t Index, typename ...Args>
struct tuple_element<Index, tuple<Args...>> : detail::tuple_element_impl<Index, Args...>{};

template<typename ...Args>
HALF_CONSTEXPR tuple<Args...>
make_tuple(Args&&... args){
	return tuple<Args...>(std::forward<Args>(args)...);
}

template<std::size_t Index, typename Tuple>
struct tuple_base_of : tuple_base_of<Index-1, typename Tuple::base_type>{};

template<typename Tuple>
struct tuple_base_of<0, Tuple>{
	typedef typename Tuple::base_type type;
};

template<
	std::size_t Index,
	typename Tuple,
	typename Base = typename tuple_base_of<Index, Tuple>::type
>
inline
HALF_CONSTEXPR typename tuple_element<Index, Tuple>::type
get(Tuple t){
	return static_cast<Base>(t).value;
}

} // namespace half


#endif /* HALF_TUPLE_H */
