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
#ifndef HALF_CSTDLIB_ATOF_H
#define HALF_CSTDLIB_ATOF_H

#include "../config.hpp"
#include "../ctype.hpp"

namespace half{

namespace atof_detail{

template<typename Char>
constexpr int
ctoi(Char c){
	return Char('0') <= c && c <= Char('9')
		? c - Char('0')
		: Char(-1);
}

template<typename T, typename Char>
struct with_c_str{
	constexpr with_c_str(T value, Char const* str)
		: value(value), str(str){}
	constexpr operator T() const{
		return value;
	}
	constexpr T get() const{
		return value;
	}
	constexpr Char const* c_str() const{
		return str;
	}
private:
	T value;
	Char const* str;
};


template<typename T, typename Char>
constexpr with_c_str<T, Char>
minus(with_c_str<T, Char> const& value){
	return with_c_str<T, Char>(value * -1, value.c_str());
}

template<typename T, typename Char>
constexpr with_c_str<T, Char>
operator *(T t, with_c_str<T, Char> const& value){
	return with_c_str<T, Char>(t * value.get(), value.c_str());
}

template<typename T, typename Char>
constexpr with_c_str<T, Char>
operator /(T t, with_c_str<T, Char> const& value){
	return with_c_str<T, Char>(t / value.get(), value.c_str());
}

template<typename Char>
constexpr Char const*
remove_space(Char const* s){
	return s[0] != Char(' ') ? s
		 : remove_space(s+1);
}

template<typename Char>
constexpr bool
isdigit(Char c){
	return Char('0') <= c && c <= Char('9');
}

template<typename Char, typename Result = with_c_str<int, Char>>
constexpr Result
atoi_impl(Char const* s, int tmp){
	return ctoi(s[0]) == -1 ? Result(tmp, s)
		 : atoi_impl(s + 1, tmp * 10 + ctoi(s[0]));
}

template<typename Char, typename Result = with_c_str<int, Char>>
constexpr Result
atoi_sign(Char const* s){
	return s[0] != Char('-') ? atoi_impl(s, 0)
		 : isdigit(s[1])     ? minus(atoi_impl(s + 1, 0))
		 : Result(0, s);
}

template<typename Char>
constexpr auto
atoi(Char const* s)->decltype(atoi_sign(remove_space(s))){
	return atoi_sign(remove_space(s));
}

template<typename Char>
constexpr bool
equal(Char const* a, Char const* b){
	return a[0] == Char('\0') && b[0] == Char('\0') ? true
		 : a[0] == b[0]                             ? equal(a+1, b+1)
		 : false;
}

constexpr double
pow(double x, unsigned int y){
	return y <= 1 ? x
		 : x * pow(x, y-1);
}

constexpr int
keta(int n, int sum = 0){
	return n <= 0 ? sum
		 : keta(n/10, sum+1);
}

template<typename T, typename Char, typename Result = with_c_str<double, Char>>
constexpr Result
atof_power_impl(with_c_str<T, Char> const& n){
	return n == 0 ? Result(1, n.c_str())
		 : n == 0 ? Result(1, n.c_str())
		 : n >  0 ? Result(pow(10.0, n), n.c_str())
		 : Result(1 / pow(10.0, n*-1), n.c_str());
}

template<typename Char>
constexpr bool
isdigit_plus_minus(Char c){
	return (Char('0') <= c && c <= Char('9'))
		|| c == Char('-')
		|| c == Char('+');
}

template<typename Char, typename Result = with_c_str<double, Char>>
constexpr Result
atof_power(Char const* s){
	return (s[0] == Char('e') || s[0] == Char('E')) && atoi(s+1).c_str() != (s+1)
//	return (s[0] == Char('e') || s[0] == Char('E'))
//	return (s[0] == Char('e') || s[0] == Char('E')) && isdigit_plus_minus(s[1])
		 ? atof_power_impl(atoi(s+1))
		 : Result(1, s);
}

template<typename T, typename Char, typename Result = with_c_str<double, Char>>
constexpr Result
atof_impl(with_c_str<T, Char> const& n, double sum){
	return (n / pow(10.0, keta(n)) + sum) * atof_power(n.c_str());
}

template<typename Char, typename Result = with_c_str<double, Char>>
constexpr Result
atof_dot(Char const* s, int sum){
	return s[0] == Char('.') ? atof_impl(atoi(s+1), sum)
		 : Result(sum, s);
}

template<typename T, typename Char, typename Result = with_c_str<double, Char>>
constexpr Result
atof(with_c_str<T, Char> const& atoi){
	return atoi < 0
		 ? minus(atof_dot(atoi.c_str(), -atoi))
		 : atof_dot(atoi.c_str(),  atoi);
}

template<typename Char>
constexpr auto
atof(Char const* s)->decltype(atof(atoi(s))){
	return atof(atoi(s));
}
}  // namespace atof_detail

template<typename Char>
constexpr auto
atof(Char const* s)->decltype(atof_detail::atof(s)){
	return atof_detail::atof(s);
}

} // namespace half

#endif /* HALF_CSTDLIB_ATOF_H */
