cmake_minimum_required(VERSION 3.5)
project(onko)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(onko 
src/main.cpp
src/calculations.cpp
src/helper.cpp
src/map.cpp
src/player.cpp
src/rays.cpp
src/light.cpp
src/particle.cpp
src/math.cpp
src/background.cpp
src/text.cpp
src/entity.cpp
src/trigger.cpp
)

add_executable(onkoEditor
src/editor.cpp
)

target_link_libraries(onko X11 pthread)
target_link_libraries(onkoEditor X11 pthread)

include_directories(include)
include_directories(include/dsl)