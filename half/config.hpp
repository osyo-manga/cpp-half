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
#ifndef HALF_CONFIG_H
#define HALF_CONFIG_H

#include <boost/config.hpp>

namespace half{


#ifndef HALF_ENABLE_CONSTEXPR
#	ifndef BOOST_NO_CONSTEXPR
#		ifndef HALF_DISABLE_CONSTEXPR
#			define HALF_ENABLE_CONSTEXPR
#		endif
#	endif
#endif

#ifdef HALF_ENABLE_CONSTEXPR
#	define HALF_CONSTEXPR constexpr
#else
#	define HALF_CONSTEXPR 
#endif


} // namespace half

#endif /* HALF_CONFIG_H */
