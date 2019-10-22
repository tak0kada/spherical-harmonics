cmake_minimum_required(VERSION 3.10)
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_STANDARD_REQUIRED ON) # force to use added c++ flag -std=c++17
set(CMAKE_CXX_EXTENSIONS OFF) # do not use compiler extensions like gnu++17
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

project(ivanic)

include_directories("/usr/include")

include_directories("${PROJECT_SOURCE_DIR}/sh")
file(GLOB IVANIC_SRC "${PROJECT_SOURCE_DIR}/sh/*.cc")
list(FILTER IVANIC_SRC EXCLUDE REGEX "${PROJECT_SOURCE_DIR}/sh/.*test.cc")
add_library(ivanic STATIC ${IVANIC_SRC})

add_executable(main main.cpp)
target_link_libraries(main
    ivanic
    )
