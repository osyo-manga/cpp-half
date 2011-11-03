//
// kmt-library
//
// Copyright (c) 2011 
// osyo-manga : http://d.hatena.ne.jp/osyo-manga/
// 
// Readme:
// https://github.com/osyo-manga/kmt/blob/master/README
//
// License:
// Boost Software License - Version 1.0
// <http://www.boost.org/LICENSE_1_0.txt>
//
#include <half/cstdlib.hpp>

template<typename Char>
constexpr bool
equal(Char const* a, Char const* b){
	return a[0] == Char('\0') && b[0] == Char('\0') ? true
		 : a[0] == b[0]                             ? equal(a+1, b+1)
		 : false;
}

template<typename Range1, typename Range2>
constexpr bool
equal_range(Range1 a, Range2 b, int n = 0){
	return a[n] == '\0' && b[n] == '\0' ? true
		 : a[n] == b[n]                 ? equal_range(a, b, n+1)
		 : false;
}


#include <type_traits>

int
main(){

	static constexpr auto str = half::itoa(94581048);
	static_assert(equal(str.c_str(), "94581048"), "");
	static constexpr auto str2 = half::itoa(-142);
	static_assert(equal(str2.c_str(), "-142"), "");
	static constexpr auto str3 = half::itoa(-142, half::c_string<char, 10>{{}});
	static_assert(equal(str3.c_str(), "-142"), "");
	static constexpr auto str4 = half::itoa(-142, half::c_string<char, 3>{{}});
	static_assert(equal(str4.c_str(), "-1"), "");
	static constexpr auto str5 = half::itoa(42, half::c_string<char, 3>{{}});
	static_assert(equal(str5.c_str(), "42"), "");
	static constexpr auto str6 = half::itoa(2147483647);
	static_assert(equal(str6.c_str(), "2147483647"), "");
	static constexpr auto str7 = half::itoa(-2147483647);
	static_assert(equal(str7.c_str(), "-2147483647"), "");
	static_assert(std::is_same<
		decltype(half::itoa(10)),
		half::c_string<char, 12>
	>::value, "");

	static_assert(equal_range(half::itoa(42), "42"), "");

	
	return 0;
}
