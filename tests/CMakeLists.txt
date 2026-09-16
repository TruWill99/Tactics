# tests/CMakeLists.txt
include(FetchContent)

# Pin GoogleTest to a tag rather than tracking a branch, so builds are
# reproducible. Swap the tag to update.
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

# Keep GoogleTest's own install rules out of our project.
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)

# Windows only: use the same runtime library as the parent project.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

add_executable(tests
    vec2_test.cpp
)

target_link_libraries(tests PRIVATE
    tactics_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
