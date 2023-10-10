cmake_minimum_required(VERSION 3.14)
project(FactorialTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}-gt factorial_test.cpp)
target_link_libraries(${PROJECT_NAME}-gt gtest_main)

enable_testing()
add_test(NAME factorial_test COMMAND ${PROJECT_NAME}-gt)