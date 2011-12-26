//
// half-library
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
#include <half/aliases/type_traits.hpp>



int
main(){
	namespace aliases = half::aliases;
	static_assert(std::is_same<aliases::add_const<int>           , int const>{}         , "");
	static_assert(std::is_same<aliases::add_volatile<int>        , int volatile>{}      , "");
	static_assert(std::is_same<aliases::add_cv<int>              , int const volatile>{}, "");
	static_assert(std::is_same<aliases::add_pointer<int>         , int*>{}              , "");
	static_assert(std::is_same<aliases::add_lvalue_reference<int>, int&>{}              , "");
	static_assert(std::is_same<aliases::add_rvalue_reference<int>, int&&>{}             , "");

	static_assert(std::is_same<aliases::remove_cv<int const volatile>, int>{}, "");
	static_assert(std::is_same<aliases::remove_const<int const>      , int>{}, "");
	static_assert(std::is_same<aliases::remove_volatile<int volatile>, int>{}, "");
	static_assert(std::is_same<aliases::remove_pointer<int*>         , int>{}, "");
	static_assert(std::is_same<aliases::remove_reference<int&>       , int>{}, "");

	return 0;
}
