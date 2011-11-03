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
#include <half/boiled.hpp>
#include <cassert>

constexpr int
ctoi(char c){
	using namespace half::boiled::arg_names;
	using namespace half::boiled::int_values;
	using namespace half::boiled::char_values;
	// constexpr な関数内で boiled を定義してみたり
	typedef decltype(_0c <= arg1 && arg1 <= _9c) isdigit;
	typedef decltype(ac <= arg1 && arg1 <= zc) islower;
	typedef decltype(Ac <= arg1 && arg1 <= Zc) isupper;
	return isdigit()(c) ? c - char('0')
		 : islower()(c) ? 10 + (c - char('a'))
		 : isupper()(c) ? 10 + (c - char('A'))
		 : char(-1);
}


int
main(){
	namespace boiled = half::boiled;
	using namespace boiled::arg_names;
	using namespace boiled::int_values;
	using namespace boiled::char_values;

	// static_assert(half::placeholder<0>()(1, 2) == 1, "");
	// static_assert(half::plus<arg1T, arg2T>()(1, 2) == 3, "");
	// 
	// static_assert(arg1(2, 3) == 2, "");
	// static_assert(half::int_<3>()(2, 1) == 3, "");
	// static_assert((arg1 + arg2)(2, 3) == 5, "");
	// static_assert((arg1 + arg2 + _1i)(3, 2) == 6, "");
	// static_assert((arg1 + arg2 + arg3)(3, 2, 3) == 8, "");
	// 
	// static_assert((arg1 + half::val(2))(3) == 5, "");

	// static_assert((arg1 - arg2)(3, 1) == 2, "");
	// static_assert(half::if_else(arg1, arg2 + arg2, arg2)(true, 1) == 2, "");
	// static_assert(half::if_else(arg1, arg2 + arg2, arg2)(false, 1) == 1, "");
	// 
	// // typedef decltype(_0c <= arg1 && arg1 <= _9c) isdigit;
	// // static_assert(isdigit()('8'), "");
	// // static_assert(!isdigit()('A'), "");
	// 
	// static_assert(ctoi('4') == 4, "");
	// 
	// static_assert(arg1(1, 2) == 1, "");

	// char c = '6';
	// std::cout << ctoi(c) << std::endl;
	// std::cout << (arg1 + _3i)(2, 3) << std::endl;
	// 
	// static_assert(decltype(arg1 + arg2)()(-2, 3) == 1, "");
	// static_assert(decltype(arg1 + _2i)()(-2) == 0, "");
	// static_assert(decltype(arg1 + boiled::val(2))()(-2) == -2, "");
	
	// 基本的には Boost.boiled と同じように Placeholders 等を使用して式を記述する
	static_assert((arg1 + arg2)(2, 4) == 6, "");
	// 値を記述する場合は、val 関数を使用
	static_assert((arg1 + boiled::val(3))(6) == 9, "");

	// if else 文
	static_assert(boiled::if_else(arg1, arg2 + arg2, arg2)(true,  3) == 6, "");
	static_assert(boiled::if_else(arg1, arg2 + arg2, arg2)(false, 3) == 3, "");
	
	// constexpr な値でなければ、実行時に処理される
	int n = 3;
	assert((arg1 + boiled::val(2))(n) == 5);
	
	// 式から型を定義して評価を行う
	typedef decltype(arg1 + arg2) plus;
	static_assert(plus()(2, 6) == 8, "");
	// 実行時にも処理出来る
	int a = 9, b = 2;
	assert(plus()(a, b) == 11);

	// 式を型として定義する場合、値は template で定義する必要がある。
	typedef decltype(arg1 - boiled::int_<4>()) minus;
	static_assert(minus()(6) == 2, "");
	// val 関数の場合は、値が保持されない
	static_assert(decltype(arg1 - boiled::val(4))()(6) == 6, "");

	// '0' ~ '9' や 0 ~ 9 などは予め用意してある
	static_assert(decltype(arg1 + _8i)()(3) == 11, "");

	typedef decltype(_0c <= arg1 && arg1 <= _9c) isdigit;
//	typedef decltype(half::char_<'0'>() <= arg1 && arg1 <= half::char_<'9'>() ) isdigit;
	static_assert(isdigit()('8'), "");
	static_assert(!isdigit()('A'), "");

	return 0;
}
