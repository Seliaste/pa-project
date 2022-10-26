cmake_minimum_required(VERSION 3.0.0)
project(PA-Project VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)

include(CTest)
enable_testing()

add_executable(PA-Project src/main.cpp)

target_link_libraries(PA-Project ${SDL2_LIBRARIES})
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
