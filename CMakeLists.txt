#
# Copyright (c) 2019 Vinnie Falco (vinnie.falco@gmail.com)
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
#
# Official repository: https://github.com/boostorg/json
#

cmake_minimum_required(VERSION 3.5...3.16)

set(BOOST_BEAST2_VERSION 1)
if(BOOST_SUPERPROJECT_VERSION)
    set(BOOST_BEAST2_VERSION ${BOOST_SUPERPROJECT_VERSION})
endif()

project(boost_beast2 VERSION "${BOOST_BEAST2_VERSION}" LANGUAGES CXX)

file(GLOB_RECURSE BOOST_BEAST2_HEADERS $<$<VERSION_GREATER_EQUAL:${CMAKE_VERSION},3.12>:CONFIGURE_DEPENDS>
    include/boost/*.hpp
    include/boost/*.ipp
    include/boost/*.natvis
)

set(BOOST_BEAST2_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/src.cpp
)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/include/boost PREFIX "" FILES ${BOOST_BEAST2_HEADERS})
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src PREFIX "" FILES ${BOOST_BEAST2_SOURCES})

# TODO: For Boost superproject, do we want to support header-only mode?
#       Then, this needs to read `add_library(boost_beast2 INTERFACE)`
#       and related settings need to be INTERFACE-ed as well.
add_library(boost_beast2 ${BOOST_BEAST2_HEADERS} ${BOOST_BEAST2_SOURCES})
add_library(Boost::beast2 ALIAS boost_beast2)

target_compile_features(boost_beast2 PUBLIC cxx_constexpr)

# TODO: For Boost superproject, this may need to be INTERFACE setting.
include(GNUInstallDirs)
if(BOOST_SUPERPROJECT_VERSION)
    target_include_directories(boost_beast2 PUBLIC include)
else()
    target_include_directories(boost_beast2
        PUBLIC
            "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
            "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
    )
endif()

target_compile_definitions(boost_beast2 PUBLIC BOOST_BEAST2_NO_LIB=1)

if(BUILD_SHARED_LIBS)
    target_compile_definitions(boost_beast2 PUBLIC BOOST_BEAST2_DYN_LINK=1)
else()
    target_compile_definitions(boost_beast2 PUBLIC BOOST_BEAST2_STATIC_LINK=1)
endif()

if(BOOST_SUPERPROJECT_VERSION)
    #
    # Building as part of Boost superproject tree, with Boost as dependency.
    #
    target_link_libraries(boost_beast2
        PUBLIC
            Boost::align
            Boost::assert
            Boost::config
            Boost::container
            Boost::exception
            Boost::system
            Boost::throw_exception
            Boost::utility
    )

elseif(BOOST_BEAST2_IN_BOOST_TREE)
    #
    # Building inside Boost tree, out of Boost superproject tree, with Boost as dependency.
    # e.g. on Travis or other CI, or when producing Visual Studio Solution and Projects.
    #
    get_filename_component(BOOST_ROOT ../.. ABSOLUTE)
    target_include_directories(boost_beast2 PUBLIC ${BOOST_ROOT})
    target_link_directories(boost_beast2 PUBLIC ${BOOST_ROOT}/stage/lib)

else()
    #
    # Building out of Boost tree, out of Boost superproject tree, with Boost as dependency.
    # e.g. for packaging or added with add_subdirectory.
    #
    find_package(Boost REQUIRED COMPONENTS container system)
    target_link_libraries(boost_beast2
        PUBLIC
            Boost::container
            Boost::system
    )
endif()

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR AND NOT BOOST_BEAST2_IN_BOOST_TREE)
    set_target_properties(boost_beast2 PROPERTIES EXPORT_NAME beast2)
    install(TARGETS boost_beast2
        EXPORT boost_beast2_targets
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    )

    install(EXPORT boost_beast2_targets
        FILE boost_beast2-targets.cmake
        NAMESPACE Boost::
        DESTINATION lib/cmake/boost_beast2
    )

    include(CMakePackageConfigHelpers)

    configure_package_config_file(cmake/config.cmake.in
        ${CMAKE_CURRENT_BINARY_DIR}/boost_beast2-config.cmake
        INSTALL_DESTINATION lib/cmake/boost_beast2
    )

    write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/boost_beast2-config-version.cmake
        VERSION ${PROJECT_VERSION} COMPATIBILITY SameMajorVersion
    )

    install(FILES
        ${CMAKE_CURRENT_BINARY_DIR}/boost_beast2-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/boost_beast2-config-version.cmake
        DESTINATION lib/cmake/boost_beast2
    )

    install(DIRECTORY include/ DESTINATION include)
endif()

include(CTest)
if(BUILD_TESTING)
    add_subdirectory(test)
endif()

add_subdirectory (example)
