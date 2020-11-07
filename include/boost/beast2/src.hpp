//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_SRC_HPP
#define BOOST_BEAST2_SRC_HPP

/*

This file is meant to be included once,
in a translation unit of the program.

*/

#ifndef BOOST_BEAST2_SOURCE
#define BOOST_BEAST2_SOURCE
#endif

// We include this in case someone is using
// src.hpp as their main JSON header file
//#include <boost/beast2.hpp>

//#include <boost/beast2/detail/config.hpp>
#include <boost/beast2/http/impl/basic_parser.ipp>
#include <boost/beast2/http/impl/error.ipp>
#include <boost/beast2/http/impl/request_parser.ipp>

#endif
