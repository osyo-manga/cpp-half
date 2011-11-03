//
// kmt-library
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
#include <half/cstdlib.hpp>
#include <iostream>

int
main(){
	static_assert(half::strtol("52", 10)  == 52, "");
	static_assert(half::strtol("377", 8)  == 255, "");
	static_assert(half::strtol("1001", 2) == 9, "");
	static_assert(half::strtol("ff", 16)  == 255, "");
	
	static_assert(half::strtol("  +42", 10) ==  42, "");
	static_assert(half::strtol("  -42", 10) == -42, "");

	static_assert(half::strtol("-10hoge", 0) == -10, "");
	static_assert(half::strtol("f3fa", 0)    == 0, "");

	static_assert(half::strtol(L"40", 0)   == 40, "");
	static_assert(half::strtol(L"0xff", 0) == 255, "");

	static_assert(half::strtol("+0xff", 16) == 255, "");

	static_assert(half::strtol("3087663490", 10) == LONG_MAX, "");

	static_assert(half::strtol("1234", 5) == 194, "");
	static_assert(half::strtol("ABCDEF", 0) == 0, "");
	
	// std::strtol が呼ばれる
	char str[] = "42fc";
	char* error = NULL;
	std::cout << half::strtol(str, &error, 10) << std::endl;
	std::cout << error << std::endl;

	return 0;
}
