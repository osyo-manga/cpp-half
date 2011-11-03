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
#ifndef HALF_BOILED_H
#define HALF_BOILED_H

#include "./config.hpp"
#include <tuple>


namespace half{

namespace boiled{

template<std::size_t N>
struct placeholder{
	template<typename ...Args>
	constexpr typename std::tuple_element<N, std::tuple<Args...>>::type
	operator ()(Args... args){
		return std::get<N>(std::make_tuple(args...));
	}
};

namespace arg_names{
	typedef placeholder<0> arg1T;
	typedef placeholder<1> arg2T;
	typedef placeholder<2> arg3T;
	typedef placeholder<3> arg4T;
	typedef placeholder<4> arg5T;

	constexpr placeholder<0> arg1{};
	constexpr placeholder<1> arg2{};
	constexpr placeholder<2> arg3{};
	constexpr placeholder<3> arg4{};
	constexpr placeholder<4> arg5{};
}  // namespace arg_names


template<typename T, T Value>
struct integral_constant{
	template<typename ...Args>
	constexpr T operator ()(Args...) const{
		return Value;
	}
};

template<int N>
struct int_ : integral_constant<int, N>{};

namespace int_values{
	constexpr int_<0> _0i{};
	constexpr int_<1> _1i{};
	constexpr int_<2> _2i{};
	constexpr int_<3> _3i{};
	constexpr int_<4> _4i{};
	constexpr int_<5> _5i{};
	constexpr int_<6> _6i{};
	constexpr int_<7> _7i{};
	constexpr int_<8> _8i{};
	constexpr int_<9> _9i{};

}  // namespace int_values

template<char C>
struct char_ : integral_constant<char, C>{};

namespace char_values{
	constexpr char_<'0'> _0c{};
	constexpr char_<'1'> _1c{};
	constexpr char_<'2'> _2c{};
	constexpr char_<'3'> _3c{};
	constexpr char_<'4'> _4c{};
	constexpr char_<'5'> _5c{};
	constexpr char_<'6'> _6c{};
	constexpr char_<'7'> _7c{};
	constexpr char_<'8'> _8c{};
	constexpr char_<'9'> _9c{};
	
	constexpr char_<'a'> ac{};
	constexpr char_<'b'> bc{};
	constexpr char_<'c'> cc{};
	constexpr char_<'d'> dc{};
	constexpr char_<'e'> ec{};
	constexpr char_<'f'> fc{};
	constexpr char_<'g'> gc{};
	constexpr char_<'h'> hc{};
	constexpr char_<'i'> ic{};
	constexpr char_<'j'> jc{};
	constexpr char_<'k'> kc{};
	constexpr char_<'l'> lc{};
	constexpr char_<'m'> mc{};
	constexpr char_<'n'> nc{};
	constexpr char_<'o'> oc{};
	constexpr char_<'p'> pc{};
	constexpr char_<'q'> qc{};
	constexpr char_<'r'> rc{};
	constexpr char_<'s'> sc{};
	constexpr char_<'t'> tc{};
	constexpr char_<'u'> uc{};
	constexpr char_<'v'> vc{};
	constexpr char_<'w'> wc{};
	constexpr char_<'x'> xc{};
	constexpr char_<'y'> yc{};
	constexpr char_<'z'> zc{};

	constexpr char_<'A'> Ac{};
	constexpr char_<'B'> Bc{};
	constexpr char_<'C'> Cc{};
	constexpr char_<'D'> Dc{};
	constexpr char_<'E'> Ec{};
	constexpr char_<'F'> Fc{};
	constexpr char_<'G'> Gc{};
	constexpr char_<'H'> Hc{};
	constexpr char_<'I'> Ic{};
	constexpr char_<'J'> Jc{};
	constexpr char_<'K'> Kc{};
	constexpr char_<'L'> Lc{};
	constexpr char_<'M'> Mc{};
	constexpr char_<'N'> Nc{};
	constexpr char_<'O'> Oc{};
	constexpr char_<'P'> Pc{};
	constexpr char_<'Q'> Qc{};
	constexpr char_<'R'> Rc{};
	constexpr char_<'S'> Sc{};
	constexpr char_<'T'> Tc{};
	constexpr char_<'U'> Uc{};
	constexpr char_<'V'> Vc{};
	constexpr char_<'W'> Wc{};
	constexpr char_<'X'> Xc{};
	constexpr char_<'Y'> Yc{};
	constexpr char_<'Z'> Zc{};

};

// template<typename T>
// struct val{
// 	template<typename ...args>
// 	constexpr typename T::value_type operator ()(args...) const{
// 		return T::value;
// 	}
// };

template<typename T>
struct val_impl{
	template<typename ...args>
	constexpr T operator ()(args...) const{
		return value;
	}
	T value;
};

template<typename T>
constexpr val_impl<T>
val(T t){
	return {{ t }};
}

template<typename T0, typename T1>
struct plus{
	template<typename ...Args>
	constexpr auto
	operator ()(Args... args)->decltype(T0()(args...) + T1()(args...)) const{
		return t0(args...) + t1(args...);
	}
	T0 t0;
	T1 t1;
};

template<typename T0, typename T1>
constexpr plus<T0, T1>
operator +(T0 t0, T1 t1){
	return { t0, t1 };
}

template<typename T0, typename T1>
struct minus{
	template<typename ...Args>
	constexpr auto
	operator ()(Args... args)->decltype(T0()(args...) - T1()(args...)) const{
		return t0(args...) - t1(args...);
	}
	T0 t0;
	T1 t1;
};

template<typename T0, typename T1>
constexpr minus<T0, T1>
operator -(T0 t0, T1 t1){
	return { t0, t1 };
}

template<typename T0, typename T1>
struct multiple{
	template<typename ...Args>
	constexpr auto
	operator ()(Args... args)->decltype(T0()(args...) - T1()(args...)) const{
		return t0(args...) * t1(args...);
	}
	T0 t0;
	T1 t1;
};

template<typename T0, typename T1>
constexpr multiple<T0, T1>
operator *(T0 t0, T1 t1){
	return { t0, t1 };
}

template<typename T0, typename T1>
struct division{
	template<typename ...Args>
	constexpr auto
	operator ()(Args... args)->decltype(T0()(args...) - T1()(args...)) const{
		return t0(args...) / t1(args...);
	}
	T0 t0;
	T1 t1;
};

template<typename T0, typename T1>
constexpr division<T0, T1>
operator /(T0 t0, T1 t1){
	return { t0, t1 };
}

template<typename T0, typename T1>
struct less_equal{
	template<typename ...Args>
	constexpr bool
	operator ()(Args... args) const{
		return t0(args...) <= t1(args...);
	}
	T0 t0;
	T1 t1;
};

template<typename T0, typename T1>
constexpr less_equal<T0, T1>
operator <=(T0 t0, T1 t1){
	return { t0, t1 };
}

template<typename T0, typename T1>
struct and_{
	template<typename ...Args>
	constexpr bool
	operator ()(Args... args) const{
		return t0(args...) && t1(args...);
	}
	T0 t0;
	T1 t1;
};

template<typename T0, typename T1>
constexpr and_<T0, T1>
operator &&(T0 t0, T1 t1){
	return { t0, t1 };
}

template<typename Cond, typename Then, typename Else>
struct if_else_impl{
	template<typename ...Args>
	constexpr auto
	operator ()(Args... args)->decltype(Then()(args...)) const{
		return cond(args...) ? then(args...) :	else_(args...);
	}
	Cond cond;
	Then then;
	Else else_;
};

template<typename Cond, typename Then, typename Else>
constexpr if_else_impl<Cond, Then, Else>
if_else(Cond cond, Then then, Else else_){
	return { cond, then, else_ };
}

}  // namespace boiled

} // namespace half

#endif /* HALF_BOILED_H */
