cmake_minimum_required(VERSION 3.10)
project(ref_gen_parser_project)
set(CMAKE_CXX_STANDARD 17)

set(GIT_HASH "unknown")
find_package(Git QUIET)
if(GIT_FOUND)
    execute_process(
            COMMAND ${GIT_EXECUTABLE} rev-parse HEAD
            OUTPUT_VARIABLE GIT_HASH
            OUTPUT_STRIP_TRAILING_WHITESPACE
            ERROR_QUIET
    )
endif()

message(STATUS "Found Git hash: ${GIT_HASH}")

configure_file(
        ${CMAKE_CURRENT_LIST_DIR}/include/version.hpp.in
        ${CMAKE_CURRENT_LIST_DIR}/include/version.hpp
        @ONLY
)

add_library(
        ref_genome_parser
        SHARED
        src/reference_genome_parser.cpp
        include/reference_genome_parser.hpp
        include/version.hpp
)

target_compile_options(
        ref_genome_parser
        PRIVATE
        -Wall
        -Wextra
)

target_link_libraries(ref_genome_parser)

add_executable(ref_gen_main main.cpp)
target_include_directories(ref_gen_main PUBLIC include/reference_genome_parser.hpp)
target_link_libraries(ref_gen_main ref_genome_parser)
