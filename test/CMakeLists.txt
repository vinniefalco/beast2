#
# Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# Official repository: https://github.com/vinniefalco/beast2
#

set(TFILES
    include/main.cpp
    include/test_suite.hpp
    )

set(PFILES
    CMakeLists.txt
    error.cpp
    string_view.cpp
    )

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} PREFIX "" FILES ${PFILES})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include PREFIX "include" FILES ${TFILES})
add_executable(boost-beast2-tests ${PFILES} ${TFILES})
target_include_directories(boost-beast2-tests PRIVATE . ./include)
target_link_libraries(boost-beast2-tests PRIVATE Boost::beast2)

add_subdirectory(http)
