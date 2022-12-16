cmake_minimum_required(VERSION 3.23)
project(mosze_szemester_project_bagira)

set(CMAKE_CXX_STANDARD 17)

# Using include directory
include_directories(include)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 

#Building targets
add_executable(
snowattack-game
main.cpp
include/Game.cpp
include/Option.cpp
include/Page.cpp
include/Character.cpp
)
        
# Link runTests (this is the file name) with what we want to test (all of the currently important .cpp) 
# # and the GTest and pthread library
add_executable(runTests Test.cpp include/Option.cpp include/Page.cpp include/Character.cpp)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
target_compile_features(runTests PRIVATE cxx_std_17)