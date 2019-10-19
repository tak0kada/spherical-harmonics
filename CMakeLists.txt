cmake_minimum_required(VERSION 3.1)
enable_language(CXX)
project(ivanic)

include_directories("/usr/include")

include_directories("${PROJECT_SOURCE_DIR}/spherical-harmonics/sh")
file(GLOB IVANIC_SRC "${PROJECT_SOURCE_DIR}/spherical-harmonics/sh/*.cc")
add_library(ivanic STATIC ${IVANIC_SRC})

add_executable(test main.cpp)
target_link_libraries(test
    ivanic
    )
