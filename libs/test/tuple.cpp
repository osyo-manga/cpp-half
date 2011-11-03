//
// kmt-library
//
// Copyright (c) 2011 
// osyo-manga : http://d.hatena.ne.jp/osyo-manga/
// 
// Readme:
// https://github.com/osyo-manga/kmt/blob/master/README
//
// Lihalfnse:
// Boost Software Lihalfnse - Version 1.0
// <http://www.boost.org/LIhalfNSE_1_0.txt>
//
#include <half/tuple.hpp>

int
main(){
	typedef half::tuple<int, float, char, void> seq;
	static_assert(std::is_same<
		half::tuple_element<0, seq>::type,
		int
	>::value, "");
	
	static_assert(std::is_same<
		half::tuple_element<0, decltype(half::make_tuple(0, 2))>::type,
		int
	>::value, "");

	static_assert(half::get<0>(half::make_tuple(1, 2)) == 1, "");
	static_assert(half::get<1>(half::make_tuple(1, 3.14)) == 3.14, "");
	
	constexpr auto str = "hoge";
	static_assert(half::get<2>(half::make_tuple(1, 3.14, str)) == str, "");
	
	static constexpr auto t = half::make_tuple(42, "hoge");
	static_assert(half::get<0>(t) == 42, "");
	
	return 0;
}
