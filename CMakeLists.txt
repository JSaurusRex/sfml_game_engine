cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
project(sfml_platformer VERSION 0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED)

add_executable(sfml_platformer
    src/main.cpp
    src/player/player.cpp
    src/entityController/entitycontroller.cpp
    src/physics/physicsobject.cpp
    src/physics/physicsWorld.cpp
    src/entities/wall.cpp
    src/levelLoader/levelLoader.cpp
    )
# target_include_directories()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(submodules/json)

target_link_directories( ${PROJECT_NAME}
    PRIVATE submodules/json
)

target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)

target_link_libraries(sfml_platformer sfml-graphics)

file(COPY Data DESTINATION ${CMAKE_BINARY_DIR})
