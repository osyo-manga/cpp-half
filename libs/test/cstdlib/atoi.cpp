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


int
main(){
	static_assert(ce::atoi("4331")   == 4331 , "");
	static_assert(ce::atoi("10")     == 10   , "");
	static_assert(ce::atoi("-742")   == -742 , "");
	static_assert(ce::atoi("")       == 0    , "");
	static_assert(ce::atoi("aba")    == 0    , "");
	static_assert(ce::atoi("52ag53") == 52   , "");
	static_assert(ce::atoi("  -42")  == -42  , "");

	return 0;
}
