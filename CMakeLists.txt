cmake_minimum_required(VERSION 3.13)
project(autorace)
set(CMAKE_CXX_STANDARD 20)

#add_subdirectory(benchmark)
#include_directories(benchmark/include)

find_package(Boost 1.76.0) # COMPONENTS thread program_options context filesystem regex system)
include_directories(${Boost_INCLUDE_DIR})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#find_package(qhull)
#include_directories(${QHULL_INCLUDE_DIRS})

add_executable(autorace main.cpp app.cpp app.h track.cpp track.h car.cpp car.h hull.cpp hull.h)
#target_link_libraries(autorace ${SDL2_LIBRARIES} Qhull::qhullcpp Qhull::qhull_r)
target_link_libraries(autorace ${SDL2_LIBRARIES})
