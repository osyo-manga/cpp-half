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
#ifndef HALF_ALIASES_TYPE_TRAITS_H
#define HALF_ALIASES_TYPE_TRAITS_H

#include <type_traits>

namespace half{ namespace aliases{

namespace detail{

using std::is_same;

using std::add_const;
using std::add_volatile;
using std::add_cv;
using std::add_pointer;
using std::add_lvalue_reference;
using std::add_rvalue_reference;

using std::remove_cv;
using std::remove_const;
using std::remove_volatile;
using std::remove_pointer;
using std::remove_pointer;
using std::remove_reference;


}  // namespace detail


template<typename T> using add_const             = typename detail::add_const            <T>::type;
template<typename T> using add_volatile          = typename detail::add_volatile         <T>::type;
template<typename T> using add_cv                = typename detail::add_cv               <T>::type;
template<typename T> using add_pointer           = typename detail::add_pointer          <T>::type;
template<typename T> using add_lvalue_reference  = typename detail::add_lvalue_reference <T>::type;
template<typename T> using add_rvalue_reference  = typename detail::add_rvalue_reference <T>::type;

template<typename T> using remove_cv             = typename detail::remove_cv            <T>::type;
template<typename T> using remove_const          = typename detail::remove_const         <T>::type;
template<typename T> using remove_volatile       = typename detail::remove_volatile      <T>::type;
template<typename T> using remove_pointer        = typename detail::remove_pointer       <T>::type;
template<typename T> using remove_pointer        = typename detail::remove_pointer       <T>::type;
template<typename T> using remove_reference      = typename detail::remove_reference     <T>::type;


} }  // namespace half { namespace aliases {

#endif /* HALF_ALIASES_TYPE_TRAITS */
