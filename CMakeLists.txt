cmake_minimum_required(VERSION 3.15)

project(fibonacci CXX)

find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)
find_package(Boost REQUIRED COMPONENTS regex system)

include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)

add_executable(fibo main.cxx)

target_link_libraries(fibo
  PRIVATE
    fmt::fmt
    range-v3::range-v3
    cxxopts::cxxopts
    ${Boost_LIBRARIES})