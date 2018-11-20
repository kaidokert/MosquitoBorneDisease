cmake_minimum_required(VERSION 3.6)
project(mbd)

# ensure C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#export compiler flags for code completion engines
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})

# Set global compiler warnings
if(MSVC)
    add_compile_options(/W3 /WX)
else()
    add_compile_options(-Wall -pedantic)
endif()

set (mbd_headers
     src/agent.hpp
     src/location.hpp
     src/mosquito.hpp
     src/nonparasite.hpp
     src/simulation.hpp
     src/world.hpp
     )


set (mbd_source
     src/agent.cpp
     src/location.cpp
     src/nonparasite.cpp
     src/simulation.cpp
     src/world.cpp
     )

add_library (mbd
             ${mbd_source}
             ${mbd_headers}
             )

target_include_directories (mbd PUBLIC
                            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
                            $<INSTALL_INTERFACE:include>)


target_compile_definitions (mbd PRIVATE MBD_SOURCE_DIR="${mbd_SOURCE_DIR}" MBD_INSTALL_DIR="${CMAKE_INSTALL_PREFIX}")

enable_testing ()

# todo: remove this option when travis standard libraries all know about std::uncaught_exceptions
option(TURN_OFF_CATCH_CPP17_UNCAUGHT_EXCEPTIONS "Some travis builds do not have std::uncaught_exceptions" OFF)
if (TURN_OFF_CATCH_CPP17_UNCAUGHT_EXCEPTIONS)
    add_definitions(-DCATCH_CONFIG_NO_CPP17_UNCAUGHT_EXCEPTIONS)
endif ()

add_executable (
        mbd_test
        tests/MbdTests.cpp
)

target_include_directories (mbd_test PRIVATE tests)
target_link_libraries (mbd_test PRIVATE mbd)
add_test (the_mbd_tests mbd_test)

add_executable (
        mbd_main
        src/main.cpp
)

target_include_directories (mbd_main PRIVATE src)
target_link_libraries (mbd_main PRIVATE mbd)

# Clang tidy as optional static analyzer
option(MBD_USE_CLANG_TIDY "Use clang tidy for static analysis" OFF)
if (MBD_USE_CLANG_TIDY)
    find_program(CLANG_TIDY_EXE NAMES "clang-tidy" "clang-tidy-6.0" "clang-tidy-5.0" "clang-tidy-4.0"
                 DOC "Path to clang-tidy executable")
    if(NOT CLANG_TIDY_EXE)
        message(STATUS "clang-tidy not found.")
    else()
        message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
        set_target_properties(mbd PROPERTIES CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
    endif()
endif()

# LLVM AddressSanitizer to detecting memory errors
# Note that there are many other sanitizers in LLVM to help detect errors, see
# http://travistoptips.blogspot.co.uk/2015/11/sanitize-all-things.html
option(MBD_MEMCHECK "Use LLVM AddressSanitizer to detecting memory errors" OFF)
if (MBD_MEMCHECK)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(STATUS "Configuring with LLVM AddressSanitizer")
        set(MBD_MEMCHECK_FLAGS -fno-optimize-sibling-calls
            -fsanitize=address
            -fsanitize-address-use-after-scope
            )
        target_compile_options(mbd PUBLIC -O1 -g -fno-omit-frame-pointer ${MBD_MEMCHECK_FLAGS})
        target_link_libraries(mbd PUBLIC -g ${MBD_MEMCHECK_FLAGS})
    else()
        message(FATAL_ERROR "clang compiler required with MBD_MEMCHECK: found ${CMAKE_CXX_COMPILER_ID}")
    endif()
endif()

# Setup coverage testing for GCC or Clang
option(MBD_ENABLE_COVERAGE "Enable coverage reporting for GCC or Clang" FALSE)
if (MBD_ENABLE_COVERAGE)
    if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
        message(STATUS "Configuring with coverage")
        target_compile_options(mbd PUBLIC --coverage -O0)
        target_link_libraries(mbd PUBLIC --coverage)
    else()
        message(FATAL_ERROR "GCC or Clang required with MBD_ENABLE_COVERAGE: found ${CMAKE_CXX_COMPILER_ID}")
    endif()
endif()