cmake_minimum_required(VERSION 3.8)

project(AISD_Tests)

set(CMAKE_C_STANDARD 99)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB AISD_Tests_src CONFIGURE_DEPENDS "../src/*.h" "../src/*.c" "*.c" "*.h")

include_directories(${PROJECT_SOURCE_DIR}../include)

add_executable(AISD_Tests ${AISD_Tests_src})
target_link_libraries(AISD_Tests Threads::Threads)

