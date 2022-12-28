cmake_minimum_required(VERSION 3.8)

project(AISD_Tests)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)

find_package (Boost COMPONENTS unit_test_framework REQUIRED)

file(GLOB AISD_Tests_src CONFIGURE_DEPENDS "../src/*.h" "../src/*.c" "*.c" "*.h" "*.cpp")

add_executable(AISD_Tests ${AISD_Tests_src})
target_link_libraries(AISD_Tests -lboost_unit_test_framework)

