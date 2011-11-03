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
#ifndef HALF_DETAIL_INDEX_TUPLE_H
#define HALF_DETAIL_INDEX_TUPLE_H

#include <cstddef>

namespace half{

namespace detail{

template<std::size_t... Indices>
struct index_tuple{};

template<
	std::size_t Start,
	std::size_t Finish,
	std::size_t Step = 1,
	typename Acc = index_tuple<>,
	bool Break = (Start >= Finish)
>
struct index_range{
	typedef Acc type;
};

template<
	std::size_t Start, std::size_t Finish, std::size_t Step,
	std::size_t... Indices
>
struct index_range<Start, Finish, Step, index_tuple<Indices...>, false>
	: index_range<Start + Step, Finish, Step, index_tuple<Indices..., Start>>
{};

}  // namespace detail

} // namespace half

#endif /* HALF_DETAIL_INDEX_TUPLE_H */
