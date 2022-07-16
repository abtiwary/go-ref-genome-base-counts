#!/bin/bash

rm *.so
rm *.h
cd .. && rm -rf build && mkdir build && cd build
cmake .. && make
cd ../go_ref_gen_parser
cp ../build/ref_genome_parser/libref_genome_parser.so .
cp ../build/ref_genome_parser_wrapper/libref_genome_parser_wrapper.so .
cp ../ref_genome_parser_wrapper/ref_genome_parser_wrapper.h .
export LD_LIBRARY_PATH=`pwd`

