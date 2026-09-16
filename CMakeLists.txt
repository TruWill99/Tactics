cmake_minimum_required(VERSION 3.16)
project(Tactics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
