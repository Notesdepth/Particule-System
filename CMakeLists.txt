cmake_minimum_required(VERSION 3.15)
project(Particules_System)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall)

include_directories(include)

find_package(SDL2 REQUIRED)
include_directories(/usr/local/include/SDL2)

find_package(OpenCL REQUIRED)
include_directories(${OpenCL_INCLUDE_DIRS})

add_executable(Particules_System src/main.cpp include/particules.h src/Window.cpp src/loop.cpp src/calcCL.cpp)

target_link_libraries(Particules_System ${SDL2_LIBRARIES})
target_link_libraries(Particules_System ${OpenCL_LIBRARY})

