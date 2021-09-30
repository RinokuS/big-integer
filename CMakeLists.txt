cmake_minimum_required(VERSION 3.17)
project(big_integer_lib)

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg

add_executable(big_integer_lib tests.cpp big_integer_lib/BigInteger.h big_integer_lib/BigInteger.cpp big_integer_lib/UnsignedBigInteger.h big_integer_lib/UnsignedBigInteger.cpp big_integer_lib/EquationsParser.h big_integer_lib/EquationsParser.cpp)
target_link_libraries(big_integer_lib gtest_main)
add_test(NAME example_test COMMAND big_integer_lib)