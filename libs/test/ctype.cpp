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
#include <half/ctype.hpp>


int
main(){
	static_assert(half::isdigit('0'), "");
	static_assert(half::isdigit('9'), "");
	static_assert(half::isdigit('5'), "");
	static_assert(!half::isdigit('a'), "");

	static_assert(half::isupper('V'), "");
	static_assert(!half::isupper('a'), "");
	static_assert(!half::isupper('0'), "");

	return 0;
}
