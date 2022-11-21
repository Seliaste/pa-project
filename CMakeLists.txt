cmake_minimum_required(VERSION 3.0.0)
project(PA-Project VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
include_directories(PA-Project ${SDL2_INCLUDE_DIRS})

add_executable(PA-Project src/main.cpp src/GameWorld.cpp src/graphics.cpp src/Car.cpp src/Car.h src/EventManager.cpp src/EventManager.h)


target_link_libraries(PA-Project ${SDL2_LIBRARIES})

add_subdirectory(lib/glm)
target_link_libraries(PA-Project glm::glm)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
