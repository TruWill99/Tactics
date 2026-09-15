cmake_minimum_required(VERSION 3.16)
project(Tactics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(Tactics main.cpp)

target_include_directories(Tactics PRIVATE src src/math)
target_link_libraries(Tactics PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)
