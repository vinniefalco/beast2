//
// Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/vinniefalco/beast2
//

#ifndef BOOST_BEAST2_BUFFERS_HPP
#define BOOST_BEAST2_BUFFERS_HPP

#include <boost/beast2/detail/config.hpp>
#include <boost/beast2/buffer.hpp>
#include <type_traits>

namespace boost {
namespace beast2 {

template<bool IsMutable>
class buffers
{
public:
    using value_type = typename
        std::conditional<IsMutable,
            mutable_buffer,
            const_buffer>::type;

    using iterator = value_type const*;

    explicit
    buffers(
        value_type const* p) noexcept
        : begin_(p)
        , end_(p + 1)
    {
    }

    iterator
    begin() const noexcept
    {
        return begin_;
    }

    iterator
    end() const noexcept
    {
        return end_;
    }

private:
    iterator begin_;
    iterator end_;
};

using const_buffers = buffers<false>;
using mutable_buffers = buffers<true>;

} // beast2
} // boost

#endif
