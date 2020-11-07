//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_HTTP_IMPL_ERROR_HPP
#define BOOST_BEAST2_HTTP_IMPL_ERROR_HPP

#include <type_traits>

namespace boost {
namespace system {
template<>
struct is_error_code_enum<
    ::boost::beast2::http::error>
{
    static bool const value = true;
};
} // system
} // boost

namespace boost {
namespace beast2 {
namespace http {

BOOST_BEAST2_DECL
error_code
make_error_code(error ev);

} // http
} // beast2
} // boost

#endif
