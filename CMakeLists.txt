cmake_minimum_required(VERSION 3.0.0)
project(PA-Project VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
include_directories(PA-Project ${SDL2_INCLUDE_DIRS})


add_executable(PA-Project src/main.cpp src/logic/GameWorld.cpp src/graphics/GraphicsManager.cpp src/logic/Car.cpp src/logic/Car.h src/EventManager.cpp src/EventManager.h src/logic/Trigger.cpp src/logic/Trigger.h src/logic/Timer.cpp src/logic/Timer.h src/logic/Track.cpp src/logic/Track.h src/menu/Menu.cpp src/menu/Menu.h src/audio/AudioManager.cpp src/audio/AudioManager.h)


target_link_libraries(PA-Project ${SDL2_LIBRARIES} SDL2_ttf SDL2_image)

add_subdirectory(lib/glm)
target_link_libraries(PA-Project glm::glm)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
