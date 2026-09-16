# src/CMakeLists.txt
add_library(tactics_lib INTERFACE)

target_include_directories(tactics_lib INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(tactics_lib INTERFACE
    SFML::Graphics
    SFML::Window
    SFML::System
    SFML::Audio
)

add_executable(Tactics main.cpp)
target_link_libraries(Tactics PRIVATE tactics_lib)
