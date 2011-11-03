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
#include <iostream>


template<typename Char>
constexpr bool
equal(Char const* a, Char const* b){
	return a[0] == Char('\0') && b[0] == Char('\0') ? true
		 : a[0] == b[0]                             ? equal(a+1, b+1)
		 : false;
}


int
main(){
	static_assert(half::atof("53.132")    == 53.132, "");
	static_assert(half::atof("42")        == 42, "");
	static_assert(half::atof("0.14035")   == 0.14035, "");
	static_assert(half::atof("")          == 0, "");
	static_assert(half::atof(".")         == 0, "");
	static_assert(half::atof("3...14")    == 3, "");
	static_assert(half::atof("    -3.14") == -3.14, "");
	static_assert(half::atof("0.25e2")    == 25, "");
	static_assert(half::atof("24.25E4")   == 242500, "");
	static_assert(half::atof("0.25e2")    == 25, "");
	static_assert(half::atof("0.4e-2")    == 0.004, "");

	static constexpr auto result = half::atof("24.25EE4");
	static_assert(result == 24.25, "");
	static_assert(equal(result.c_str(), "EE4"), "");

	static constexpr auto result2 = half::atof("0.25e-");
	static_assert(result2 == 0.25, "");
	static_assert(equal(result2.c_str(), "e-"), "");

	static constexpr auto result3 = half::atof("0.25e  -");
	static_assert(result3 == 0.25, "");
	// strtod の仕様だと OK
//	static_assert(half::equal(result4.c_str(), "e  -"), "");

	std::cout << atof("0.14e2") << std::endl;
	std::cout << atof("0.14e-2") << std::endl;
	{
	char* result = nullptr;
	char str[] = "0.25e    -";
	strtod(str, &result);
	std::cout << result << std::endl;
	}

	
	return 0;
}
