//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_HTTP_IMPL_BASIC_PARSER_IPP
#define BOOST_BEAST2_HTTP_IMPL_BASIC_PARSER_IPP

#include <boost/beast2/http/request_parser.hpp>

namespace boost {
namespace beast2 {

basic_parser::
~basic_parser()
{
    if(data_)
        delete[] data_;
}

basic_parser::
basic_parser() noexcept
    : data_(nullptr)
    , cap_(0)
{
}

bool
basic_parser::
need_more() const noexcept
{
    return true;
}

mutable_buffers
basic_parser::
prepare()
{
    if(! data_)
    {
        data_ = new char[4096];
        cap_ = 4096;
        b_ = { data_, cap_ };
    }

    mutable_buffers b(&b_);
    return b;
}

void
basic_parser::
commit(std::size_t n)
{
    (void)n;
}

} // beast2
} // boost

#endif
