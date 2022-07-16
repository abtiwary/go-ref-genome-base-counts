cmake_minimum_required(VERSION 3.10)
project(ref_gen_parser_project)
set(CMAKE_CXX_STANDARD 17)

add_library(
        ref_genome_parser_wrapper
        SHARED
        ref_genome_parser_wrapper.cpp
        ref_genome_parser_wrapper.h
)

target_compile_options(
        ref_genome_parser_wrapper
        PRIVATE
        -Wall
        -Wextra
)

target_link_libraries(ref_genome_parser_wrapper ref_genome_parser)

add_executable(main main.c)
target_link_libraries(main ref_genome_parser_wrapper ref_genome_parser)
