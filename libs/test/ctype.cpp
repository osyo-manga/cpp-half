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
	static_assert(ce::isdigit('0'), "");
	static_assert(ce::isdigit('9'), "");
	static_assert(ce::isdigit('5'), "");
	static_assert(!ce::isdigit('a'), "");

	static_assert(ce::isupper('V'), "");
	static_assert(!ce::isupper('a'), "");
	static_assert(!ce::isupper('0'), "");
	
	static_assert(ce::strtol("52", 0) == 52, "");
	static_assert(ce::strtol("0377", 0) == 255, "");
	static_assert(ce::strtol("0xff", 0) == 255, "");
	static_assert(ce::strtol("0xFF", 0) == 255, "");

	return 0;
}
