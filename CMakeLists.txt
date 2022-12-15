cmake_minimum_required(VERSION 3.23)
project(mosze_szemester_project_bagira)

# Fetch Gtest
# see: https://google.github.io/googletest/quickstart-cmake.html
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


set(CMAKE_CXX_STANDARD 17)

# Using include directory
include_directories(include)

#Building targets
add_executable(
a.out
main.cpp
include/Game.cpp
include/Option.cpp
include/Page.cpp)

#Testing

include(GoogleTest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()

add_executable(test_snowattack Test.cpp)
target_link_libraries(test_snowattack ${GTEST_LIBRARIES} pthread)
add_test(story_snowattack test_snowattack)
