cmake_minimum_required(VERSION 3.30)
project(AsteroidsCopy)

set(CMAKE_CXX_STANDARD 20)

#Download Raylib
include(FetchContent)
FetchContent_Declare(raylib GIT_REPOSITORY "https://github.com/raysan5/raylib.git")
FetchContent_MakeAvailable(raylib)

add_executable(AsteroidsCopy main.cpp)
target_link_libraries(${PROJECT_NAME} raylib)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR})
