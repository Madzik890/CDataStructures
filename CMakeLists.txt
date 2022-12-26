cmake_minimum_required(VERSION 3.8)

project(CExample)

set(CMAKE_C_STANDARD 99)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file(GLOB CExample_src CONFIGURE_DEPENDS "src/*.h" "src/*.c")

include_directories(${PROJECT_SOURCE_DIR}../include)

add_executable(CExample ${CExample_src})
target_link_libraries(CExample Threads::Threads)

