cmake_minimum_required(VERSION 3.17)
project(big_integer_lib)

set(CMAKE_CXX_STANDARD 17)

add_executable(big_integer_lib tests.cpp big_integer_lib/BigInteger.h big_integer_lib/BigInteger.cpp big_integer_lib/UnsignedBigInteger.h big_integer_lib/UnsignedBigInteger.cpp)